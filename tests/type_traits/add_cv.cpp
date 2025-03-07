#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<const volatile int, add_cv<int>::type>::value));
    assert((is_same<const int, add_const<int>::type>::value));
    assert((is_same<volatile int, add_volatile<int>::type>::value));
#if defined(SB_HAS_ALIAS_TEMPLATES)
    assert((is_same<const volatile int, add_cv_t<int> >::value));
    assert((is_same<const int, add_const_t<int> >::value));
    assert((is_same<volatile int, add_volatile_t<int> >::value));
#endif
    return 0;
}
