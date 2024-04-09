#ifndef HXX_SB_TYPE_TRAITS_DECAY
#define HXX_SB_TYPE_TRAITS_DECAY

#include "sb/config.hxx"
#include "sb/type_traits/add_pointer.hxx"
#include "sb/type_traits/conditional.hxx"
#include "sb/type_traits/is_array.hxx"
#include "sb/type_traits/is_function.hxx"
#include "sb/type_traits/remove_cv.hxx"
#include "sb/type_traits/remove_extent.hxx"

namespace sb {
template<typename T> struct decay {
private:
    typedef typename remove_reference<T>::type U;
public:
    typedef typename conditional<
        is_array<U>::value,
        typename add_pointer<typename remove_extent<U>::type>::type,
        typename conditional<is_function<U>::value, typename add_pointer<U>::type, typename remove_cv<U>::type>::type>::
        type type;
};
#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using decay_t = typename decay<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_DECAY
