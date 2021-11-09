#ifndef SIMDJSON_SKYLAKE_INTRINSICS_H
#define SIMDJSON_SKYLAKE_INTRINSICS_H

#include "simdjson/base.h"

#ifdef SIMDJSON_VISUAL_STUDIO
// under clang within visual studio, this will include <x86intrin.h>
#include <intrin.h>  // visual studio or clang
#else
#include <x86intrin.h> // elsewhere
#endif // SIMDJSON_VISUAL_STUDIO

#ifdef SIMDJSON_CLANG_VISUAL_STUDIO
/**
 * You are not supposed, normally, to include these
 * headers directly. Instead you should either include intrin.h
 * or x86intrin.h. However, when compiling with clang
 * under Windows (i.e., when _MSC_VER is set), these headers
 * only get included *if* the corresponding features are detected
 * from macros:
 * e.g., if __AVX2__ is set... in turn,  we normally set these
 * macros by compiling against the corresponding architecture
 * (e.g., arch:AVX2, -mavx2, etc.) which compiles the whole
 * software with these advanced instructions. In simdjson, we
 * want to compile the whole program for a generic target,
 * and only target our specific kernels. As a workaround,
 * we directly include the needed headers. These headers would
 * normally guard against such usage, but we carefully included
 * <x86intrin.h>  (or <intrin.h>) before, so the headers
 * are fooled.
 */
#include <bmiintrin.h>   // for _blsr_u64
#include <lzcntintrin.h> // for  __lzcnt64
#include <immintrin.h>   // for most things (AVX2, AVX512, _popcnt64)
#include <smmintrin.h>
#include <tmmintrin.h>
#include <avxintrin.h>
#include <avx2intrin.h>
#include <avx512fintrin.h>
#include <wmmintrin.h>   // for  _mm_clmulepi64_si128
// unfortunately, we may not get _blsr_u64, but, thankfully, clang
// has it as a macro.
#ifndef _blsr_u64
// we roll our own
SIMDJSON_TARGET_SKYLAKE
static simdjson_really_inline uint64_t _blsr_u64(uint64_t n) {
  return (n - 1) & n;
}
SIMDJSON_UNTARGET_SKYLAKE
#endif //  _blsr_u64
#endif // SIMDJSON_CLANG_VISUAL_STUDIO

#endif // SIMDJSON_SKYLAKE_INTRINSICS_H
