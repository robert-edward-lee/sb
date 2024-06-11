#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A {};

class B {};

enum E {};

union U {
    class UC {};
};

int main(void) {
    assert(is_class<A>::value);
    assert(is_class<B>::value);
    assert(!is_class<B *>::value);
    assert(!is_class<B &>::value);
    assert(is_class<const B>::value);
    assert(!is_class<E>::value);
    assert(!is_class<int>::value);
    assert(!is_class<U>::value);
    assert(is_class<U::UC>::value);
    return 0;
}
