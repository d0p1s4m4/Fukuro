SECTIONS
{
        . = 0x80000;

        .text.boot :
        {
                *(.text.boot)
        }

        .text :
        {
                *(.text)
        }

        .rodata :
        {
                *(.rodata)
        }

        .data :
        {
                *(.data)
        }

        . = ALIGN(16);

        bss_begin = .;
        .bss :
        {
                *(.bss*)
        }
        bss_end = .;
}
