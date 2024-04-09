#ifndef HXX_SB_TYPE_TRAITS_MAKE_UNSIGNED
#define HXX_SB_TYPE_TRAITS_MAKE_UNSIGNED

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
template<typename T> struct make_unsigned_typed_helper {
    typedef void type;
};
template<> struct make_unsigned_typed_helper<unsigned char> {
    typedef unsigned char type;
};
template<> struct make_unsigned_typed_helper<signed char> {
    typedef unsigned char type;
};
template<> struct make_unsigned_typed_helper<unsigned short> {
    typedef unsigned short type;
};
template<> struct make_unsigned_typed_helper<signed short> {
    typedef unsigned short type;
};
template<> struct make_unsigned_typed_helper<unsigned int> {
    typedef unsigned int type;
};
template<> struct make_unsigned_typed_helper<signed int> {
    typedef unsigned int type;
};
template<> struct make_unsigned_typed_helper<unsigned long> {
    typedef unsigned long type;
};
template<> struct make_unsigned_typed_helper<signed long> {
    typedef unsigned long type;
};
#if defined(SB_HAS_LONG_LONG)
template<> struct make_unsigned_typed_helper<unsigned long long> {
    typedef unsigned long long type;
};
template<> struct make_unsigned_typed_helper<signed long long> {
    typedef unsigned long long type;
};
#elif defined(__GNUC__)
__extension__ template<> struct make_unsigned_typed_helper<unsigned long long> {
    typedef unsigned long long type;
};
__extension__ template<> struct make_unsigned_typed_helper<signed long long> {
    typedef unsigned long long type;
};
#elif defined(SB_HAS_MSVC_INT64)
template<> struct make_unsigned_typed_helper<unsigned __int64> {
    typedef unsigned __int64 type;
};
template<> struct make_unsigned_typed_helper<signed __int64> {
    typedef unsigned __int64 type;
};
#endif
#if defined(SB_HAS_GNUC_INT128)
template<> struct make_unsigned_typed_helper<__uint128_t> {
    typedef __uint128_t type;
};
template<> struct make_unsigned_typed_helper<__int128_t> {
    typedef __uint128_t type;
};
#endif

template<size_t S> struct make_unsigned_sized_helper {
    typedef void type;
};
template<> struct make_unsigned_sized_helper<1> {
    typedef u8 type;
};
template<> struct make_unsigned_sized_helper<2> {
    typedef u16 type;
};
template<> struct make_unsigned_sized_helper<4> {
    typedef u32 type;
};
#if defined(SB_HAS_INT64)
template<> struct make_unsigned_sized_helper<8> {
    typedef u64 type;
};
#endif
#if defined(SB_HAS_INT128)
template<> struct make_unsigned_sized_helper<16> {
    typedef u128 type;
};
#endif
template<typename T> class make_unsigned_helper {
    typedef typename conditional<is_enum<T>::value || is_char<T>::value,
                             typename make_unsigned_sized_helper<sizeof(T)>::type,
                             typename make_unsigned_typed_helper<typename remove_cv<T>::type>::type>::type pure_type;
public:
    typedef typename cv_selector<pure_type, is_const<T>::value, is_volatile<T>::value>::type type;
};
} // namespace detail

template<typename T> struct make_unsigned: detail::make_unsigned_helper<T> {};

#if defined(SB_HAS_ALIAS_TEMPLATES)
template<typename T> using make_unsigned_t = typename make_unsigned<T>::type;
#endif
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_MAKE_UNSIGNED
