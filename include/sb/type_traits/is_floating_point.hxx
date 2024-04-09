#ifndef HXX_SB_TYPE_TRAITS_IS_FLOATING_POINT
#define HXX_SB_TYPE_TRAITS_IS_FLOATING_POINT

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/type_traits/remove_cv.hxx"
#include "sb/types.hxx"

namespace sb {
namespace detail {
template<typename T> struct is_floating_point_helper: false_type {};
template<> struct is_floating_point_helper<float>: true_type {};
template<> struct is_floating_point_helper<double>: true_type {};
template<> struct is_floating_point_helper<long double>: true_type {};
#if defined(SB_HAS_GNUC_FLOAT128)
template<> struct is_floating_point_helper<__float128>: true_type {};
#endif
} // namespace detail
template<typename T> struct is_floating_point: detail::is_floating_point_helper<typename remove_cv<T>::type>::type {};
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_FLOATING_POINT
