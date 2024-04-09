#ifndef HXX_SB_TYPE_TRAITS_IS_NULL_POINTER
#define HXX_SB_TYPE_TRAITS_IS_NULL_POINTER

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/is_same.hxx"
#include "sb/type_traits/remove_cv.hxx"

#if SB_CXX_VERSION_CHECK(201103)
#include <cstddef>
#endif

namespace sb {
#if SB_CXX_VERSION_CHECK(201103)
template<typename T> struct is_null_pointer: is_same<std::nullptr_t, typename remove_cv<T>::type> {};
#else
template<typename T> struct is_null_pointer: false_type {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_NULL_POINTER
