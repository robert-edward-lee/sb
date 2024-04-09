#ifndef HXX_SB_TYPE_TRAITS_IS_UNION
#define HXX_SB_TYPE_TRAITS_IS_UNION

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
#if defined(SB_IS_UNION)
template<typename T> struct is_union: integral_constant<bool, SB_IS_UNION(T)> {};
#else
template<typename T> struct is_union: false_type {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_UNION
