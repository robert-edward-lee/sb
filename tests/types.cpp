#include "sb/types.hxx"
#include "tests/common.hxx"

int main(void) {
    assert(sizeof(u8) == 1);
    assert(sizeof(s8) == 1);
    assert(sizeof(u16) == 2);
    assert(sizeof(s16) == 2);
    assert(sizeof(u32) == 4);
    assert(sizeof(s32) == 4);
#if defined(SB_HAS_INT64)
    assert(sizeof(u64) == 8);
    assert(sizeof(s64) == 8);
#endif
#if defined(SB_HAS_INT128)
    assert(sizeof(u128) == 16);
    assert(sizeof(s128) == 16);
#endif
    assert(sizeof(f32) == 4);
    assert(sizeof(f64) == 8);
#if defined(SB_HAS_FLOAT128)
    assert(sizeof(f128) == 16);
#endif
    assert(sizeof((char *)0 - (char *)1) == sizeof(ptrdiff_t));
    assert(sizeof((char *)0 - (char *)1) == sizeof(size_t));
    return 0;
}
