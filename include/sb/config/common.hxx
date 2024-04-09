#ifndef HXX_SB_CONFIG_COMPILER_COMMON
#define HXX_SB_CONFIG_COMPILER_COMMON

#include "sb/utils.hxx"

#if defined(__cplusplus)
#if defined(_MSC_VER)
#define SB_CXX_VERSION_CHECK(v) (_MSC_LANG >= (v))
#define SB_CXX_VERSION_CHECK_STRICT(v) (_MSC_LANG > (v))
#else
#define SB_CXX_VERSION_CHECK(v) (__cplusplus >= (v))
#define SB_CXX_VERSION_CHECK_STRICT(v) (__cplusplus > (v))
#endif
#else
#define SB_CXX_VERSION_CHECK(v) 0
#define SB_CXX_VERSION_CHECK_STRICT(v) 0
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Language Feature-Test                            //
////////////////////////////////////////////////////////////////////////////////
#if defined(__cpp_alias_templates)
#define SB_HAS_ALIAS_TEMPLATES
#endif

#if defined(__cpp_char8_t)
#define SB_HAS_CHAR8
#endif

#if defined(__cpp_constexpr)
#if __cpp_constexpr >= 201907
#define SB_CONST_OR_CONSTEXPR constexpr
#define SB_CONSTEXPR constexpr
#define SB_CONSTEXPR_14 constexpr
#define SB_CONSTEXPR_20 constexpr
#elif __cpp_constexpr >= 201304
#define SB_CONST_OR_CONSTEXPR constexpr
#define SB_CONSTEXPR constexpr
#define SB_CONSTEXPR_14 constexpr
#define SB_CONSTEXPR_20
#else
#define SB_CONST_OR_CONSTEXPR constexpr
#define SB_CONSTEXPR constexpr
#define SB_CONSTEXPR_14
#define SB_CONSTEXPR_20
#endif
#else
#define SB_CONST_OR_CONSTEXPR const
#define SB_CONSTEXPR
#define SB_CONSTEXPR_14
#define SB_CONSTEXPR_20
#endif

#if defined(__cpp_if_constexpr)
#define SB_IF_CONSTEXPR if constexpr
#else
#define SB_IF_CONSTEXPR if
#endif

#if SB_CXX_VERSION_CHECK(201103)
#define SB_HAS_LONG_LONG
#endif

#if SB_CXX_VERSION_CHECK(201103)
#define SB_NOEXCEPT noexcept
#else
#define SB_NOEXCEPT throw()
#endif

#if defined(__cpp_rvalue_references)
#define SB_HAS_RVALUE_REFERENCES
#endif

#if defined(__cpp_static_assert)
#if __cpp_static_assert >= 201411
#define SB_STATIC_ASSERT(expr) static_assert(expr)
#define SB_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)
#else
#define SB_STATIC_ASSERT(expr) static_assert(expr, SB_STR(expr))
#define SB_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)
#endif
#else
#define SB_MAKE_ASSERT_NAME(a) SB_CONCAT(a, __COUNTER__)
#define SB_STATIC_ASSERT(expr) typedef char SB_MAKE_ASSERT_NAME(static_assertion_)[(expr) ? 1 : -1]
#define SB_STATIC_ASSERT_MSG(expr, msg) SB_STATIC_ASSERT(expr)
#endif

#if defined(__cpp_unicode_characters)
#define SB_HAS_UNICODE_CHARS
#endif

#if defined(__cpp_variadic_templates)
#define SB_HAS_VARIADIC_TEMPLATES
#endif

////////////////////////////////////////////////////////////////////////////////
//                           Attribute Feature-Test                           //
////////////////////////////////////////////////////////////////////////////////
#if defined(__has_cpp_attribute)
#define SB_HAS_ATTRIBUTE(x) __has_cpp_attribute(x)
#define SB_HAS_ATTRIBUTE_VER(x, v) (__has_cpp_attribute(x) >= (v))
#else
#define SB_HAS_ATTRIBUTE(x) 0
#define SB_HAS_ATTRIBUTE_VER(x, v) 0
#endif

#if SB_HAS_ATTRIBUTE(assume)
#define SB_ASSUME(e) [[assume(e)]]
#endif

#if SB_HAS_ATTRIBUTE(carries_dependency)
#define SB_CARRIES_DEPENDENCY [[carries_dependency]]
#endif

#if SB_HAS_ATTRIBUTE(deprecated)
#define SB_DEPRECATED [[deprecated]]
#define SB_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#endif

#if SB_HAS_ATTRIBUTE(fallthrough)
#define SB_FALLTHROUGH [[fallthrough]]
#endif

#if SB_HAS_ATTRIBUTE(maybe_unused) && SB_CXX_VERSION_CHECK(201603)
#define SB_MAYBE_UNUSED [[maybe_unused]]
#endif

#if SB_HAS_ATTRIBUTE_VER(nodiscard, 201907)
#define SB_NODISCARD [[nodiscard]]
#define SB_NODISCARD_MSG(msg) [[nodiscard(msg)]]
#elif SB_HAS_ATTRIBUTE_VER(nodiscard, 201603)
#define SB_NODISCARD [[nodiscard]]
#define SB_NODISCARD_MSG(msg) [[nodiscard]]
#endif

#if SB_HAS_ATTRIBUTE(noreturn)
#define SB_NORETURN [[noreturn]]
#endif

#endif // HXX_SB_CONFIG_COMPILER_COMMON
