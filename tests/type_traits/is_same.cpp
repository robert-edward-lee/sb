#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((!is_same<float, s32>::value));
    assert((is_same<int, int>::value));
    assert((!is_same<int, unsigned int>::value));
    assert((is_same<int, signed int>::value));
    assert((is_same<char, char>::value));
    assert((!is_same<char, unsigned char>::value));
    assert((!is_same<char, signed char>::value));
    assert((!is_same<const int, int>()));
    return 0;
}
