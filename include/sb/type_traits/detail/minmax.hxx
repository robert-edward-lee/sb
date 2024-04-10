#ifndef HXX_SB_TYPE_TRAITS_DETAIL_MINMAX
#define HXX_SB_TYPE_TRAITS_DETAIL_MINMAX

#include "sb/type_traits/integral_constant.hxx"

namespace sb { namespace detail {
template<typename T, T A, T B> struct min: integral_constant<T, (A < B) ? A : B> {};
template<typename T, T A, T B> struct max: integral_constant<T, (A > B) ? A : B> {};
}} // namespace sb::detail

#endif // HXX_SB_TYPE_TRAITS_DETAIL_MINMAX
