#ifndef HXX_SB_TYPE_TRAITS_IS_CONST
#define HXX_SB_TYPE_TRAITS_IS_CONST

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
template<typename T> struct is_const: false_type {};
template<typename T> struct is_const<const T>: true_type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_CONST
