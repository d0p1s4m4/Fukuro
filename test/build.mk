# vim: set tabstop=4:shiftwidth=4:noexpandtab

TESTS_SRCS	= itoa_test.c \
				memset_test.c \
				strlen_test.c \
				strrev_test.c \
				test.c

TESTS_OBJS	= $(addprefix $(TEST_BUILDDIR)/, $(TESTS_SRCS:.c=.o))

.PHONY: test
test: $(TESTS_OBJS) $(LIB_MINIC_TEST_OBJS)
	$(CC) -o test.exe $^ $(TESTS_LDFLAGS)
	@ ./test.exe

$(TEST_BUILDDIR)/%.o: test/%.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(TESTS_CFLAGS)

