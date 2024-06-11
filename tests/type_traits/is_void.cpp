#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(is_void<void>::value);
    assert(is_void<const void>::value);
    assert(is_void<volatile void>::value);
    assert(!is_void<void *>::value);
    assert(!is_void<int>::value);
    assert(!is_void<void()>::value);
    assert(!is_void<is_void<void> >::value);
    return 0;
}
