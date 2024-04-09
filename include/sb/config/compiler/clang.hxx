#ifndef HXX_SB_CONFIG_COMPILER_CLANG
#define HXX_SB_CONFIG_COMPILER_CLANG

#include "sb/config/common.hxx"

#define SB_CLANG_VERSION_VALUE(maj, min, patch) (10000 * (maj) + 100 * (min) + (patch))
#define SB_CLANG_CURRENT_VERSION SB_CLANG_VERSION_VALUE(__clang_major__, __clang_minor__, __clang_patchlevel__)
#define SB_CLANG_VERSION_CHECK(maj, min, patch) (SB_CLANG_CURRENT_VERSION >= SB_CLANG_VERSION_VALUE(maj, min, patch))
#define SB_CLANG_VERSION_CHECK_STRICT(maj, min, patch) \
    (SB_CLANG_CURRENT_VERSION > SB_CLANG_VERSION_VALUE(maj, min, patch))

#define SB_DO_PRAGMA(x) _Pragma(SB_STR(x))
#define SB_GCC_IGNORE_WARNING_PUSH(warning) \
    SB_DO_PRAGMA(GCC diagnostic push) SB_DO_PRAGMA(GCC diagnostic ignored warning)
#define SB_GCC_IGNORE_WARNING_POP() SB_DO_PRAGMA(GCC diagnostic pop)

////////////////////////////////////////////////////////////////////////////////
//                           Language Feature-Test                            //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_HAS_LONG_LONG)
#define SB_HAS_LONG_LONG
#endif

#if !defined(SB_HAS_RVALUE_REFERENCES) && __has_feature(cxx_rvalue_references)
#define SB_HAS_RVALUE_REFERENCES
#endif

#if !defined(SB_HAS_UNICODE_CHARS) && ((defined(_MSC_VER) && _MSC_VER >= 1900) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#define SB_HAS_UNICODE_CHARS
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Attribute Feature-Test                           //
////////////////////////////////////////////////////////////////////////////////
#if !defined(SB_ALWAYS_INLINE)
#define SB_ALWAYS_INLINE __attribute__((always_inline))
#endif

#if !defined(SB_ASSUME)
#if __has_builtin(__builtin_assume)
#define SB_ASSUME(x) __builtin_assume(x)
#elif __has_builtin(__builtin_unreachable)
#define SB_ASSUME(x)                 \
    do {                             \
        if(!(x)) {                   \
            __builtin_unreachable(); \
        }                            \
    } while(0)
#endif
#endif

#if !defined(SB_DEPRECATED)
#define SB_DEPRECATED __attribute__((deprecated))
#define SB_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#endif

#if !defined(SB_FALLTHROUGH)
#define SB_FALLTHROUGH __attribute__((fallthrough))
#endif

#if !defined(SB_LIKELY) && __has_builtin(__builtin_expect)
#define SB_LIKELY(x) __builtin_expect(x, 1)
#define SB_UNLIKELY(x) __builtin_expect(x, 0)
#endif

#if !defined(SB_MAYBE_UNUSED)
#define SB_MAYBE_UNUSED __attribute__((unused))
#endif

#if !defined(SB_NODISCARD)
#define SB_NODISCARD __attribute__((warn_unused_result))
#define SB_NODISCARD_MSG(msg) __attribute__((warn_unused_result))
#endif

#if !defined(SB_NOINLINE)
#define SB_NOINLINE __attribute__((noinline))
#endif

#if !defined(SB_NORETURN)
#define SB_NORETURN __attribute__((noreturn))
#endif

////////////////////////////////////////////////////////////////////////////////
//                            Compiler intrinsics                             //
////////////////////////////////////////////////////////////////////////////////
#if defined(__SIZEOF_FLOAT128__)
#define SB_HAS_GNUC_FLOAT128
#endif

#ifdef __is_identifier
#if __is_identifier(__int64) && !defined(__GNUC__)
#define SB_HAS_MSVC_INT64
#endif
#endif

#if defined(__SIZEOF_INT128__)
#define SB_HAS_GNUC_INT128
#endif

#if __has_feature(is_class)
#define SB_IS_CLASS(x) __is_class(x)
#endif

#if __has_feature(is_enum)
#define SB_IS_ENUM(x) __is_enum(x)
#endif

#if __has_feature(is_union)
#define SB_IS_UNION(x) __is_union(x)
#endif

#endif // HXX_SB_CONFIG_COMPILER_CLANG
