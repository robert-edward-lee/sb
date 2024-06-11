#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A {};

typedef union {
    int a;
    float b;
} B;

struct C {
    B d;
};

int main(void) {
    assert(!is_union<A>::value);
    assert(is_union<B>::value);
    assert(!is_union<C>::value);
    assert(!is_union<int>::value);
    return 0;
}
