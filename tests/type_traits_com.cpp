#include "sb/type_traits.hxx"
#include "tests/common.hxx"

int main(void) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4101)
#endif
    add_cv<int> TEST_UNIQUE_NAME_UNUSED;
    add_const<int> TEST_UNIQUE_NAME_UNUSED;
    add_volatile<int> TEST_UNIQUE_NAME_UNUSED;
    add_pointer<int> TEST_UNIQUE_NAME_UNUSED;
    alignment_of<int> TEST_UNIQUE_NAME_UNUSED;
    conditional<0, int, int> TEST_UNIQUE_NAME_UNUSED;
    decay<int> TEST_UNIQUE_NAME_UNUSED;
    enable_if<0> TEST_UNIQUE_NAME_UNUSED;
    extent<int> TEST_UNIQUE_NAME_UNUSED;
    integral_constant<int, 0> TEST_UNIQUE_NAME_UNUSED;
    is_arithmetic<int> TEST_UNIQUE_NAME_UNUSED;
    is_array<int> TEST_UNIQUE_NAME_UNUSED;
    is_bounded_array<int> TEST_UNIQUE_NAME_UNUSED;
    is_char<int> TEST_UNIQUE_NAME_UNUSED;
    is_class<int> TEST_UNIQUE_NAME_UNUSED;
    is_compound<int> TEST_UNIQUE_NAME_UNUSED;
    is_const<int> TEST_UNIQUE_NAME_UNUSED;
    is_enum<int> TEST_UNIQUE_NAME_UNUSED;
    is_floating_point<int> TEST_UNIQUE_NAME_UNUSED;
    is_function<int> TEST_UNIQUE_NAME_UNUSED;
    is_fundamental<int> TEST_UNIQUE_NAME_UNUSED;
    is_integral<int> TEST_UNIQUE_NAME_UNUSED;
    is_lvalue_reference<int> TEST_UNIQUE_NAME_UNUSED;
    is_member_pointer<int> TEST_UNIQUE_NAME_UNUSED;
    is_null_pointer<int> TEST_UNIQUE_NAME_UNUSED;
    is_object<int> TEST_UNIQUE_NAME_UNUSED;
    is_pointer<int> TEST_UNIQUE_NAME_UNUSED;
    is_reference<int> TEST_UNIQUE_NAME_UNUSED;
    is_same<int, int> TEST_UNIQUE_NAME_UNUSED;
    is_scalar<int> TEST_UNIQUE_NAME_UNUSED;
    is_signed<int> TEST_UNIQUE_NAME_UNUSED;
    is_unbounded_array<int> TEST_UNIQUE_NAME_UNUSED;
    is_union<int> TEST_UNIQUE_NAME_UNUSED;
    is_unsigned<int> TEST_UNIQUE_NAME_UNUSED;
    is_void<int> TEST_UNIQUE_NAME_UNUSED;
    is_volatile<int> TEST_UNIQUE_NAME_UNUSED;
    make_signed<int> TEST_UNIQUE_NAME_UNUSED;
    make_unsigned<int> TEST_UNIQUE_NAME_UNUSED;
    make_void<int> TEST_UNIQUE_NAME_UNUSED;
    rank<int> TEST_UNIQUE_NAME_UNUSED;
    remove_all_extents<int> TEST_UNIQUE_NAME_UNUSED;
    remove_cv<int> TEST_UNIQUE_NAME_UNUSED;
    remove_extent<int> TEST_UNIQUE_NAME_UNUSED;
    remove_pointer<int> TEST_UNIQUE_NAME_UNUSED;
    remove_reference<int> TEST_UNIQUE_NAME_UNUSED;
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
    return 0;
}
