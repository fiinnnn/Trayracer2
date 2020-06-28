#ifndef CORE_H
#define CORE_H

#include "core/log.h"

#include <memory>

#ifdef __linux__
    #define PLATFORM_LINUX
#elif defined(_WIN32)
    #define PLATFORM_WINDOWS \
    #error "Windows not supported"
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_MACOS
    #error "MacOS not supported"
#else
    #error "Unknown platform"
#endif

#ifndef NDEBUG
    #define ENABLE_ASSERT

    #if defined(PLATFORM_LINUX)
        #include <csignal>

        #define DEBUG_BREAK() raise(SIGTRAP)
    #else
        #warning "Debug break not supported"
    #endif
#else
    #define DEBUG_BREAK()
#endif

#ifdef ENABLE_ASSERT
    #define ASSERT(x, ...) {if(!(x)){LOG_ERROR("Assert failed: {0}", __VA_ARGS__);DEBUG_BREAK();}}
#else
    #define ASSERT
#endif

namespace Trayracer2 {

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> createScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> createRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

}

#endif //CORE_H
