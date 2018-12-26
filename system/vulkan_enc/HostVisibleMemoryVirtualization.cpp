// Copyright (C) 2018 The Android Open Source Project
// Copyright (C) 2018 Google Inc.
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
#include "HostVisibleMemoryVirtualization.h"

#include <log/log.h>

#include <set>

namespace goldfish_vk {

bool canFitVirtualHostVisibleMemoryInfo(
    const VkPhysicalDeviceMemoryProperties* memoryProperties) {
    uint32_t typeCount =
        memoryProperties->memoryTypeCount;
    uint32_t heapCount =
        memoryProperties->memoryHeapCount;

    bool canFit = true;

    if (typeCount == VK_MAX_MEMORY_TYPES) {
        canFit = false;
        ALOGE("Underlying device has no free memory types");
    }

    if (heapCount == VK_MAX_MEMORY_HEAPS) {
        canFit = false;
        ALOGE("Underlying device has no free memory heaps");
    }

    uint32_t numFreeMemoryTypes = VK_MAX_MEMORY_TYPES - typeCount;
    uint32_t numFreeMemoryHeaps = VK_MAX_MEMORY_HEAPS - heapCount;

    uint32_t hostVisibleMemoryTypeCount = 0;
    uint32_t hostVisibleMemoryHeapCount = 0;
    std::set<uint32_t> hostVisibleMemoryHeaps;

    for (uint32_t i = 0; i < typeCount; ++i) {
        const auto& type = memoryProperties->memoryTypes[i];
        if (type.propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) {
            ++hostVisibleMemoryTypeCount;
            hostVisibleMemoryHeaps.insert(type.heapIndex);
        }
    }
    hostVisibleMemoryHeapCount =
        (uint32_t)hostVisibleMemoryHeaps.size();

    if (hostVisibleMemoryTypeCount > numFreeMemoryTypes) {
        ALOGE("Underlying device has too many host visible memory types (%u)"
              "and not enough free types (%u)",
              hostVisibleMemoryTypeCount, numFreeMemoryTypes);
        canFit = false;
    }

    if (hostVisibleMemoryHeapCount > numFreeMemoryHeaps) {
        ALOGE("Underlying device has too many host visible memory types (%u)"
              "and not enough free types (%u)",
              hostVisibleMemoryHeapCount, numFreeMemoryHeaps);
        canFit = false;
    }

    return canFit;
}

void initHostVisibleMemoryVirtualizationInfo(
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceMemoryProperties* memoryProperties,
    bool hasDirectMem,
    HostVisibleMemoryVirtualizationInfo* info_out) {

    if (info_out->initialized) return;

    info_out->initialized = true;

    info_out->memoryPropertiesSupported =
        canFitVirtualHostVisibleMemoryInfo(memoryProperties);

    info_out->directMemSupported = hasDirectMem;

    if (!info_out->memoryPropertiesSupported ||
        !info_out->directMemSupported) {
        info_out->virtualizationSupported = false;
        return;
    }

    info_out->virtualizationSupported = true;

    info_out->physicalDevice = physicalDevice;
    info_out->hostMemoryProperties = *memoryProperties;
    info_out->guestMemoryProperties = *memoryProperties;

    uint32_t typeCount =
        memoryProperties->memoryTypeCount;
    uint32_t heapCount =
        memoryProperties->memoryHeapCount;

    uint32_t firstFreeTypeIndex = typeCount;
    uint32_t firstFreeHeapIndex = heapCount;

    for (uint32_t i = 0; i < typeCount; ++i) {

        // Set up identity mapping and not-both
        // by default, to be edited later.
        info_out->memoryTypeIndexMappingToHost[i] = i;
        info_out->memoryHeapIndexMappingToHost[i] = i;

        info_out->memoryTypeIndexMappingFromHost[i] = i;
        info_out->memoryHeapIndexMappingFromHost[i] = i;

        info_out->memoryTypeBitsShouldAdvertiseBoth[i] = false;

        const auto& type = memoryProperties->memoryTypes[i];

        if (type.propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) {
            uint32_t heapIndex = type.heapIndex;

            auto& guestMemoryType =
                info_out->guestMemoryProperties.memoryTypes[i];

            auto& newVirtualMemoryType =
                info_out->guestMemoryProperties.memoryTypes[firstFreeTypeIndex];

            auto& newVirtualMemoryHeap =
                info_out->guestMemoryProperties.memoryHeaps[firstFreeHeapIndex];

            // Remove all references to host visible in the guest memory type at
            // index i, while transferring them to the new virtual memory type.
            newVirtualMemoryType = type;

            // Set this memory type to have a separate heap.
            newVirtualMemoryType.heapIndex = firstFreeHeapIndex;

            newVirtualMemoryType.propertyFlags =
                type.propertyFlags &
                ~(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

            guestMemoryType.propertyFlags =
                type.propertyFlags & \
                ~(VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                  VK_MEMORY_PROPERTY_HOST_COHERENT_BIT |
                  VK_MEMORY_PROPERTY_HOST_CACHED_BIT);

            // In the corresponding new memory heap, copy the information over,
            // remove device local flags, and resize it based on what is
            // supported by the PCI device.
            newVirtualMemoryHeap =
                memoryProperties->memoryHeaps[heapIndex];
            newVirtualMemoryHeap.flags =
                newVirtualMemoryHeap.flags &
                ~(VK_MEMORY_HEAP_DEVICE_LOCAL_BIT);

            // TODO: Figure out how to support bigger sizes
            newVirtualMemoryHeap.size = 512ULL * 1048576ULL; // 512 MB

            info_out->memoryTypeIndexMappingToHost[firstFreeTypeIndex] = i;
            info_out->memoryHeapIndexMappingToHost[firstFreeHeapIndex] = i;

            info_out->memoryTypeIndexMappingFromHost[i] = firstFreeTypeIndex;
            info_out->memoryHeapIndexMappingFromHost[i] = firstFreeHeapIndex;

            // Was the original memory type also a device local type? If so,
            // advertise both types in resulting type bits.
            info_out->memoryTypeBitsShouldAdvertiseBoth[i] =
                type.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

            ++firstFreeTypeIndex;
            ++firstFreeHeapIndex;
        }
    }

    info_out->guestMemoryProperties.memoryTypeCount = firstFreeTypeIndex;
    info_out->guestMemoryProperties.memoryHeapCount = firstFreeHeapIndex;

    for (uint32_t i = info_out->guestMemoryProperties.memoryTypeCount; i < VK_MAX_MEMORY_TYPES; ++i) {
        memset(&info_out->guestMemoryProperties.memoryTypes[i],
               0x0, sizeof(VkMemoryType));
    }
}

} // namespace goldfish_vk
