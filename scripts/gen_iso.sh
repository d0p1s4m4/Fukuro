#!/bin/sh

error () {
    printf "\033[31mError: %s\033[0m\n" "$1"
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

grub2-mkrescue -o fukuro.iso /tmp/fukuro_iso  \
    || grub-mkrescue -o fukuro.iso /tmp/fukuro_iso || error "Can't create ISO"
