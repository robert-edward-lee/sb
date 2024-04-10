#include "sb/type_traits.hxx"
#include "tests/common.hxx"

#define test_make_unsigned(T1, T2) assert((is_same<make_unsigned<T1>::type, T2>::value))

enum E {};

int main() {
    test_make_unsigned(char, unsigned char);
    test_make_unsigned(int, unsigned int);
    test_make_unsigned(volatile long, volatile unsigned long);

    test_make_unsigned(E, unsigned int);
    test_make_unsigned(const E, const unsigned int);
    test_make_unsigned(volatile E, volatile unsigned int);
    test_make_unsigned(const volatile E, const volatile unsigned int);

#if defined(SB_HAS_INT128)
    test_make_unsigned(__uint128_t, __uint128_t);
    test_make_unsigned(__int128_t, __uint128_t);
#endif

#if defined(_WIN32) || defined(_WIN64)
    test_make_unsigned(wchar_t, u16);
    test_make_unsigned(const wchar_t, const u16);
    test_make_unsigned(volatile wchar_t, volatile u16);
    test_make_unsigned(const volatile wchar_t, const volatile u16);
#else
    test_make_unsigned(wchar_t, u32);
    test_make_unsigned(const wchar_t, const u32);
    test_make_unsigned(volatile wchar_t, volatile u32);
    test_make_unsigned(const volatile wchar_t, const volatile u32);
#endif
}
