#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<int, int>::value));
    assert((!is_same<int, int *>::value));
    assert((!is_same<int, int **>::value));
    assert((is_same<int, remove_pointer<int>::type>::value));
    assert((is_same<int, remove_pointer<int *>::type>::value));
    assert((!is_same<int, remove_pointer<int **>::type>::value));
    assert((is_same<int, remove_pointer<int *const>::type>::value));
    assert((is_same<int, remove_pointer<int *volatile>::type>::value));
    assert((is_same<int, remove_pointer<int *const volatile>::type>::value));
    return 0;
}
