#ifndef HXX_SB_TYPE_TRAITS_IS_ARRAY
#define HXX_SB_TYPE_TRAITS_IS_ARRAY

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/types.hxx"

namespace sb {
template<typename T> struct is_array: false_type {};
template<typename T> struct is_array<T[]>: true_type {};
template<typename T, size_t N> struct is_array<T[N]>: true_type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_ARRAY
