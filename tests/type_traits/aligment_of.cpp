#include "sb/type_traits.hxx"
#include "tests/common.hxx"

struct A1 {
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
    u8 TEST_UNIQUE_NAME;
};

struct A2 {
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
    u16 TEST_UNIQUE_NAME;
};

struct A4 {
    u32 TEST_UNIQUE_NAME;
    u32 TEST_UNIQUE_NAME;
    u32 TEST_UNIQUE_NAME;
    u32 TEST_UNIQUE_NAME;
};

#if defined(SB_HAS_INT64)
struct A8 {
    u64 TEST_UNIQUE_NAME;
    u64 TEST_UNIQUE_NAME;
};
#endif

int main(void) {
    assert(alignment_of<u8>::value == sizeof(u8));
    assert(alignment_of<s8>::value == sizeof(s8));
    assert(alignment_of<A1>::value == alignment_of<u8>::value);
    assert(alignment_of<u16>::value == sizeof(u16));
    assert(alignment_of<s16>::value == sizeof(s16));
    assert(alignment_of<A2>::value == alignment_of<u16>::value);
    assert(alignment_of<u32>::value == sizeof(u32));
    assert(alignment_of<s32>::value == sizeof(s32));
    assert(alignment_of<A4>::value == alignment_of<u32>::value);
#if defined(SB_HAS_INT64)
    assert(alignment_of<u64>::value == sizeof(u64));
    assert(alignment_of<s64>::value == sizeof(s64));
    assert(alignment_of<A8>::value == alignment_of<u64>::value);
#endif
#if defined(SB_HAS_INT128)
    assert(alignment_of<u128>::value == sizeof(u128));
    assert(alignment_of<s128>::value == sizeof(s128));
#endif
    assert(alignment_of<f32>::value == sizeof(f32));
    assert(alignment_of<f64>::value == sizeof(f64));
#if defined(SB_HAS_FLOAT128)
    assert(alignment_of<f128>::value == sizeof(f128));
#endif
    return 0;
}
