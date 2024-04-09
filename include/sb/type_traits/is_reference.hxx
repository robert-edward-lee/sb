#ifndef HXX_SB_TYPE_TRAITS_IS_REFERENCE
#define HXX_SB_TYPE_TRAITS_IS_REFERENCE

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_lvalue_reference.hxx"
#include "sb/type_traits/is_rvalue_reference.hxx"

namespace sb {
template<typename T>
struct is_reference: integral_constant<bool, is_lvalue_reference<T>::value || is_rvalue_reference<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_REFERENCE
