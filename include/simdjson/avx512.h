#ifndef SIMDJSON_AVX512_H
#define SIMDJSON_AVX512_H

#include "simdjson/implementation-base.h"

#if SIMDJSON_IMPLEMENTATION_AVX512

#if SIMDJSON_CAN_ALWAYS_RUN_AVX512
#define SIMDJSON_TARGET_AVX512
#define SIMDJSON_UNTARGET_AVX512
#else
#define SIMDJSON_TARGET_AVX512 SIMDJSON_TARGET_REGION("avx512f,bmi,pclmul,lzcnt")
#define SIMDJSON_UNTARGET_AVX512 SIMDJSON_UNTARGET_REGION
#endif

namespace simdjson {
/**
 * Implementation for cpus supporting AVX512.
 */
namespace avx512 {
} // namespace avx512
} // namespace simdjson

//
// These two need to be included outside SIMDJSON_TARGET_AVX512
//
#include "simdjson/avx512/implementation.h"
#include "simdjson/avx512/intrinsics.h"

//
// The rest need to be inside the region
//
#include "simdjson/avx512/begin.h"

// Declarations
#include "simdjson/generic/dom_parser_implementation.h"
#include "simdjson/avx512/bitmanipulation.h"
#include "simdjson/avx512/bitmask.h"
#include "simdjson/avx512/simd.h"
#include "simdjson/generic/jsoncharutils.h"
#include "simdjson/generic/atomparsing.h"
#include "simdjson/avx512/stringparsing.h"
#include "simdjson/avx512/numberparsing.h"
#include "simdjson/avx512/end.h"

#endif // SIMDJSON_IMPLEMENTATION_AVX512
#endif // SIMDJSON_AVX512_COMMON_H
