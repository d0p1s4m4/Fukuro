# overwrite main makefile config
AS		= nasm
ASFLAGS		= -f elf32

include arch/x86/build.mk

ARCH_ASM_SRCS	= boot.s gdt.s idt.s isr.s
ARCH_C_SRCS	= arch.c $(addprefix ../x86/, $(X86_SRCS)) \
				gdt.c pic.c idt.c isr.c cpuid.c

TARGET		= fukuro.iso

$(TARGET): $(KERNEL)
	./scripts/gen_iso.sh

qemu: $(TARGET)
	qemu-kvm -cdrom $< -s -serial stdio
