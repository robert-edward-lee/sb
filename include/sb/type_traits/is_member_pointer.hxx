#ifndef HXX_SB_TYPE_TRAITS_IS_MEMBER_POINTER
#define HXX_SB_TYPE_TRAITS_IS_MEMBER_POINTER

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/remove_cv.hxx"

namespace sb {
namespace detail {
template<typename T> struct is_member_pointer_helper: false_type {};
template<typename T, typename U> struct is_member_pointer_helper<T U::*>: true_type {};
} // namespace detail
template<typename T> struct is_member_pointer: detail::is_member_pointer_helper<typename remove_cv<T>::type> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_MEMBER_POINTER
