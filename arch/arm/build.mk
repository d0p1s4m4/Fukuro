# overwrite main makefile config
CC	= arm-none-eabi-gcc
AS	= arm-none-eabi-as

CFLAGS	+= -mcpu=cortex-a7 -fpic

ARCH_ASM_SRCS	= boot.s
ARCH_C_SRCS	= arch.c

qemu: $(KERNEL)
	qemu-system-arm -M raspi2 -serial stdio -kernel $^
