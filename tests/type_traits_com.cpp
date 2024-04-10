#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
    add_cv<int> UNIQUE_NAME;
    add_const<int> UNIQUE_NAME;
    add_volatile<int> UNIQUE_NAME;
    add_pointer<int> UNIQUE_NAME;
    alignment_of<int> UNIQUE_NAME;
    conditional<0, int, int> UNIQUE_NAME;
    decay<int> UNIQUE_NAME;
    enable_if<0> UNIQUE_NAME;
    extent<int> UNIQUE_NAME;
    integral_constant<int, 0> UNIQUE_NAME;
    is_arithmetic<int> UNIQUE_NAME;
    is_array<int> UNIQUE_NAME;
    is_bounded_array<int> UNIQUE_NAME;
    is_char<int> UNIQUE_NAME;
    is_class<int> UNIQUE_NAME;
    is_compound<int> UNIQUE_NAME;
    is_const<int> UNIQUE_NAME;
    is_enum<int> UNIQUE_NAME;
    is_floating_point<int> UNIQUE_NAME;
    is_function<int> UNIQUE_NAME;
    is_fundamental<int> UNIQUE_NAME;
    is_integral<int> UNIQUE_NAME;
    is_lvalue_reference<int> UNIQUE_NAME;
    is_member_pointer<int> UNIQUE_NAME;
    is_null_pointer<int> UNIQUE_NAME;
    is_object<int> UNIQUE_NAME;
    is_pointer<int> UNIQUE_NAME;
    is_reference<int> UNIQUE_NAME;
    is_same<int, int> UNIQUE_NAME;
    is_scalar<int> UNIQUE_NAME;
    is_signed<int> UNIQUE_NAME;
    is_unbounded_array<int> UNIQUE_NAME;
    is_union<int> UNIQUE_NAME;
    is_unsigned<int> UNIQUE_NAME;
    is_void<int> UNIQUE_NAME;
    is_volatile<int> UNIQUE_NAME;
    make_signed<int> UNIQUE_NAME;
    make_unsigned<int> UNIQUE_NAME;
    make_void<int> UNIQUE_NAME;
    rank<int> UNIQUE_NAME;
    remove_all_extents<int> UNIQUE_NAME;
    remove_cv<int> UNIQUE_NAME;
    remove_extent<int> UNIQUE_NAME;
    remove_pointer<int> UNIQUE_NAME;
    remove_reference<int> UNIQUE_NAME;
    return 0;
}
