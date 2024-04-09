#ifndef HXX_SB_TYPE_TRAITS_IS_VOLATILE
#define HXX_SB_TYPE_TRAITS_IS_VOLATILE

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
template<typename T> struct is_volatile: false_type {};
template<typename T> struct is_volatile<volatile T>: true_type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_VOLATILE
