#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};
class B {
    int i;
};
enum C {};

int main(void) {
    assert(!is_signed<A>::value);
    assert(!is_signed<B>::value);
    assert(!is_signed<C>::value);
    assert(is_signed<signed int>::value);
    assert(is_signed<signed int>());
    assert(is_signed<signed int>::value);
    assert(!is_signed<unsigned int>::value);
    assert(is_signed<float>::value);
    assert(!is_signed<bool>::value);
    assert(is_signed<signed char>::value);
    assert(!is_signed<unsigned char>::value);
    return 0;
}
