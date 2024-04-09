#include <cassert>
#include <iostream>

#include "sb/type_traits.hxx"

using namespace sb;

#define test_make_signed(T1, T2) assert((is_same<make_signed<T1>::type, T2>::value))

enum E {};

int main() {
    test_make_signed(char, signed char);
    test_make_signed(unsigned int, int);
    test_make_signed(volatile unsigned long, volatile long);

    test_make_signed(E, int);
    test_make_signed(const E, const int);
    test_make_signed(volatile E, volatile int);
    test_make_signed(const volatile E, const volatile int);

#if defined(SB_HAS_INT128)
    test_make_signed(__uint128_t, __int128_t);
    test_make_signed(__int128_t, __int128_t);
#endif

#if defined(_WIN32) || defined(_WIN64)
    test_make_signed(wchar_t, s16);
    test_make_signed(const wchar_t, const s16);
    test_make_signed(volatile wchar_t, volatile s16);
    test_make_signed(const volatile wchar_t, const volatile s16);
#else
    test_make_signed(wchar_t, s32);
    test_make_signed(const wchar_t, const s32);
    test_make_signed(volatile wchar_t, volatile s32);
    test_make_signed(const volatile wchar_t, const volatile s32);
#endif
}
