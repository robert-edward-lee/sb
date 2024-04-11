#ifndef HXX_SB_CONFIG_COMPILER_GCC
#define HXX_SB_CONFIG_COMPILER_GCC

#include "sb/config/common.hxx"

#define SB_GCC_VERSION_VALUE(maj, min, patch) (10000 * (maj) + 100 * (min) + (patch))
#define SB_GCC_VERSION_CURRENT SB_GCC_VERSION_VALUE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#define SB_GCC_VERSION_CHECK(maj, min, patch) (SB_GCC_VERSION_CURRENT >= SB_GCC_VERSION_VALUE(maj, min, patch))
#define SB_GCC_VERSION_CHECK_STRICT(maj, min, patch) (SB_GCC_VERSION_CURRENT > SB_GCC_VERSION_VALUE(maj, min, patch))

#define SB_DO_PRAGMA(x) _Pragma(SB_STR(x))
#if SB_GCC_VERSION_CHECK(4, 6, 0)
#define SB_GCC_IGNORE_WARNING_PUSH(warning) \
    SB_DO_PRAGMA(GCC diagnostic push) SB_DO_PRAGMA(GCC diagnostic ignored warning)
#define SB_GCC_IGNORE_WARNING_POP() SB_DO_PRAGMA(GCC diagnostic pop)
#else
#define SB_GCC_IGNORE_WARNING_PUSH(warning)
#define SB_GCC_IGNORE_WARNING_POP()
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Language Feature-Test                            //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_HAS_LONG_LONG) && defined(__GXX_EXPERIMENTAL_CXX0X__)
#define SB_HAS_LONG_LONG
#endif

#if !defined(SB_HAS_RVALUE_REFERENCES) && defined(__GXX_EXPERIMENTAL_CXX0X__) && SB_GCC_VERSION_CHECK(4, 3, 0)
#define SB_HAS_RVALUE_REFERENCES
#endif

#if !defined(SB_HAS_UNICODE_CHARS) && defined(__GXX_EXPERIMENTAL_CXX0X__) && SB_GCC_VERSION_CHECK(4, 4, 0)
#define SB_HAS_UNICODE_CHARS
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Attribute Feature-Test                           //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_ALWAYS_INLINE) && SB_GCC_VERSION_CHECK(3, 1, 0)
#define SB_ALWAYS_INLINE __attribute__((always_inline))
#endif

#if !defined(SB_ASSUME)
#if SB_GCC_VERSION_CHECK(13, 0, 0)
#define SB_ASSUME(x) __attribute__((assume(x)))
#elif SB_GCC_VERSION_CHECK(4, 6, 2)
#define SB_ASSUME(x)                 \
    do {                             \
        if(!(x)) {                   \
            __builtin_unreachable(); \
        }                            \
    } while(0)
#endif
#endif

#if !defined(SB_DEPRECATED) && SB_GCC_VERSION_CHECK(3, 1, 0)
#define SB_DEPRECATED __attribute__((deprecated))
#define SB_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#endif

#if !defined(SB_FALLTHROUGH) && SB_GCC_VERSION_CHECK(7, 0, 0)
#define SB_FALLTHROUGH __attribute__((fallthrough))
#endif

#if !defined(SB_LIKELY) && SB_GCC_VERSION_CHECK(2, 96, 0)
#define SB_LIKELY(x) __builtin_expect(x, 1)
#define SB_UNLIKELY(x) __builtin_expect(x, 0)
#endif

#if !defined(SB_MAYBE_UNUSED) && SB_GCC_VERSION_CHECK(2, 7, 0)
#define SB_MAYBE_UNUSED __attribute__((unused))
#endif

#if !defined(SB_NODISCARD) && SB_GCC_VERSION_CHECK(3, 3, 0)
#define SB_NODISCARD __attribute__((warn_unused_result))
#define SB_NODISCARD_MSG(msg) __attribute__((warn_unused_result))
#endif

#if !defined(SB_NOINLINE) && SB_GCC_VERSION_CHECK(2, 96, 0)
#define SB_NOINLINE __attribute__((noinline))
#endif

#if !defined(SB_NORETURN) && SB_GCC_VERSION_CHECK(2, 5, 0)
#define SB_NORETURN __attribute__((noreturn))
#endif

////////////////////////////////////////////////////////////////////////////////
//                            Compiler intrinsics                             //
////////////////////////////////////////////////////////////////////////////////
#if defined(__SIZEOF_FLOAT128__)
#define SB_HAS_GNUC_FLOAT128
#endif

#if defined(__SIZEOF_INT128__)
#define SB_HAS_GNUC_INT128
#endif

#if SB_GCC_VERSION_CHECK(4, 3, 3)
#define SB_IS_CLASS(x) __is_class(x)
#define SB_IS_ENUM(x) __is_enum(x)
#define SB_IS_UNION(x) __is_union(x)
#endif

#endif // HXX_SB_CONFIG_COMPILER_GCC
