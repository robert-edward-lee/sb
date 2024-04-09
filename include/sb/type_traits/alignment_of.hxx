#ifndef HXX_SB_TYPE_TRAITS_ALIGNMENT_OF
#define HXX_SB_TYPE_TRAITS_ALIGNMENT_OF

#include "sb/config.hxx"
#include "sb/type_traits/integral_constant.hxx"
#include "sb/types.hxx"

namespace sb {
#if defined(__GNUC__)
template<typename T> struct alignment_of: integral_constant<size_t, __alignof__(T)> {};
#elif defined(_MSC_VER)
template<typename T> struct alignment_of: integral_constant<size_t, __alignof(T)> {};
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_ALIGNMENT_OF
