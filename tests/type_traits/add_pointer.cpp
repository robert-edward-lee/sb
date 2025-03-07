#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<int *, add_pointer<int>::type>::value));
    assert((is_same<int *, add_pointer<int &>::type>::value));
#if defined(SB_HAS_ALIAS_TEMPLATES)
    assert((is_same<int *, add_pointer_t<int> >::value));
    assert((is_same<int *, add_pointer_t<int &> >::value));
#endif
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert((is_same<int *, add_pointer<int &&>::type>::value));
#if defined(SB_HAS_ALIAS_TEMPLATES)
    assert((is_same<int *, add_pointer_t<int &&> >::value));
#endif
#endif
    return 0;
}
