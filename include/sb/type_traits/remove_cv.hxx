#ifndef HXX_SB_TYPE_TRAITS_REMOVE_CV
#define HXX_SB_TYPE_TRAITS_REMOVE_CV

#include "sb/config.hxx"

namespace sb {
template<typename T> struct remove_cv {
    typedef T type;
};
template<typename T> struct remove_cv<const T> {
    typedef T type;
};
template<typename T> struct remove_cv<volatile T> {
    typedef T type;
};
template<typename T> struct remove_cv<const volatile T> {
    typedef T type;
};

template<typename T> struct remove_const {
    typedef T type;
};
template<typename T> struct remove_const<const T> {
    typedef T type;
};

template<typename T> struct remove_volatile {
    typedef T type;
};
template<typename T> struct remove_volatile<volatile T> {
    typedef T type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using remove_cv_t = typename remove_cv<T>::type;
template<typename T> using remove_const_t = typename remove_const<T>::type;
template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_REMOVE_CV
