#pragma once

#include <memory>
#include "Ref.h"
#include "Log.h"

namespace U {

	void InitializeCore();
	void ShutdownCore();

}


#ifdef U_PLATFORM_WINDOWS
	#define Ungine_API
#else
	#error Ungine only supports Windows!
#endif

// __VA_ARGS__ expansion to get past MSVC "bug"
#define U_EXPAND_VARGS(x) x

#define BIT(x) (1 << x)

#define U_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)


#include "Assert.h"

// Pointer wrappers
namespace U {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	using byte = uint8_t;

}
