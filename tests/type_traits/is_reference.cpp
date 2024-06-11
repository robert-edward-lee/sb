#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(!is_reference<A>::value);
    assert(is_reference<A &>::value);
    assert(!is_reference<long>::value);
    assert(is_reference<long &>::value);
    assert(!is_reference<double *>::value);
    assert(is_reference<double *&>::value);
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(is_reference<long &&>::value);
    assert(is_reference<A &&>::value);
    assert(is_reference<double *&&>::value);
#endif
    return 0;
}
