#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};

int main(void) {
    assert(is_fundamental<int>::value);
    assert(!is_fundamental<int &>::value);
    assert(!is_fundamental<int *>::value);
    assert(is_fundamental<void>::value);
    assert(!is_fundamental<void *>::value);
    assert(is_fundamental<float>::value);
    assert(!is_fundamental<float &>::value);
    assert(!is_fundamental<float *>::value);
    assert(!is_fundamental<is_fundamental<int> >::value);
    assert(!is_fundamental<A>::value);
    assert(is_fundamental<is_fundamental<A>::value_type>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(is_fundamental<std::nullptr_t>::value);
#endif
    return 0;
}
