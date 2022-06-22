	.section ".text.boot"

	.extern __bss_begin
	.extern __bss_end
	.extern kmain

	.globl _entry
_entry:

	mov r0, #0
	ldr r1, =(__bss_begin)
	ldr r2, =(__bss_end)

1:
	strt r0, [r1, #0]
	add r1, #4
	cmp r2, r1
	bgt 1b

	bl kmain
	nop

hang:
	b hang
