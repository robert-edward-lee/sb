#include "sb/type_traits.hxx"
#include "tests/common.hxx"

#if SB_CXX_VERSION_CHECK(201103)
struct S {
    void foo() const {}
    void bar() const {}
};
typedef void (S::*S_mem_fun_ptr)() const;
#endif

int main(void) {
    assert((is_same<const int *, int const *>::value));
    assert(!is_const<int>::value);
    assert(is_const<const int>::value);
    assert(!is_const<int *>::value);
    assert(is_const<int *const>::value);
    assert(!is_const<const int *>::value);
    assert(!is_const<const int &>::value);
    assert(is_const<remove_reference<const int &>::type>::value);
#if SB_CXX_VERSION_CHECK(201103)
    assert(!is_const<decltype(&S::foo)>::value);
    S_mem_fun_ptr sfp = &S::foo;
    sfp = &S::bar;
    assert(!is_const<decltype(sfp)>::value);
    const S_mem_fun_ptr csfp = &S::foo;
    assert(is_const<decltype(csfp)>::value);
#endif
    return 0;
}
