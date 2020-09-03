# overwrite main makefile config
AS		= nasm
ASFLAGS		= -f elf32

ARCH_ASM_SRCS	= boot.s gdt.s
ARCH_C_SRCS	= arch.c serial.c gdt.c vga.c
