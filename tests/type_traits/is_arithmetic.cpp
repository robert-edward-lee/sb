#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

enum B { e };

int main(void) {
    assert(is_arithmetic<bool>::value == true);
    assert(is_arithmetic<char>::value == true);
    assert(is_arithmetic<char const>::value == true);
    assert(is_arithmetic<int>::value == true);
    assert(is_arithmetic<int const>::value == true);
    assert(is_arithmetic<float>::value == true);
    assert(is_arithmetic<float const>::value == true);
    assert(is_arithmetic<size_t>::value == true);
    assert(is_arithmetic<char &>::value == false);
    assert(is_arithmetic<char *>::value == false);
    assert(is_arithmetic<int &>::value == false);
    assert(is_arithmetic<int *>::value == false);
    assert(is_arithmetic<float &>::value == false);
    assert(is_arithmetic<float *>::value == false);
    assert(is_arithmetic<A>::value == false);
    assert(is_arithmetic<B>::value == false);
    return 0;
}
