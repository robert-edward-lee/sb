#ifndef HXX_SB_TYPE_TRAITS_IS_UNSIGNED
#define HXX_SB_TYPE_TRAITS_IS_UNSIGNED

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_arithmetic.hxx"

namespace sb {
namespace detail {
template<typename T, bool = is_arithmetic<T>::value> struct is_unsigned_helper: false_type {};
template<typename T> struct is_unsigned_helper<T, true>: integral_constant<bool, T(0) < T(-1)> {};
} // namespace detail
template<typename T> struct is_unsigned: detail::is_unsigned_helper<T>::type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_UNSIGNED
