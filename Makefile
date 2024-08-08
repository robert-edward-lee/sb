################################################################################
#                              ОПРЕДЕЛЕНИЯ ПАПОК                               #
################################################################################
INCLUDE_DIR = include .

TEST_DIR = tests
TEST_DIRS = $(sort $(TEST_DIR)/ $(dir $(wildcard $(TEST_DIR)/*/)))
TEST_SRCS = $(foreach dir,$(TEST_DIRS),$(wildcard $(dir)*.cpp))
TEST_BINS = $(patsubst %.cpp,%,$(TEST_SRCS))

WORK_DIRS = $(sort . $(TEST_DIRS) \
			$(dir $(wildcard include/sb/*/)) \
			$(dir $(wildcard include/sb/*/*/)))

VPATH = $(TEST_DIR)

################################################################################
#                              НАСТРОЙКА ТУЛЧЕЙНА                              #
################################################################################
CC = gcc

CFLAGS += $(INCLUDE_OPTS) $(WARN_OPTS) $(STDC_OPTS)
CXXFLAGS += $(INCLUDE_OPTS) $(WARN_OPTS) $(STDCXX_OPTS)

ifeq ($(CC),gcc)
CXX = g++
include Makefile.gcc
else ifeq ($(CC),clang)
CXX = clang++
include Makefile.gcc
else ifeq ($(CC),cl)
include Makefile.msvc
endif

################################################################################
#                                  ОБЩИЕ ЦЕЛИ                                  #
################################################################################
clean:
	@$(RM) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.a,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.d,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.dll,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.exe,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.o,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.obj,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.tds,$(dir)))

format:
	@clang-format -style=file:./.clang-format -i \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.c,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.cpp,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.cxx,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.h,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.hpp,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.hxx,$(dir))) \
		2> /dev/null ||:
