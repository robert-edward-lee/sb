#ifndef HXX_SB_TYPE_TRAITS_IS_VOID
#define HXX_SB_TYPE_TRAITS_IS_VOID

#include "sb/config.hxx"
#include "sb/type_traits/is_same.hxx"
#include "sb/type_traits/remove_cv.hxx"

namespace sb {
template<typename T> struct is_void: is_same<void, typename remove_cv<T>::type> {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_VOID
