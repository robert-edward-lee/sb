CXX = clang++

INCLUDE_OPTS = $(addprefix -I,$(INCLUDE_DIR))
STDCXX_OPTS = -ansi
WARN_OPTS = -Wall -Wextra -pedantic -Wno-long-long

test: $(TEST_BINS)
	@echo All test are done! 1>&2

%: %.cpp
	@echo $(notdir $<)
	@$(CXX) $(CXXFLAGS) $< -o $@
	@./$@
