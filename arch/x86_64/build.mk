# overwrite main makefile config
CFLAGS		+= -mcmodel=kernel
LDFLAGS		+= -z max-page-size=0x1000

include arch/x86/build.mk

ARCH_ASM_SRCS	=
ARCH_C_SRCS	= arch.c $(addprefix ../x86/, $(X86_SRCS))
