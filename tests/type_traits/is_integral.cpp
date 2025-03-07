#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class A {};
struct B {
    int x: 4;
};

#if SB_CXX_VERSION_CHECK(201103)
enum E : int {};
using BF = decltype(B::x);
template<typename T> constexpr T same(T i) {
    return i;
}
#endif

int main(void) {

    assert(!is_integral<float>::value);
    assert(!is_integral<int *>::value);
    assert(is_integral<int>::value);
    assert(is_integral<const int>::value);
    assert(is_integral<bool>::value);
    assert(is_integral<char>::value);
    assert(!is_integral<A>::value);
    assert(!is_integral<B>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(!is_integral<E>::value);
    assert(is_integral<BF>::value == true);
    assert(same('"') == 042);
#endif
    return 0;
}
