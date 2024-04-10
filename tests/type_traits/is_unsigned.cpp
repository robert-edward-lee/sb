#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};
enum B {};
struct S {
    unsigned p: 1;
    int q: 1;
};

int main(void) {
    assert(is_unsigned<A>::value == false);
    assert(is_unsigned<B>::value == false);
#if defined(__GNUC__)
    assert(is_unsigned<__typeof__(S::p)>::value != is_unsigned<__typeof__(S::q)>::value);
#endif
    // assert(is_unsigned<float>::value == false); TODO: добавить float
    assert(is_unsigned<signed int>::value == false);
    assert(is_unsigned<unsigned int>::value == true);
    assert(is_unsigned<bool>::value == true);
    return 0;
}
