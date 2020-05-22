#ifndef CORE_H
#define CORE_H

#include "log.h"

#include <csignal>

#ifndef NDEBUG
	#define ENABLE_ASSERT
#endif

#define DEBUG_BREAK() raise(SIGTRAP)

#ifdef ENABLE_ASSERT
	#define ASSERT(x, ...) {if(!(x)){LOG_ERROR("Assert failed: {0}", __VA_ARGS__);DEBUG_BREAK();}}
#else
	#define ASSERT
#endif

#endif //CORE_H
