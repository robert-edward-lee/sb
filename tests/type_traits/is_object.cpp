#include "sb/type_traits.hxx"
#include "tests/common.hxx"

class cls {};

int main(void) {
    assert(!is_object<void>::value);
    assert(is_object<int>::value);
    assert(!is_object<int &>::value);
    assert(is_object<int *>::value);
    assert(!is_object<int *&>::value);
    assert(is_object<cls>::value);
    assert(!is_object<cls &>::value);
    assert(is_object<cls *>::value);
    assert(!is_object<int()>::value);
    assert(is_object<int (*)()>::value);
    assert(!is_object<int (&)()>::value);
    return 0;
}
