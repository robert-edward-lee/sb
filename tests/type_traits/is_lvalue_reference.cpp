#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_lvalue_reference<A>::value == false);
    assert(is_lvalue_reference<char>::value == false);
    assert(is_lvalue_reference<A &>::value == true);
    assert(is_lvalue_reference<char &>::value == true);
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(is_lvalue_reference<A &&>::value == false);
    assert(is_lvalue_reference<char &&>::value == false);
#endif
    return 0;
}
