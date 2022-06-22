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
		 		. += 0x4000;
				PROVIDE(__stack_top = .);
		}
}
