#ifndef HXX_SB_CONFIG
#define HXX_SB_CONFIG

////////////////////////////////////////////////////////////////////////////////
//                           Select Compiler Config                           //
////////////////////////////////////////////////////////////////////////////////
#if defined(__GNUC__) && !defined(__clang__)
#include "sb/config/compiler/gcc.hxx"
#elif defined(_MSC_VER) && !defined(__clang__)
#include "sb/config/compiler/msvc.hxx"
#elif defined(__clang__)
#include "sb/config/compiler/clang.hxx"
#else
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Attribute Feature-Test                           //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_ALWAYS_INLINE)
#define SB_ALWAYS_INLINE
#endif

#if !defined(SB_ASSUME)
#define SB_ASSUME(x)
#endif

#if !defined(SB_CARRIES_DEPENDENCY)
#define SB_CARRIES_DEPENDENCY
#endif

#if !defined(SB_DEPRECATED)
#define SB_DEPRECATED
#define SB_DEPRECATED_MSG(msg)
#endif

#if !defined(SB_FALLTHROUGH)
#define SB_FALLTHROUGH
#endif

#if !defined(SB_LIKELY)
#define SB_LIKELY(x) (x)
#define SB_UNLIKELY(x) (x)
#endif

#if !defined(SB_MAYBE_UNUSED)
#define SB_MAYBE_UNUSED
#endif

#if !defined(SB_NODISCARD)
#define SB_NODISCARD
#define SB_NODISCARD_MSG(msg)
#endif

#if !defined(SB_NOINLINE)
#define SB_NOINLINE
#endif

#if !defined(SB_NORETURN)
#define SB_NORETURN
#endif

#endif // HXX_SB_CONFIG
