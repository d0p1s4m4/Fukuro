	.section ".text"
	.align 4

	.extern __bss_begin
	.extern __bss_end
	.extern __minilibc_main

	.globl _start
_start:
	xorl %ebp, %ebp

	xorl %eax, %eax
	movl $__bss_begin, %edi
	movl $__bss_end, %ecx
	subl %edi, %ecx
	cld
	rep
	stosb

	pushl %ebp

	call __minilibc_main

	hlt
