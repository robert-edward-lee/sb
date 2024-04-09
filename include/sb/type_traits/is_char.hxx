#ifndef HXX_SB_TYPE_TRAITS_IS_CHAR
#define HXX_SB_TYPE_TRAITS_IS_CHAR

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/remove_cv.hxx"
#include "sb/types.hxx"

namespace sb {
namespace detail {
template<typename T> struct is_char_helper: false_type {};
template<> struct is_char_helper<char>: true_type {};
#if defined(SB_HAS_CHAR8)
template<> struct is_char_helper<char8_t>: true_type {};
#endif
template<> struct is_char_helper<wchar_t>: true_type {};
#if defined(SB_HAS_UNICODE_CHARS)
template<> struct is_char_helper<char16_t>: true_type {};
template<> struct is_char_helper<char32_t>: true_type {};
#endif
} // namespace detail
template<typename T> struct is_char: detail::is_char_helper<typename remove_cv<T>::type>::type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_CHAR
