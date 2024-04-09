#ifndef HXX_SB_TYPE_TRAITS_IS_RVALUE_REFERENCE
#define HXX_SB_TYPE_TRAITS_IS_RVALUE_REFERENCE

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"

namespace sb {
template<typename T> struct is_rvalue_reference: false_type {};
#if defined(SB_HAS_RVALUE_REFERENCES)
template<typename T> struct is_rvalue_reference<T &&>: true_type {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_IS_RVALUE_REFERENCE
