# overwrite main makefile config
CFLAGS += -mgeneral-regs-only

ARCH_ASM_SRCS	= boot.s
ARCH_C_SRCS	= arch.c
