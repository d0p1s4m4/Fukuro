# vim: set tabstop=4:shiftwidth=4:noexpandtab

LIB_MINIC_SRCS = itoa.c \
				strlen.c \
				strrev.c \
				memset.c

LIB_MINIC_KERNEL_OBJS	= $(addprefix $(KERNEL_BUILDDIR)/lib/minic/, $(LIB_MINIC_SRCS:.c=.o))
LIB_MINIC_TEST_OBJS		= $(addprefix $(TEST_BUILDDIR)/lib/minic/, $(LIB_MINIC_SRCS:.c=.o))

$(TEST_BUILDDIR)/lib/minic/%.o: src/lib/minic/%.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(TESTS_CFLAGS)

$(KERNEL_BUILDDIR)/lib/minic/%.o: src/lib/minic/%.c
	@ mkdir -p $(dir $@)
	$(TARGET_CC) -o $@ -c $< $(KERNEL_CFLAGS)

