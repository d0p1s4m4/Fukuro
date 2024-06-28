ENTRY(_entry)

SECTIONS
{
    . = 0x8000;

    .text : ALIGN(4K) {
        KEEP(*(.text.boot))
       *(.text)
    }

    .rodata : ALIGN(4K) {
       *(.rodata)
    }

    .data : ALIGN(4K) {
        *(.data)
    }

    .bss : ALIGN(4K) {
        *(.bss)
    }

    PROVIDE(__bss_begin = ADDR(.bss));
	PROVIDE(__bss_end = ADDR(.bss) + SIZEOF(.bss));
}