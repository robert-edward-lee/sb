#ifndef HXX_SB_TYPE_TRAITS_IS_UNBOUNDED_ARRAY
#define HXX_SB_TYPE_TRAITS_IS_UNBOUNDED_ARRAY

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
template<typename T> struct is_unbounded_array: false_type {};
template<typename T> struct is_unbounded_array<T[]>: true_type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_UNBOUNDED_ARRAY
