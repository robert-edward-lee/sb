CXX = cl

INCLUDE_OPTS = $(addprefix /I,$(INCLUDE_DIR))
STDCXX_OPTS =
WARN_OPTS = /W4

test: $(TEST_BINS)
	@echo All test are done! 1>&2

%: %.cpp
	@$(CXX) $(CXXFLAGS) /nologo $< /link /out:$@.exe
	@$@.exe
