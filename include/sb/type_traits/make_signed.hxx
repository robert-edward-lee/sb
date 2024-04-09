#ifndef HXX_SB_TYPE_TRAITS_MAKE_SIGNED
#define HXX_SB_TYPE_TRAITS_MAKE_SIGNED

#include "sb/config.hxx"
#include "sb/type_traits/conditional.hxx"
#include "sb/type_traits/detail/cv_selector.hxx"
#include "sb/type_traits/is_char.hxx"
#include "sb/type_traits/is_const.hxx"
#include "sb/type_traits/is_enum.hxx"
#include "sb/type_traits/is_volatile.hxx"
#include "sb/type_traits/remove_cv.hxx"
#include "sb/types.hxx"

namespace sb {
namespace detail {
template<typename T> struct make_signed_typed_helper {
    typedef void type;
};
template<> struct make_signed_typed_helper<unsigned char> {
    typedef signed char type;
};
template<> struct make_signed_typed_helper<signed char> {
    typedef signed char type;
};
template<> struct make_signed_typed_helper<unsigned short> {
    typedef signed short type;
};
template<> struct make_signed_typed_helper<signed short> {
    typedef signed short type;
};
template<> struct make_signed_typed_helper<unsigned int> {
    typedef signed int type;
};
template<> struct make_signed_typed_helper<signed int> {
    typedef signed int type;
};
template<> struct make_signed_typed_helper<unsigned long> {
    typedef signed long type;
};
template<> struct make_signed_typed_helper<signed long> {
    typedef signed long type;
};
#if defined(SB_HAS_LONG_LONG)
template<> struct make_signed_typed_helper<unsigned long long> {
    typedef signed long long type;
};
template<> struct make_signed_typed_helper<signed long long> {
    typedef signed long long type;
};
#elif defined(__GNUC__)
__extension__ template<> struct make_signed_typed_helper<unsigned long long> {
    typedef signed long long type;
};
__extension__ template<> struct make_signed_typed_helper<signed long long> {
    typedef signed long long type;
};
#elif defined(SB_HAS_MSVC_INT64)
template<> struct make_signed_typed_helper<unsigned __int64> {
    typedef signed __int64 type;
};
template<> struct make_signed_typed_helper<signed __int64> {
    typedef signed __int64 type;
};
#endif
#if defined(SB_HAS_GNUC_INT128)
template<> struct make_signed_typed_helper<__uint128_t> {
    typedef __int128_t type;
};
template<> struct make_signed_typed_helper<__int128_t> {
    typedef __int128_t type;
};
#endif

template<size_t S> struct make_signed_sized_helper {
    typedef void type;
};
template<> struct make_signed_sized_helper<1> {
    typedef s8 type;
};
template<> struct make_signed_sized_helper<2> {
    typedef s16 type;
};
template<> struct make_signed_sized_helper<4> {
    typedef s32 type;
};
#if defined(SB_HAS_INT64)
template<> struct make_signed_sized_helper<8> {
    typedef s64 type;
};
#endif
#if defined(SB_HAS_INT128)
template<> struct make_signed_sized_helper<16> {
    typedef s128 type;
};
#endif
template<typename T> class make_signed_helper {
    typedef typename conditional<is_enum<T>::value || is_char<T>::value,
                                 typename make_signed_sized_helper<sizeof(T)>::type,
                                 typename make_signed_typed_helper<typename remove_cv<T>::type>::type>::type pure_type;
public:
    typedef typename cv_selector<pure_type, is_const<T>::value, is_volatile<T>::value>::type type;
};
} // namespace detail

template<typename T> struct make_signed: detail::make_signed_helper<T> {};

#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using make_signed_t = typename make_signed<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_MAKE_SIGNED
