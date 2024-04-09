#ifndef HXX_SB_TYPE_TRAITS_ADD_CV
#define HXX_SB_TYPE_TRAITS_ADD_CV

#include "sb/config.hxx"

namespace sb {
template<typename T> struct add_cv {
    typedef const volatile T type;
};
template<typename T> struct add_const {
    typedef const T type;
};
template<typename T> struct add_volatile {
    typedef volatile T type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using add_cv_t = typename add_cv<T>::type;
template<typename T> using add_const_t = typename add_const<T>::type;
template<typename T> using add_volatile_t = typename add_volatile<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_ADD_CV
