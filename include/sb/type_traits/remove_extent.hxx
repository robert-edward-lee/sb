#ifndef HXX_SB_TYPE_TRAITS_REMOVE_EXTENT
#define HXX_SB_TYPE_TRAITS_REMOVE_EXTENT

#include "sb/config.hxx"
#include "sb/types.hxx"

namespace sb {
template<typename T> struct remove_extent {
    typedef T type;
};
template<typename T> struct remove_extent<T[]> {
    typedef T type;
};
template<typename T, size_t N> struct remove_extent<T[N]> {
    typedef T type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using remove_extent_t = typename remove_extent<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_REMOVE_EXTENT
