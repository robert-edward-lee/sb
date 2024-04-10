#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(!is_null_pointer<int *>::value);
    assert(is_pointer<int *>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(!is_pointer<decltype(nullptr)>::value);
    assert(is_null_pointer<decltype(nullptr)>::value);
#endif
    return 0;
}
