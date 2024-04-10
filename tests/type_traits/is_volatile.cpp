#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(!is_volatile<int>::value);
    assert(is_volatile<volatile int>::value);
    assert(is_volatile<volatile const int>::value);
    return 0;
}
