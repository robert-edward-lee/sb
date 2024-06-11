#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

enum B { e };

int main(void) {
    assert(is_arithmetic<bool>::value);
    assert(is_arithmetic<char>::value);
    assert(is_arithmetic<char const>::value);
    assert(is_arithmetic<int>::value);
    assert(is_arithmetic<int const>::value);
    assert(is_arithmetic<float>::value);
    assert(is_arithmetic<float const>::value);
    assert(is_arithmetic<size_t>::value);
    assert(!is_arithmetic<char &>::value);
    assert(!is_arithmetic<char *>::value);
    assert(!is_arithmetic<int &>::value);
    assert(!is_arithmetic<int *>::value);
    assert(!is_arithmetic<float &>::value);
    assert(!is_arithmetic<float *>::value);
    assert(!is_arithmetic<A>::value);
    assert(!is_arithmetic<B>::value);
    return 0;
}
