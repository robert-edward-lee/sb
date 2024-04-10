#ifndef HXX_TEST_COMMON
#define HXX_TEST_COMMON

#include <cassert>
#include <iostream>

#include "sb/config.hxx"

#define UNIQUE_NAME SB_CONCAT(a, __LINE__) SB_MAYBE_UNUSED

using namespace sb;

#endif // HXX_TEST_COMMON
