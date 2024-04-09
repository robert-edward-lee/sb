#ifndef HXX_SB_TYPE_TRAITS_IS_SAME
#define HXX_SB_TYPE_TRAITS_IS_SAME

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
template<typename T, typename U> struct is_same: false_type {};
template<typename T> struct is_same<T, T>: true_type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_SAME
