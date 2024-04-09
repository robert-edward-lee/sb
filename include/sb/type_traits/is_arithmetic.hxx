#ifndef HXX_SB_TYPE_TRAITS_IS_ARITHMETIC
#define HXX_SB_TYPE_TRAITS_IS_ARITHMETIC

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_floating_point.hxx"
#include "sb/type_traits/is_integral.hxx"

namespace sb {
template<typename T>
struct is_arithmetic: integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_ARITHMETIC
