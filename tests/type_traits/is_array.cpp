#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(!is_array<A>::value);
    assert(is_array<A[]>::value);
    assert(is_array<A[3]>::value);
    assert(!is_array<float>::value);
    assert(!is_array<int>::value);
    assert(is_array<int[]>::value);
    assert(is_array<int[3]>::value);
    return 0;
}
