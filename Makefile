.DEFAULT_GOAL = all

# Global config
ARCH	?= i686
CC	= $(ARCH)-elf-gcc
AS	= $(ARCH)-elf-as
OBJCOPY	= $(ARCH)-elf-objcopy
RM	= rm -rf
SPARSE	= sparse
ifeq ($(C),)
	SPARSE := :
endif

VERSION	= $$(cat VERSION)
COMMIT = $$(git rev-parse --short HEAD)

CFLAGS	= -ansi -pedantic -pedantic-errors -Wall -Werror -Wextra \
		-ffreestanding -fno-builtin -nostdlib -nostdinc -O2 \
		-Iarch/$(ARCH)/include -Iarch -Ilibk/include \
		-DVERSION="\"$(VERSION)\"" -DCOMMIT="\"$(COMMIT)\"" \
		-Wno-variadic-macros
ASFLAGS	=
LDFLAGS	= -T arch/$(ARCH)/linker.ld -ffreestanding -nostdlib

KERNEL	= kernel.elf

# import arch specific build config
ifneq "$(wildcard arch/$(ARCH)/)" ""
 include arch/$(ARCH)/build.mk
else
 $(error "$(ARCH) is not supported by Fukuro")
endif

include kernel/build.mk
include libk/build.mk

TARGET	?= $(KERNEL)

OBJS		= $(addprefix kernel/, $(KERN_C_SRCS:.c=.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_ASM_SRCS:.s=.s.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_C_SRCS:.c=.o)) \
			$(addprefix libk/, $(LIBK_C_SRCS:.c=.o))

OBJS_TEST	= $(addprefix libk/, $(LIBK_C_SRCS:.c=.o)) \
			$(addprefix libk/, $(LIBK_C_TESTS:.c=.o))

test: CFLAGS	= -Wall -Werror -Wextra  -fno-builtin \
				-Iarch/$(ARCH)/include -Iarch -Ilibk/include \
				 --coverage
test: LDFLAGS	= -lcmocka --coverage
test: CC		= gcc

all: $(TARGET)

test: $(OBJS_TEST)
	$(CC) -o $@ $^ $(LDFLAGS)
	./$@

$(KERNEL): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	@ $(SPARSE) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)
	$(RM) $(OBJS_TEST:.o=.gcda)
	$(RM) $(OBJS_TEST:.o=.gcno)

fclean: clean
	$(RM) $(KERNEL)
	$(RM) $(TARGET)
	$(RM) test

re: fclean all

format:
	find . -type f  -name "*.[h|c]" -exec ./scripts/format.sh {} \;

.PHONY: all clean fclean re qemu format test
