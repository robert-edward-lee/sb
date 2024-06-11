#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(!is_rvalue_reference<A>::value);
    assert(!is_rvalue_reference<char>::value);
    assert(!is_rvalue_reference<A &>::value);
    assert(!is_rvalue_reference<char &>::value);
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(is_rvalue_reference<A &&>::value);
    assert(is_rvalue_reference<char &&>::value);
#endif
    return 0;
}
