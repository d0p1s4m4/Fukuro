KERNEL_SRCS	= main.c

KERNEL_OBJS	= $(addprefix $(KERNEL_BUILDDIR)/, $(KERNEL_SRCS:.c=.o))

TARGET		= fukuro.elf

kernel8.img: fukuro.elf
	$(TARGET_OBJCOPY) $< -O binary $@

fukuro.elf: $(KERNEL_OBJS) $(LIB_MINIC_KERNEL_OBJS)
	$(TARGET_CC) -o $@ $^ $(KERNEL_LDFLAGS)

$(KERNEL_BUILDDIR)/%.o: src/kernel/%.c
	@ mkdir -p $(dir $@)
	$(TARGET_CC) -o $@ -c $< $(KERNEL_CFLAGS)

