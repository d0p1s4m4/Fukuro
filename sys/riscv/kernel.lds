ENTRY(_entry)

SECTIONS {
		 . = 0x80200000;

		 .text :{
		 	   KEEP(*(.text.boos));
			   *(.text .text.*);
		 }

		 .rodata : ALIGN(4) {
		 		 *(.rodata .text.*);
		 }

		 .data : ALIGN(4) {
		 	   *(.data .data.*);
		 }

		 .bss : ALIGN(4) {
		 	  *(.bss .bss.*);
			  *(COMMON);
		 }

		 PROVIDE(__bss_begin = ADDR(.bss));
		 PROVIDE(__bss_end = ADDR(.bss) + SIZEOF(.bss));

		 .stack (NOLOAD) : ALIGN(4) {
		 		. += 16 * 1024; /* 16KB */
				PROVIDE(__stack_top = .);
		}

		/* XXX: temporary  */
		. = ALIGN(4096);
		PROVIDE(__free_ram_begin = .);
		. += 256 * 1024 * 1024; /* 256MB */
		PROVIDE(__free_ram_end = .);
}
