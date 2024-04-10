#ifndef HXX_SB_TYPE_TRAITS_ALIGNMENT_OF
#define HXX_SB_TYPE_TRAITS_ALIGNMENT_OF

#include "sb/config.hxx"
#include "sb/type_traits/detail/minmax.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/types.hxx"

namespace sb {
namespace detail {
#if defined(__GNUC__)
template<typename T> struct alignment_of_impl: integral_constant<size_t, __alignof__(T)> {};
#else
template<typename T> struct offset_value {
    char c;
    T t;
};
template<typename T> struct alignment_of_impl: min<size_t, sizeof(offset_value<T>) - sizeof(T), sizeof(T)> {};
#endif
} // namespace detail
template<typename T> struct alignment_of: detail::alignment_of_impl<T> {};
template<typename T> struct alignment_of<T &>: alignment_of<T *> {};
template<> struct alignment_of<void>: integral_constant<size_t, 0> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_ALIGNMENT_OF
