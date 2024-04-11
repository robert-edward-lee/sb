#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_array<A>::value == false);
    assert(is_array<A[]>::value == true);
    assert(is_array<A[3]>::value == true);
    assert(is_array<float>::value == false);
    assert(is_array<int>::value == false);
    assert(is_array<int[]>::value == true);
    assert(is_array<int[3]>::value == true);
    return 0;
}
