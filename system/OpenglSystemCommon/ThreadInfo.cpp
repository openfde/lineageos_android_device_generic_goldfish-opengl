/*
* Copyright (C) 2011 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "ThreadInfo.h"

#ifdef __BIONIC__
#include <bionic/tls.h>
#endif

#ifdef __ANDROID__
// Are we missing an actual set of TLS defs?
#ifdef GOLDFISH_OPENGL_NO_PLATFORM_BIONIC_INCLUDES
#include <bionic_tls.h>
#endif
#endif

#include <pthread.h>

#include  <sys/types.h>
//#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

extern pid_t gettid();

typedef struct {
    pthread_mutex_t   lock;
    int               has_tls;
    pthread_key_t     tls;
} thread_store_t;

#define  THREAD_STORE_INITIALIZER  { PTHREAD_MUTEX_INITIALIZER, 0, 0 }

typedef void  (*thread_store_destruct_t)(void*  value);

extern void*  thread_store_get(thread_store_t*  store);

extern void   thread_store_set(thread_store_t*          store,
                               void*                    value,
                               thread_store_destruct_t  destroy);

#ifdef __cplusplus
}
#endif

void*  thread_store_get( thread_store_t*  store )
{
    if (!store->has_tls)
        return NULL;

    return pthread_getspecific( store->tls );
}

extern void   thread_store_set( thread_store_t*          store,
                                void*                    value,
                                thread_store_destruct_t  destroy)
{
    pthread_mutex_lock( &store->lock );
    if (!store->has_tls) {
        if (pthread_key_create( &store->tls, destroy) != 0) {
            pthread_mutex_unlock(&store->lock);
            return;
        }
        store->has_tls = 1;
    }
    pthread_mutex_unlock( &store->lock );

    pthread_setspecific( store->tls, value );
}

thread_store_t s_tls = THREAD_STORE_INITIALIZER;

static bool sDefaultTlsDestructorCallback(__attribute__((__unused__)) void* ptr) {
  return true;
}
static bool (*sTlsDestructorCallback)(void*) = sDefaultTlsDestructorCallback;

static void tlsDestruct(void *ptr)
{
    sTlsDestructorCallback(ptr);
    if (ptr
#ifdef __ANDROID__
         && ((void **)__get_tls())[TLS_SLOT_OPENGL]
#endif
        ) {
        EGLThreadInfo *ti = (EGLThreadInfo *)ptr;
        delete ti->hostConn;
        delete ti;
#ifdef __ANDROID__
        ((void **)__get_tls())[TLS_SLOT_OPENGL] = NULL;
#endif
    }
}

void setTlsDestructor(tlsDtorCallback func) {
    sTlsDestructorCallback = func;
}

EGLThreadInfo *goldfish_get_egl_tls()
{
    EGLThreadInfo* ti = (EGLThreadInfo*)thread_store_get(&s_tls);

    if (ti) return ti;

    ti = new EGLThreadInfo();
    thread_store_set(&s_tls, ti, tlsDestruct);

    return ti;
}

EGLThreadInfo* getEGLThreadInfo() {
#ifdef __ANDROID__
    EGLThreadInfo *tInfo =
        (EGLThreadInfo *)(((uintptr_t *)__get_tls())[TLS_SLOT_OPENGL]);
    if (!tInfo) {
        tInfo = goldfish_get_egl_tls();
        ((uintptr_t *)__get_tls())[TLS_SLOT_OPENGL] = (uintptr_t)tInfo;
    }
    return tInfo;
#else
    return goldfish_get_egl_tls();
#endif
}

int32_t getCurrentThreadId() {
    return (int32_t)gettid();
}
