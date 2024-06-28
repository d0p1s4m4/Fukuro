
OUTPUT_ARCH("i386")
ENTRY(_entry)

_kern_phys_base = 1M;
_kern_virt_base = 0xC0100000;
_kern_offset    = _kern_virt_base - _kern_phys_base;

SECTIONS {
    . = _kern_phys_base;

    .unpaged_text : { 
        i686/boot.o(.text.boot .text)
        i686/unpaged_*.o(.text)
    }

    .unpaged_data : {
        i686/boot.o(.data)
        i686/unpaged_*.o(.text)
    }

    .unpaged_bss : {
        i686/boot.o(.bss)
        i686/unpaged_*.o(.bss)
    }

    . += _kern_offset;

    .text : {
        *(.text.boot)
        *(.text)
    }

    .data : {
        *(.data)
    }

    .rodata : {
        *(.rodata)
    }

    .bss : {
        bss_begin = .;
        *(COMMON)
        *(.bss)
        bss_end = .;
    }
}
