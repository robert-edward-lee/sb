#ifndef HXX_SB_TYPE_TRAITS_IS_FUNDAMENTAL
#define HXX_SB_TYPE_TRAITS_IS_FUNDAMENTAL

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_arithmetic.hxx"
#include "sb/type_traits/is_null_pointer.hxx"
#include "sb/type_traits/is_void.hxx"

namespace sb {
template<typename T>
struct is_fundamental
    : integral_constant<bool, is_arithmetic<T>::value || is_void<T>::value || is_null_pointer<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_FUNDAMENTAL
