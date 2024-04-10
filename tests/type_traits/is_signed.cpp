#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};
class B {
    int i;
};
enum C {};

int main(void) {
    assert(is_signed<A>::value == false);
    assert(is_signed<B>::value == false);
    assert(is_signed<C>::value == false);
    assert(is_signed<signed int>::value == true);
    assert(is_signed<signed int>() == true);
    assert(is_signed<signed int>::value == true);
    assert(is_signed<unsigned int>::value == false);
    // assert(is_signed<float>::value == true); TODO: float!
    assert(is_signed<bool>::value == false);
    assert(is_signed<signed char>::value == true);
    assert(is_signed<unsigned char>::value == false);
    return 0;
}
