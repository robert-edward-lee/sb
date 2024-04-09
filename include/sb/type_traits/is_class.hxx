#ifndef HXX_SB_TYPE_TRAITS_IS_CLASS
#define HXX_SB_TYPE_TRAITS_IS_CLASS

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
#if defined(SB_IS_CLASS)
template<typename T> struct is_class: integral_constant<bool, SB_IS_CLASS(T)> {};
#else
template<typename T> struct is_class: false_type {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_CLASS
