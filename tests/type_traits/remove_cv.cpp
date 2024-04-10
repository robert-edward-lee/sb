#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<remove_cv<int>::type, int>::value));
    assert((is_same<remove_cv<const int>::type, int>::value));
    assert((is_same<remove_cv<volatile int>::type, int>::value));
    assert((is_same<remove_cv<const volatile int>::type, int>::value));
    assert((!is_same<remove_cv<const volatile int *>::type, int *>::value));
    assert((is_same<remove_cv<const volatile int *>::type, const volatile int *>::value));
    assert((is_same<remove_cv<const int *volatile>::type, const int *>::value));
    assert((is_same<remove_cv<int *const volatile>::type, int *>::value));
    return 0;
}
