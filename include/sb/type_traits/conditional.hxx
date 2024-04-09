#ifndef HXX_SB_TYPE_TRAITS_CONDITIONAL
#define HXX_SB_TYPE_TRAITS_CONDITIONAL

#include "sb/config.hxx"

namespace sb {
template<bool Cond, class T1, class T2> struct conditional {
    typedef T1 type;
};
template<class T1, class T2> struct conditional<false, T1, T2> {
    typedef T2 type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<bool Cond, class T1, class T2> using conditional_t = typename conditional<Cond, T1, T2>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_CONDITIONAL
