#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(!is_floating_point<A>::value);
    assert(is_floating_point<float>::value);
    assert(!is_floating_point<float &>::value);
    assert(is_floating_point<double>::value);
    assert(!is_floating_point<double &>::value);
    assert(!is_floating_point<int>::value);
    return 0;
}
