#ifndef HXX_SB_TYPE_TRAITS_IS_SIGNED
#define HXX_SB_TYPE_TRAITS_IS_SIGNED

#include "sb/config.hxx"
#include "sb/type_traits/conditional.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_arithmetic.hxx"
#include "sb/type_traits/is_floating_point.hxx"

namespace sb {
namespace detail {
template<typename T, bool = is_arithmetic<T>::value> struct is_signed_helper: false_type {};
template<typename T> struct is_signed_helper<T, true>: integral_constant<bool, T(-1) < T(0)> {};
template<typename T>
struct is_signed_selector: conditional<is_floating_point<T>::value, true_type, is_signed_helper<T> > {};
} // namespace detail
template<typename T> struct is_signed: detail::is_signed_selector<T>::type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_SIGNED
