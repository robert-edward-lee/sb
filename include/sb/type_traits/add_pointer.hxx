#ifndef HXX_SB_TYPE_TRAITS_ADD_POINTER
#define HXX_SB_TYPE_TRAITS_ADD_POINTER

#include "sb/config.hxx"
#include "sb/type_traits/remove_reference.hxx"

namespace sb {
template<typename T> struct add_pointer {
    typedef typename remove_reference<T>::type no_ref_type;
    typedef no_ref_type *type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using add_pointer_t = typename add_pointer<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_ADD_POINTER
