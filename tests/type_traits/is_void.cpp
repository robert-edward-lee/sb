#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(is_void<void>::value == true);
    assert(is_void<const void>::value == true);
    assert(is_void<volatile void>::value == true);
    assert(is_void<void *>::value == false);
    assert(is_void<int>::value == false);
    assert(is_void<void()>::value == false);
    assert(is_void<is_void<void> >::value == false);
    return 0;
}
