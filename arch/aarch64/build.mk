# overwrite main makefile config
CFLAGS += -mgeneral-regs-only
ASFLAGS += -c $(CFLAGS)

ARCH_ASM_SRCS	= boot.s utils.s
ARCH_C_SRCS	= arch.c serial.c

TARGET		= kernel8.img

$(TARGET): $(KERNEL)
	$(OBJCOPY) $^ -O binary $@

qemu: $(TARGET)
	qemu-system-aarch64 -M raspi3 -serial stdio -kernel $^
