LIBK_C_SRCS	= $(addprefix src/, itoa.c strlen.c strrev.c memset.c logger.c)

LIBK_C_TESTS = $(addprefix tests/, test.c \
								strlen_test.c \
								strrev_test.c \
								itoa_test.c \
								memset_test.c)
