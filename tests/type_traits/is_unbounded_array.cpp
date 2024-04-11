#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_unbounded_array<A>::value == false);
    assert(is_unbounded_array<A[]>::value == true);
    assert(is_unbounded_array<A[3]>::value == false);
    assert(is_unbounded_array<float>::value == false);
    assert(is_unbounded_array<int>::value == false);
    assert(is_unbounded_array<int[]>::value == true);
    assert(is_unbounded_array<int[3]>::value == false);
    return 0;
}
