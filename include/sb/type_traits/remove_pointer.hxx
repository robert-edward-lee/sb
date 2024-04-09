#ifndef HXX_SB_TYPE_TRAITS_REMOVE_POINTER
#define HXX_SB_TYPE_TRAITS_REMOVE_POINTER

#include "sb/config.hxx"
#include "sb/type_traits/remove_cv.hxx"

namespace sb {
namespace detail {
template<typename T, typename> struct remove_pointer_helper {
    typedef T type;
};
template<typename T, typename U> struct remove_pointer_helper<T, U *> {
    typedef U type;
};
} // namespace detail
template<typename T> struct remove_pointer: detail::remove_pointer_helper<T, typename remove_cv<T>::type> {};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_REMOVE_POINTER
