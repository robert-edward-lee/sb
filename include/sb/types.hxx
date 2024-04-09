#ifndef HXX_SB_TYPES
#define HXX_SB_TYPES

#include <stddef.h>

#include "sb/config.hxx"

namespace sb {
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

using ::size_t;
using ::ptrdiff_t;

#if defined(SB_HAS_GNUC_INT128)
#define SB_HAS_INT128
typedef __uint128_t u128;
typedef __int128_t s128;
#endif

typedef float f32;
typedef double f64;

#if defined(SB_HAS_GNUC_FLOAT128)
#define SB_HAS_FLOAT128
typedef __float128 f128;
#endif

} // namespace sb

#endif // HXX_SB_TYPES
