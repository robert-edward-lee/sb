#ifndef HXX_SB_TYPE_TRAITS_IS_COMPOUND
#define HXX_SB_TYPE_TRAITS_IS_COMPOUND

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_fundamental.hxx"

namespace sb {
template<typename T> struct is_compound: integral_constant<bool, !is_fundamental<T>::value> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_COMPOUND
