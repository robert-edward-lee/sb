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
    assert(is_union<A>::value == false);
    assert(is_union<B>::value == true);
    assert(is_union<C>::value == false);
    assert(is_union<int>::value == false);
    return 0;
}
