#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((extent<int[3]>::value == 3));
    assert((extent<int[3], 0>::value == 3));
    assert((extent<int[3][4], 0>::value == 3));
    assert((extent<int[3][4], 1>::value == 4));
    assert((extent<int[3][4], 2>::value == 0));
    assert((extent<int[]>::value == 0));
    assert((extent<int>::value == 0));
    return 0;
}
