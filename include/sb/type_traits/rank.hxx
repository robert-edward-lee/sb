#ifndef HXX_SB_TYPE_TRAITS_RANK
#define HXX_SB_TYPE_TRAITS_RANK

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/types.hxx"

namespace sb {
template<typename T> struct rank: integral_constant<size_t, 0> {};
template<typename T> struct rank<T[]>: integral_constant<size_t, rank<T>::value + 1> {};
template<typename T, size_t N> struct rank<T[N]>: integral_constant<size_t, rank<T>::value + 1> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_RANK
