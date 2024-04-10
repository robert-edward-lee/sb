INCLUDE_DIR = include
TEST_DIR = tests
WORK_DIRS = $(sort $(dir $(wildcard $(TEST_DIR)/ include/sb/*/)))

CXX = g++
CXXFLAGS += $(addprefix -I,$(INCLUDE_DIR)) $(WARN_OPTS) $(STDCXX_OPTS)
include Makefile.gcc

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
