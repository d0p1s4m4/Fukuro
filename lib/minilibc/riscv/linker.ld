ENTRY(_start)

SECTIONS {
		 . = 0x1000000;

		 .text :{
		 	   *(.text .text.*);
		 }

		 .rodata : ALIGN(4) {
		 		 *(.rodata .rodata.*);
		 }

		 .data : ALIGN(4) {
		 	   *(.data .data.*);
		 }

		 .bss : ALIGN(4) {
		 	  *(.bss .bss.* .sbss .sbss.*);

			  . = ALIGN(4);
			  . += 64 * 1024;
			 PROVIDE(__stack_top = .);
		 }

		 PROVIDE(__bss_begin = ADDR(.bss));
		 PROVIDE(__bss_end = ADDR(.bss) + SIZEOF(.bss));
}
