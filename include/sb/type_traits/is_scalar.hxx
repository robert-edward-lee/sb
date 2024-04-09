#ifndef HXX_SB_TYPE_TRAITS_IS_SCALAR
#define HXX_SB_TYPE_TRAITS_IS_SCALAR

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_arithmetic.hxx"
#include "sb/type_traits/is_enum.hxx"
#include "sb/type_traits/is_member_pointer.hxx"
#include "sb/type_traits/is_null_pointer.hxx"
#include "sb/type_traits/is_pointer.hxx"

namespace sb {
template<typename T>
struct is_scalar: integral_constant<bool,
                                    is_arithmetic<T>::value || is_enum<T>::value || is_pointer<T>::value
                                        || is_member_pointer<T>::value || is_null_pointer<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_SCALAR
