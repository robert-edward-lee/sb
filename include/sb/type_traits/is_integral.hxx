#ifndef HXX_SB_TYPE_TRAITS_IS_INTEGRAL
#define HXX_SB_TYPE_TRAITS_IS_INTEGRAL

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/remove_cv.hxx"
#include "sb/types.hxx"

namespace sb {
namespace detail {
template<typename T> struct is_integral_helper: false_type {};
template<> struct is_integral_helper<bool>: true_type {};
template<> struct is_integral_helper<char>: true_type {};
template<> struct is_integral_helper<unsigned char>: true_type {};
template<> struct is_integral_helper<signed char>: true_type {};
#if defined(SB_HAS_CHAR8)
template<> struct is_integral_helper<char8_t>: true_type {};
#endif
template<> struct is_integral_helper<wchar_t>: true_type {};
#if defined(SB_HAS_UNICODE_CHARS)
template<> struct is_integral_helper<char16_t>: true_type {};
template<> struct is_integral_helper<char32_t>: true_type {};
#endif
template<> struct is_integral_helper<unsigned short>: true_type {};
template<> struct is_integral_helper<signed short>: true_type {};
template<> struct is_integral_helper<unsigned int>: true_type {};
template<> struct is_integral_helper<signed int>: true_type {};
template<> struct is_integral_helper<unsigned long>: true_type {};
template<> struct is_integral_helper<signed long>: true_type {};
#if defined(SB_HAS_LONG_LONG)
template<> struct is_integral_helper<unsigned long long>: true_type {};
template<> struct is_integral_helper<signed long long>: true_type {};
#elif defined(__GNUC__)
__extension__ template<> struct is_integral_helper<unsigned long long>: true_type {};
__extension__ template<> struct is_integral_helper<signed long long>: true_type {};
#elif defined(SB_HAS_MSVC_INT64)
template<> struct is_integral_helper<unsigned __int64>: true_type {};
template<> struct is_integral_helper<signed __int64>: true_type {};
#endif
#if defined(SB_HAS_GNUC_INT128)
template<> struct is_integral_helper<__uint128_t>: true_type {};
template<> struct is_integral_helper<__int128_t>: true_type {};
#endif
} // namespace detail
template<typename T> struct is_integral: detail::is_integral_helper<typename remove_cv<T>::type>::type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_INTEGRAL
