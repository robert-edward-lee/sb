#ifndef HXX_SB_TYPE_TRAITS_IS_OBJECT
#define HXX_SB_TYPE_TRAITS_IS_OBJECT

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_array.hxx"
#include "sb/type_traits/is_class.hxx"
#include "sb/type_traits/is_scalar.hxx"
#include "sb/type_traits/is_union.hxx"

namespace sb {
template<typename T>
struct is_object
    : integral_constant<bool, is_scalar<T>::value || is_array<T>::value || is_union<T>::value || is_class<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_OBJECT
