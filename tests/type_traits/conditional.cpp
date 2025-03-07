#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<int, conditional<1, int, void>::type>::value));
    assert((is_same<void, conditional<0, int, void>::type>::value));
#if defined(SB_HAS_ALIAS_TEMPLATES)
    assert((is_same<int, conditional_t<1, int, void> >::value));
    assert((is_same<void, conditional_t<0, int, void> >::value));
#endif
    return 0;
}
