#include "sb/type_traits.hxx"
#include "tests/common.hxx"

void f();
class C {};
union U {};
enum E { e };
struct S {
    int i: 8;
    int j;
    void foo();
};

int main(void) {
    assert(!is_compound<int>::value);
    assert(is_compound<int *>::value);
    assert(is_compound<int &>::value);
    assert(is_compound<char[100]>::value);
    assert(is_compound<C>::value);
    assert(is_compound<U>::value);
    assert(is_compound<E>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(is_compound<decltype(f)>::value);
    assert(is_compound<decltype(&f)>::value);
    assert(is_compound<decltype(E::e)>::value);
    assert(!is_compound<decltype(S::i)>::value);
    assert(!is_compound<decltype(S::j)>::value);
    assert(is_compound<decltype(&S::j)>::value);
    assert(is_compound<decltype(&S::foo)>::value);
#endif
    return 0;
}
