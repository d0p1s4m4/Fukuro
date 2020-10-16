# overwrite main makefile config
CFLAGS		+= -mcmodel=kernel
LDFLAGS		+= -z max-page-size=0x1000

ARCH_ASM_SRCS	=
ARCH_C_SRCS	= arch.c
