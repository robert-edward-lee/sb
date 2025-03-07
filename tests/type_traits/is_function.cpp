#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int f();
struct O {
    void operator()() {}
};
struct A {
    static int foo();
    int fun() const
#if SB_CXX_VERSION_CHECK(201103)
        &
#endif
        ;
};

int main(void) {
    assert(is_function<int(int)>::value);
    assert(!is_function<int>::value);
#if 0
    assert(!is_function<function<void()> >::value);
#endif
    assert(is_function<O()>::value);
    assert(!is_function<A>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(is_function<decltype(f)>::value);
    assert(is_function<decltype(A::foo)>::value);
    assert(!is_function<decltype(&A::fun)>::value);
#endif
#if SB_CXX_VERSION_CHECK(202002)
    assert(!is_function<decltype([] {})>::value);
#endif
    return 0;
}
