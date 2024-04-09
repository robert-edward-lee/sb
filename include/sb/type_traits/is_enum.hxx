#ifndef HXX_SB_TYPE_TRAITS_IS_ENUM
#define HXX_SB_TYPE_TRAITS_IS_ENUM

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
#if defined(SB_IS_ENUM)
template<typename T> struct is_enum: integral_constant<bool, SB_IS_ENUM(T)> {};
#else
template<typename T> struct is_enum: false_type {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_ENUM
