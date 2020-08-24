# Global config
ARCH	?= i686
CC	= $(ARCH)-elf-gcc
AS	= $(ARCH)-elf-as
RM	= rm -rf

CFLAGS	= -ansi -pedantic -pedantic-errors -Wall -Werror -Wextra \
		-ffreestanding -fno-builtin -nostdlib -nostdinc -O2
ASFLAGS	=
LDFLAGS	= -T arch/$(ARCH)/linker.ld -ffreestanding -nostdlib

# import arch specific build config
ifneq "$(wildcard arch/$(ARCH)/)" ""
 include arch/$(ARCH)/build.mk
else
 $(error "$(ARCH) is not supported by Fukuro")
endif

NAME	= kernel.elf

KERN_SRCS	= main.c
OBJS		= $(addprefix kernel/, $(KERN_SRCS:.c=.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_ASM_SRCS:.s=.o)) \
			$(addprefix arch/$(ARCH)/, $(ARCH_C_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
