#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_reference<A>::value == false);
    assert(is_reference<A &>::value == true);
    assert(is_reference<long>::value == false);
    assert(is_reference<long &>::value == true);
    assert(is_reference<double *>::value == false);
    assert(is_reference<double *&>::value == true);
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(is_reference<long &&>::value == true);
    assert(is_reference<A &&>::value == true);
    assert(is_reference<double *&&>::value == true);
#endif
    return 0;
}
