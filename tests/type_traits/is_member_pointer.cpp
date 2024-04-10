#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class C {};

int main(void) {
    assert(is_member_pointer<int(C::*)>::value);
    assert(!is_member_pointer<int>::value);
    return 0;
}
