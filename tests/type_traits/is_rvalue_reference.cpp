#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_rvalue_reference<A>::value == false);
    assert(is_rvalue_reference<char>::value == false);
    assert(is_rvalue_reference<A &>::value == false);
    assert(is_rvalue_reference<char &>::value == false);
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(is_rvalue_reference<A &&>::value == true);
    assert(is_rvalue_reference<char &&>::value == true);
#endif
    return 0;
}
