#ifndef HXX_SB_TYPES
#define HXX_SB_TYPES

#include <stddef.h>

#include "sb/config.hxx"

#if SB_CXX_VERSION_CHECK(201103)
#include <cstdint>
#endif

#if SB_CXX_VERSION_CHECK(202302)
#include <stdfloat>
#endif

namespace sb {
#if SB_CXX_VERSION_CHECK(201103)
#define SB_HAS_INT64
typedef std::uint8_t u8;
typedef std::int8_t s8;
typedef std::uint16_t u16;
typedef std::int16_t s16;
typedef std::uint32_t u32;
typedef std::int32_t s32;
typedef std::uint64_t u64;
typedef std::int64_t s64;
#else
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
#if defined(SB_HAS_LONG_LONG)
#define SB_HAS_INT64
typedef unsigned long long u64;
typedef signed long long s64;
#elif defined(__GNUC__)
#define SB_HAS_INT64
__extension__ typedef unsigned long long u64;
__extension__ typedef signed long long s64;
#elif defined(SB_HAS_MSVC_INT64)
#define SB_HAS_INT64
typedef unsigned __int64 u64;
typedef signed __int64 s64;
#endif
#endif

#if defined(SB_HAS_GNUC_INT128)
#define SB_HAS_INT128
typedef __uint128_t u128;
typedef __int128_t s128;
#endif

using ::size_t;
using ::ptrdiff_t;

#if SB_CXX_VERSION_CHECK(202302)
#define SB_HAS_BFLOAT16
#define SB_HAS_FLOAT16
#define SB_HAS_FLOAT128
typedef std::bfloat16_t bf16;
typedef std::float16_t f16;
typedef std::float32_t f32;
typedef std::float64_t f64;
typedef std::float128_t f128;
#else
typedef float f32;
typedef double f64;
#if defined(SB_HAS_GNUC_FLOAT128) && !defined(SB_HAS_FLOAT128)
#define SB_HAS_FLOAT128
typedef __float128 f128;
#endif
#endif

} // namespace sb

#endif // HXX_SB_TYPES
