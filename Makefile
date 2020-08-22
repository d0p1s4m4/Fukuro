CC	= i686-elf-gcc
AS	= nasm
RM	= rm -f

NAME	= kernel.elf

CFLAGS	+= -ansi -pedantic -pedantic-errors -Wall -Werror -Wextra -ffreestanding \
		-fno-builtin -nostdlib -nostdinc
ASFLAGS	= -f elf32
LDFLAGS	+= -T arch/i686/linker.ld -ffreestanding -nostdlib

KERN_SRCS	= main.c
OBJS		= $(addprefix kernel/, $(KERN_SRCS:.c=.o)) arch/i686/boot.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

arch/i686/boot.o: arch/i686/boot.s
	$(AS) $(ASFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
