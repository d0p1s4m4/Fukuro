# overwrite main makefile config
AS		= nasm
ASFLAGS		= -f elf32

ARCH_ASM_SRCS	= boot.s gdt.s idt.s isr.s
ARCH_C_SRCS	= arch.c serial.c gdt.c vga.c pic.c idt.c isr.c

TARGET		= fukuro.iso

$(TARGET): $(KERNEL)
	./scripts/gen_iso.sh

qemu: $(TARGET)
	qemu-kvm -cdrom $< -s -serial stdio
