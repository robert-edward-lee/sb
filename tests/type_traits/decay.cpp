#include "sb/type_traits.hxx"
#include "tests/common.hxx"

#if defined(SB_HAS_ALIAS_TEMPLATES)
#define decay_test(T1, T2) is_same<decay_t<T1>, T2>::value
#else
#define decay_test(T1, T2) is_same<decay<T1>::type, T2>::value
#endif

int main(void) {
    assert(decay_test(int, int));
    assert(!decay_test(int, float));
    assert(decay_test(int &, int));
#if defined(SB_HAS_RVALUE_REFERENCES)
    assert(decay_test(int &&, int));
#endif
    assert(decay_test(const int &, int));
    assert(decay_test(int[2], int *));
    assert(!decay_test(int[4][2], int *));
    assert(!decay_test(int[4][2], int **));
    assert(decay_test(int[4][2], int(*)[2]));
    assert(decay_test(int(int), int (*)(int)));
    return 0;
}
