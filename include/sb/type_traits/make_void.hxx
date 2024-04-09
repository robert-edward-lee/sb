#ifndef HXX_SB_TYPE_TRAITS_MAKE_VOID
#define HXX_SB_TYPE_TRAITS_MAKE_VOID

#include "sb/config.hxx"

namespace sb {
#if defined(SB_HAS_VARIADIC_TEMPLATES)
template<typename... Types> struct make_void {
    typedef void type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename... Types> using void_t = typename make_void<Types...>::type;
#endif
#else // SB_HAS_VARIADIC_TEMPLATES
template<typename A = void, typename B = void, typename C = void, typename D = void, typename E = void>
struct make_void {
    typedef void type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename A = void, typename B = void, typename C = void, typename D = void, typename E = void>
using void_t = typename make_void<A, B, C, D, E>::type;
#endif
#endif // SB_HAS_VARIADIC_TEMPLATES
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_MAKE_VOID
