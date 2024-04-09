#ifndef HXX_SB_TYPE_TRAITS_REMOVE_REFERENCE
#define HXX_SB_TYPE_TRAITS_REMOVE_REFERENCE

#include "sb/config.hxx"

namespace sb {
template<typename T> struct remove_reference {
    typedef T type;
};
template<typename T> struct remove_reference<T &> {
    typedef T type;
};
#if defined(SB_HAS_RVALUE_REFERENCES)
template<typename T> struct remove_reference<T &&> {
    typedef T type;
};
#endif
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using remove_reference_t = typename remove_reference<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_REMOVE_REFERENCE
