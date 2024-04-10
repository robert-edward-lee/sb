#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct X {
    int m;
};

int main(void) {
    assert((is_same<remove_all_extents<float>::type, float>::value));
    assert((is_same<remove_all_extents<float[1][2][3]>::type, float>::value));
    assert((is_same<remove_all_extents<float[1][1][1][1][2]>::type, float>::value));
    assert((is_same<remove_all_extents<float *>::type, float *>::value));
    assert((is_same<remove_all_extents<int[3][2]>::type, int>::value));
    assert((is_same<remove_all_extents<double[2][3]>::type, double>::value));
    assert((is_same<remove_all_extents<X[3][3]>::type, X>::value));
    return 0;
}
