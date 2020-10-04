ENTRY(_start)
 
SECTIONS
{
    . = 0x8000;

    .text :
    {
        KEEP(*(.text.boot))
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

    . = ALIGN(0x8);

    bss_begin = .;
    .bss :
    {
            *(.bss*)
    }
    bss_end = .;
}
