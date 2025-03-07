#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A {
    enum E {};
};
enum E {};
#if SB_CXX_VERSION_CHECK(201103)
enum class Ec : int {};
#endif

int main(void) {
    assert(!is_enum<A>::value);
    assert(is_enum<A::E>::value);
    assert(is_enum<E>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(is_enum<Ec>::value);
#endif
    assert(!is_enum<int>::value);
    return 0;
}
