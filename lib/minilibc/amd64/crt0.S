	.section .text
	.align 8

	.extern __bss_begin
	.extern __bss_end
	.extern __minilibc_main

	.globl _start
_start:
	xorq %rbp, %rbp

	/* clear bss */
	xorq %rax, %rax
	movq $__bss_begin, %rdi
	movq $__bss_end, %rcx
	subq %rdi, %rcx
	cld
	rep
	stosb

	movq %rsp, %rdi
	call __minilibc_main

	hlt
