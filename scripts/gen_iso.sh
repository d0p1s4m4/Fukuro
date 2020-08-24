#!/bin/sh

error () {
    printf "\033[31mError: $1\033[0m"
    exit 1
}

if [ ! -f "kernel.elf" ]
then
    make || error "Can't build kernel"
fi

mkdir -p /tmp/fukuro_iso/boot/grub
cat > /tmp/fukuro_iso/boot/grub/grub.cfg << EOF
menuentry "Fukuro" {
	multiboot2 /boot/kernel.elf
}
EOF

cp kernel.elf /tmp/fukuro_iso/boot/

grub2-mkrescue -o fukuro.iso /tmp/fukuro_iso