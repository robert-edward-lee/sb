#ifndef HXX_SB_TYPE_TRAITS_INTEGRAL_CONSTANT
#define HXX_SB_TYPE_TRAITS_INTEGRAL_CONSTANT

#include "sb/config.hxx"

namespace sb {
template<typename T, T v> struct integral_constant {
    static SB_CONST_OR_CONSTEXPR T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    SB_CONSTEXPR operator value_type() const SB_NOEXCEPT {
        return value;
    }
    SB_CONSTEXPR value_type operator()() const SB_NOEXCEPT {
        return value;
    }
};
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;
} // namespace sb

#endif // HXX_SB_TYPE_TRAITS_INTEGRAL_CONSTANT
