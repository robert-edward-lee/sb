#ifndef HXX_SB_TYPE_TRAITS_IS_FUNCTION
#define HXX_SB_TYPE_TRAITS_IS_FUNCTION

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_const.hxx"
#include "sb/type_traits/is_reference.hxx"

namespace sb {
template<typename T>
struct is_function: integral_constant<bool, !is_const<const T>::value && !is_reference<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_FUNCTION
