# Global config
ARCH	?= i686
CC	= $(ARCH)-elf-gcc
AS	= $(ARCH)-elf-as
RM	= rm -rf

VERSION	= $$(cat VERSION)
COMMIT = $$(git rev-parse --short HEAD)

CFLAGS	= -ansi -pedantic -pedantic-errors -Wall -Werror -Wextra \
		-ffreestanding -fno-builtin -nostdlib -nostdinc -O2 \
		-Iarch/$(ARCH)/include -Iarch -Ilibk/include \
		-DVERSION="\"$(VERSION)\"" -DCOMMIT="\"$(COMMIT)\""
ASFLAGS	=
LDFLAGS	= -T arch/$(ARCH)/linker.ld -ffreestanding -nostdlib

# import arch specific build config
ifneq "$(wildcard arch/$(ARCH)/)" ""
 include arch/$(ARCH)/build.mk
else
 $(error "$(ARCH) is not supported by Fukuro")
endif

include libk/build.mk

KERNEL	= kernel.elf
ISO	= fukuro.iso

KERN_SRCS	= main.c logger.c
OBJS		= $(addprefix kernel/, $(KERN_SRCS:.c=.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_ASM_SRCS:.s=.s.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_C_SRCS:.c=.o)) \
			$(addprefix libk/, $(LIBK_C_SRCS:.c=.o))

all: $(ISO)

$(ISO): $(KERNEL)
	./scripts/gen_iso.sh

$(KERNEL): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(KERNEL)
	$(RM) $(ISO)

re: fclean all

qemu: $(ISO)
	qemu-kvm -cdrom $< -s -serial stdio

format:
	find . -type f  -name "*.[h|c]" -exec ./scripts/format.sh {} \;

.PHONY: all clean fclean re qemu format
