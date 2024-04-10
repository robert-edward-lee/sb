#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<int, int>::value == true));
    assert((is_same<int, int *>::value == false));
    assert((is_same<int, int **>::value == false));
    assert((is_same<int, remove_pointer<int>::type>::value == true));
    assert((is_same<int, remove_pointer<int *>::type>::value == true));
    assert((is_same<int, remove_pointer<int **>::type>::value == false));
    assert((is_same<int, remove_pointer<int *const>::type>::value == true));
    assert((is_same<int, remove_pointer<int *volatile>::type>::value == true));
    assert((is_same<int, remove_pointer<int *const volatile>::type>::value == true));
    return 0;
}
