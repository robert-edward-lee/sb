#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A {
    int m;
    void f() {}
};

int A::*mem_data_ptr = &A::m;
void (A::*mem_fun_ptr)() = &A::f;

int main(void) {
    assert(!is_pointer<A>::value);
    assert(!is_pointer<A>::value);
    assert(!is_pointer<A>());
    assert(!is_pointer<A>()());
    assert(is_pointer<A *>::value);
    assert(is_pointer<A const *volatile>::value);
    assert(!is_pointer<A &>::value);
    assert(is_pointer<void *>::value);
    assert(!is_pointer<int>::value);
    assert(is_pointer<int *>::value);
    assert(is_pointer<int **>::value);
    assert(!is_pointer<int[10]>::value);
    assert(is_pointer<void (*)()>::value);
#if defined(__GNUC__)
    assert(!is_pointer<__typeof__(mem_data_ptr)>::value);
    assert(!is_pointer<__typeof__(mem_fun_ptr)>::value);
#endif
#if SB_CXX_VERSION_CHECK(201103)
    assert(!is_pointer<nullptr_t>::value);
#endif
    return 0;
}
