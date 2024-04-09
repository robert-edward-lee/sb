#ifndef HXX_SB_TYPE_TRAITS_ENABLE_IF
#define HXX_SB_TYPE_TRAITS_ENABLE_IF

#include "sb/config.hxx"

namespace sb {
template<bool Cond, typename T = void> struct enable_if {};
template<typename T> struct enable_if<true, T> {
    typedef T type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<bool Cond, typename Type = void> using enable_if_t = typename enable_if<Cond, Type>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_ENABLE_IF
