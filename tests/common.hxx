#ifndef HXX_TEST_COMMON
#define HXX_TEST_COMMON

#include <cassert>
#include <iostream>

#include "sb/config.hxx"

#define TEST_UNIQUE_NAME_UNUSED SB_CONCAT(a, __LINE__) SB_MAYBE_UNUSED

#define TEST_UNIQUE_NAME SB_CONCAT(a, __LINE__)

using namespace sb;

#endif // HXX_TEST_COMMON
