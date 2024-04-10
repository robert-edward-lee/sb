#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert((is_same<int, remove_reference<int>::type>::value));
    assert((is_same<int, remove_reference<int &>::type>::value));
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert((is_same<int, remove_reference<int &&>::type>::value));
#endif
    assert((is_same<const int, remove_reference<const int &>::type>::value));
    return 0;
}
