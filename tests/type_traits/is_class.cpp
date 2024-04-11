#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A {};

class B {};

enum E {};

union U {
    class UC {};
};

int main(void) {
    assert(is_class<A>::value == true);
    assert(is_class<B>::value == true);
    assert(is_class<B *>::value == false);
    assert(is_class<B &>::value == false);
    assert(is_class<const B>::value == true);
    assert(is_class<E>::value == false);
    assert(is_class<int>::value == false);
    assert(is_class<U>::value == false);
    assert(is_class<U::UC>::value == true);
    return 0;
}
