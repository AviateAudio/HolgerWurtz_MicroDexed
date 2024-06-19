#pragma once
#include <type_traits>
#include "sysPlatform/SysTimer.h"

using SysPlatform::SysTimer;

#define constrain(amt, low, high) ({ \
  typeof(amt) _amt = (amt); \
  typeof(low) _low = (low); \
  typeof(high) _high = (high); \
  (_amt < _low) ? _low : ((_amt > _high) ? _high : _amt); \
})

// define a template equiavlent to the Arduino map function. It is not included in Multiverse libraries because
// it interferes with std::map
template <class T, class A, class B, class C, class D>
T map(T x, A in_min, B in_max, C out_min, D out_max, typename std::enable_if<std::is_floating_point<T>::value >::type* = 0)
{
	return (x - (T)in_min) * ((T)out_max - (T)out_min) / ((T)in_max - (T)in_min) + (T)out_min;
}

// computes limit((val >> rshift), 2**bits)
static inline int32_t signed_saturate_rshift(int32_t val, int bits, int rshift) __attribute__((always_inline, unused));
static inline int32_t signed_saturate_rshift(int32_t val, int bits, int rshift)
{
#if defined (__ARM_ARCH_7EM__)
	int32_t out;
	asm volatile("ssat %0, %1, %2, asr %3" : "=r" (out) : "I" (bits), "r" (val), "I" (rshift));
	return out;
#elif defined(KINETISL)
	int32_t out, max;
	out = val >> rshift;
	max = 1 << (bits - 1);
	if (out >= 0) {
		if (out > max - 1) out = max - 1;
	} else {
		if (out < -max) out = -max;
	}
	return out;
#endif
}
