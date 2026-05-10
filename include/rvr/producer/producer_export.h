// Copyright 2026, Iurii Sernivka.

#pragma once

// Windows
#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef RVR_PRODUCER_BUILD
        #define RVR_PRODUCER_API __declspec(dllexport)
    #else
        #define RVR_PRODUCER_API __declspec(dllimport)
    #endif

// Linux/macOS
#else
    #ifdef RVR_PRODUCER_BUILD
        #define RVR_PRODUCER_API __attribute__((visibility("default")))
    #else
        #define RVR_PRODUCER_API
    #endif
#endif
