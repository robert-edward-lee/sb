#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(rank<int>::value == 0);
    assert(rank<int[5]>::value == 1);
    assert(rank<int[5][5]>::value == 2);
    assert(rank<int[][5][5]>::value == 3);
    return 0;
}
