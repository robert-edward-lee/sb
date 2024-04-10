#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};
class B {
    int i;
};
enum C {};

int main(void) {
    assert((is_same<float, s32>::value == false));
    assert((is_same<int, int>::value == true));
    assert((is_same<int, unsigned int>::value == false));
    assert((is_same<int, signed int>::value == true));
    assert((is_same<char, char>::value == true));
    assert((is_same<char, unsigned char>::value == false));
    assert((is_same<char, signed char>::value == false));
    assert((!is_same<const int, int>()));
    return 0;
}
