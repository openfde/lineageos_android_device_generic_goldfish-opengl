/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <errno.h>
#include <log/log.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <qemu_pipe_bp.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace {
int open_verbose(const char* name, int flags) {
    const int fd = QEMU_PIPE_RETRY(open(name, flags));
    if (fd < 0) {
        ALOGE("%s:%d: Could not open '%s': %s",
              __func__, __LINE__, name, strerror(errno));
    }
    return fd;
}

}  // namespace

extern "C" {

int qemu_pipe_open_ns(const char* ns, const char* pipeName, int flags) {
    if (pipeName == NULL || pipeName[0] == '\0') {
        errno = EINVAL;
        return -1;
    }
    if (strstr(pipeName,"opengles") == NULL) {
        errno = EINVAL;
        return -1;
    }
    
    char buf[256];
    int bufLen;
    if (ns) {
        bufLen = snprintf(buf, sizeof(buf), "pipe:%s:%s", ns, pipeName);
    } else {
        bufLen = snprintf(buf, sizeof(buf), "pipe:%s", pipeName);
    }


    /*
    const int fd = open_verbose("/dev/goldfish_pipe", flags);
    if (fd < 0) {
        return fd;
    }*/


    #if 0
    fd = open("/dev/qemu_pipe", O_RDWR);
    #else

    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/sockets/qemu_pipe", sizeof(addr.sun_path));  

    if (connect(fd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        ALOGE("###### Failed to connect to pipe:%s %d, %s ######", pipeName, errno, strerror(errno));
    #if !defined(QEMU_PIPE_FROM_ADB)
        close(fd);
    #else
        // Adb renames 'close' to 'unix_close' and marks the original
        // 'close' as not available.
        unix_close(fd);
    #endif
        fd = -1;
    }
    #endif

    if (fd < 0 && errno == ENOENT)
        fd = open("/dev/goldfish_pipe", O_RDWR);
    if (fd < 0) {
        ALOGD("%s: Could not open /dev/qemu_pipe: %s", __FUNCTION__, strerror(errno));
        //errno = ENOSYS;
        return -1;
    }

    //buffLen = strlen(buff);


    /*char buf[256];
    int bufLen;
    if (ns) {
        bufLen = snprintf(buf, sizeof(buf), "pipe:%s:%s", ns, pipeName);
    } else {
        bufLen = snprintf(buf, sizeof(buf), "pipe:%s", pipeName);
    }*/

    if (qemu_pipe_write_fully(fd, buf, bufLen + 1)) {
        ALOGE("%s:%d: Could not connect to the '%s' service: %s",
              __func__, __LINE__, buf, strerror(errno));
        return -1;
    }

    return fd;
}

int qemu_pipe_open(const char* pipeName) {
    return qemu_pipe_open_ns(NULL, pipeName, O_RDWR | O_NONBLOCK);
}

void qemu_pipe_close(int pipe) {
    close(pipe);
}

int qemu_pipe_read(int pipe, void* buffer, int size) {
    return read(pipe, buffer, size);
}

int qemu_pipe_write(int pipe, const void* buffer, int size) {
    return write(pipe, buffer, size);
}

int qemu_pipe_try_again(int ret) {
    return (ret < 0) && (errno == EINTR || errno == EAGAIN);
}

void qemu_pipe_print_error(int pipe) {
    ALOGE("pipe error: fd %d errno %d", pipe, errno);
}

}  // extern "C"
