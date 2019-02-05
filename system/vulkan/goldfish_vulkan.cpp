// Copyright (C) 2018 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <hardware/hwvulkan.h>

#include <log/log.h>

#include <errno.h>
#include <string.h>

#include "HostConnection.h"
#include "ResourceTracker.h"
#include "VkEncoder.h"

#include "func_table.h"

#include <array>
#include <bitset>
#include <mutex>

// Used when there is no Vulkan support on the host.
// Copied from frameworks/native/vulkan/libvulkan/stubhal.cpp
namespace vkstubhal {

const size_t kMaxInstances = 32;
static std::mutex g_instance_mutex;
static std::bitset<kMaxInstances> g_instance_used(false);
static std::array<hwvulkan_dispatch_t, kMaxInstances> g_instances;

[[noreturn]] VKAPI_ATTR void NoOp() {
    LOG_ALWAYS_FATAL("invalid stub function called");
}

VkResult
EnumerateInstanceExtensionProperties(const char* /*layer_name*/,
                                     uint32_t* count,
                                     VkExtensionProperties* /*properties*/) {
    *count = 0;
    return VK_SUCCESS;
}

VkResult
EnumerateInstanceLayerProperties(uint32_t* count,
                                 VkLayerProperties* /*properties*/) {
    *count = 0;
    return VK_SUCCESS;
}

VkResult CreateInstance(const VkInstanceCreateInfo* /*create_info*/,
                        const VkAllocationCallbacks* /*allocator*/,
                        VkInstance* instance) {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    for (size_t i = 0; i < kMaxInstances; i++) {
        if (!g_instance_used[i]) {
            g_instance_used[i] = true;
            g_instances[i].magic = HWVULKAN_DISPATCH_MAGIC;
            *instance = reinterpret_cast<VkInstance>(&g_instances[i]);
            return VK_SUCCESS;
        }
    }
    ALOGE("no more instances available (max=%zu)", kMaxInstances);
    return VK_ERROR_INITIALIZATION_FAILED;
}

void DestroyInstance(VkInstance instance,
                     const VkAllocationCallbacks* /*allocator*/) {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    ssize_t idx =
        reinterpret_cast<hwvulkan_dispatch_t*>(instance) - &g_instances[0];
    ALOG_ASSERT(idx >= 0 && static_cast<size_t>(idx) < g_instance_used.size(),
                "DestroyInstance: invalid instance handle");
    g_instance_used[static_cast<size_t>(idx)] = false;
}

VkResult EnumeratePhysicalDevices(VkInstance /*instance*/,
                                  uint32_t* count,
                                  VkPhysicalDevice* /*gpus*/) {
    *count = 0;
    return VK_SUCCESS;
}

VkResult
EnumeratePhysicalDeviceGroups(VkInstance /*instance*/,
                              uint32_t* count,
                              VkPhysicalDeviceGroupProperties* /*properties*/) {
    *count = 0;
    return VK_SUCCESS;
}

PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance,
                                       const char* name) {
    if (strcmp(name, "vkCreateInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(CreateInstance);
    if (strcmp(name, "vkDestroyInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(DestroyInstance);
    if (strcmp(name, "vkEnumerateInstanceExtensionProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(
            EnumerateInstanceExtensionProperties);
    if (strcmp(name, "vkEnumeratePhysicalDevices") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(EnumeratePhysicalDevices);
    if (strcmp(name, "vkEnumeratePhysicalDeviceGroups") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(
            EnumeratePhysicalDeviceGroups);
    if (strcmp(name, "vkGetInstanceProcAddr") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(GetInstanceProcAddr);
    // Per the spec, return NULL if instance is NULL.
    if (!instance)
        return nullptr;
    // None of the other Vulkan functions should ever be called, as they all
    // take a VkPhysicalDevice or other object obtained from a physical device.
    return reinterpret_cast<PFN_vkVoidFunction>(NoOp);
}

} // namespace vkstubhal

namespace {

int OpenDevice(const hw_module_t* module, const char* id, hw_device_t** device);

hw_module_methods_t goldfish_vulkan_module_methods = {
    .open = OpenDevice
};

extern "C" __attribute__((visibility("default"))) hwvulkan_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = HWVULKAN_MODULE_API_VERSION_0_1,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = HWVULKAN_HARDWARE_MODULE_ID,
        .name = "Goldfish Vulkan Driver",
        .author = "The Android Open Source Project",
        .methods = &goldfish_vulkan_module_methods,
    },
};

#define VK_HOST_CONNECTION(ret) \
    HostConnection *hostCon = HostConnection::get(); \
    if (!hostCon) { \
        ALOGE("vulkan: Failed to get host connection\n"); \
        return ret; \
    } \
    ExtendedRCEncoderContext *rcEnc = hostCon->rcEncoder(); \
    if (!rcEnc) { \
        ALOGE("vulkan: Failed to get renderControl encoder context\n"); \
        return ret; \
    } \
    goldfish_vk::VkEncoder *vkEnc = hostCon->vkEncoder(); \
    if (!vkEnc) { \
        ALOGE("vulkan: Failed to get Vulkan encoder\n"); \
        return ret; \
    } \
    goldfish_vk::ResourceTracker::get()->setupFeatures(rcEnc->featureInfo_const()); \
    auto hostSupportsVulkan = goldfish_vk::ResourceTracker::get()->hostSupportsVulkan(); \

int CloseDevice(struct hw_device_t* /*device*/) {
    VK_HOST_CONNECTION(-1)

    if (!hostSupportsVulkan) {
        // nothing to do - opening a device doesn't allocate any resources
        return 0;
    }

    goldfish_vk::TeardownFuncs teardownFuncs;
    teardownFuncs.vkDeviceWaitIdle =
        (PFN_vkDeviceWaitIdle)goldfish_vk::goldfish_vulkan_get_proc_address("vkDeviceWaitIdle");

#define GET_TEARDOWN_PROC_ADDR(func) \
    teardownFuncs.func = (PFN_##func)goldfish_vk::goldfish_vulkan_get_proc_address(#func);

    GET_TEARDOWN_PROC_ADDR(vkDestroyInstance)
    GET_TEARDOWN_PROC_ADDR(vkDestroyDevice)
    GET_TEARDOWN_PROC_ADDR(vkDestroySemaphore)
    GET_TEARDOWN_PROC_ADDR(vkDestroyFence)
    GET_TEARDOWN_PROC_ADDR(vkFreeMemory)
    GET_TEARDOWN_PROC_ADDR(vkDestroyBuffer)
    GET_TEARDOWN_PROC_ADDR(vkDestroyImage)
    GET_TEARDOWN_PROC_ADDR(vkDestroyEvent)
    GET_TEARDOWN_PROC_ADDR(vkDestroyQueryPool)
    GET_TEARDOWN_PROC_ADDR(vkDestroyBufferView)
    GET_TEARDOWN_PROC_ADDR(vkDestroyImageView)
    GET_TEARDOWN_PROC_ADDR(vkDestroyShaderModule)
    GET_TEARDOWN_PROC_ADDR(vkDestroyPipelineCache)
    GET_TEARDOWN_PROC_ADDR(vkDestroyPipelineLayout)
    GET_TEARDOWN_PROC_ADDR(vkDestroyRenderPass)
    GET_TEARDOWN_PROC_ADDR(vkDestroyPipeline)
    GET_TEARDOWN_PROC_ADDR(vkDestroyDescriptorSetLayout)
    GET_TEARDOWN_PROC_ADDR(vkDestroySampler)
    GET_TEARDOWN_PROC_ADDR(vkDestroyDescriptorPool)
    GET_TEARDOWN_PROC_ADDR(vkDestroyFramebuffer)
    GET_TEARDOWN_PROC_ADDR(vkDestroyCommandPool)

    goldfish_vk::ResourceTracker::get()->teardown(
        (void*)vkEnc,
        teardownFuncs);

    return 0;
}

VKAPI_ATTR
VkResult EnumerateInstanceExtensionProperties(
    const char* layer_name,
    uint32_t* count,
    VkExtensionProperties* properties) {

    VK_HOST_CONNECTION(VK_ERROR_DEVICE_LOST)

    if (!hostSupportsVulkan) {
        return vkstubhal::EnumerateInstanceExtensionProperties(layer_name, count, properties);
    }

    if (layer_name) {
        ALOGW(
            "Driver vkEnumerateInstanceExtensionProperties shouldn't be called "
            "with a layer name ('%s')",
            layer_name);
    }

    VkResult res = goldfish_vk::ResourceTracker::get()->on_vkEnumerateInstanceExtensionProperties(
        vkEnc, VK_SUCCESS, layer_name, count, properties);

    return res;
}

VKAPI_ATTR
VkResult CreateInstance(const VkInstanceCreateInfo* create_info,
                        const VkAllocationCallbacks* allocator,
                        VkInstance* out_instance) {
    VK_HOST_CONNECTION(VK_ERROR_DEVICE_LOST)

    if (!hostSupportsVulkan) {
        return vkstubhal::CreateInstance(create_info, allocator, out_instance);
    }

    VkResult res = vkEnc->vkCreateInstance(create_info, nullptr, out_instance);

    return res;
}

static PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* name) {
    VK_HOST_CONNECTION(nullptr)

    if (!hostSupportsVulkan) {
        return nullptr;
    }

    if (!strcmp(name, "vkGetDeviceProcAddr")) {
        return (PFN_vkVoidFunction)(GetDeviceProcAddr);
    }
    return (PFN_vkVoidFunction)(goldfish_vk::goldfish_vulkan_get_device_proc_address(device, name));
}

VKAPI_ATTR
PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* name) {
    VK_HOST_CONNECTION(nullptr)

    if (!hostSupportsVulkan) {
        return vkstubhal::GetInstanceProcAddr(instance, name);
    }

    if (!strcmp(name, "vkEnumerateInstanceExtensionProperties")) {
        return (PFN_vkVoidFunction)EnumerateInstanceExtensionProperties;
    }
    if (!strcmp(name, "vkCreateInstance")) {
        return (PFN_vkVoidFunction)CreateInstance;
    }
    if (!strcmp(name, "vkGetDeviceProcAddr")) {
        return (PFN_vkVoidFunction)(GetDeviceProcAddr);
    }
    return (PFN_vkVoidFunction)(goldfish_vk::goldfish_vulkan_get_instance_proc_address(instance, name));
}

hwvulkan_device_t goldfish_vulkan_device = {
    .common = {
        .tag = HARDWARE_DEVICE_TAG,
        .version = HWVULKAN_DEVICE_API_VERSION_0_1,
        .module = &HAL_MODULE_INFO_SYM.common,
        .close = CloseDevice,
    },
    .EnumerateInstanceExtensionProperties = EnumerateInstanceExtensionProperties,
    .CreateInstance = CreateInstance,
    .GetInstanceProcAddr = GetInstanceProcAddr,
};

int OpenDevice(const hw_module_t* /*module*/,
               const char* id,
               hw_device_t** device) {
    if (strcmp(id, HWVULKAN_DEVICE_0) == 0) {
        *device = &goldfish_vulkan_device.common;
        goldfish_vk::ResourceTracker::get();
        return 0;
    }
    return -ENOENT;
}

} // namespace
