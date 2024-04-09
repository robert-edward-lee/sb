#ifndef HXX_SB_TYPE_TRAITS_REMOVE_ALL_EXTENTS
#define HXX_SB_TYPE_TRAITS_REMOVE_ALL_EXTENTS

#include "sb/config.hxx"
#include "sb/types.hxx"

namespace sb {
template<typename T> struct remove_all_extents {
    typedef T type;
};
template<typename T> struct remove_all_extents<T[]> {
    typedef T type;
};
template<typename T, size_t N> struct remove_all_extents<T[N]> {
    typedef typename remove_all_extents<T>::type type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using remove_all_extents_t = typename remove_all_extents<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_REMOVE_ALL_EXTENTS
