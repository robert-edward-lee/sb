#ifndef HXX_SB_TYPE_TRAITS_EXTENT
#define HXX_SB_TYPE_TRAITS_EXTENT

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/types.hxx"

namespace sb {
template<typename T, unsigned N = 0> struct extent: integral_constant<size_t, 0> {};
template<typename T> struct extent<T[], 0>: integral_constant<size_t, 0> {};
template<typename T, unsigned N> struct extent<T[], N>: extent<T, N - 1> {};
template<typename T, size_t I> struct extent<T[I], 0>: integral_constant<size_t, I> {};
template<typename T, size_t I, unsigned N> struct extent<T[I], N>: extent<T, N - 1> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_EXTENT
