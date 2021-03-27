;    This file is part of Fukurō.
;
;    Fukurō is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    any later version.
;
;    Fukurō is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with Fukurō.  If not, see <https://www.gnu.org/licenses/>.

[BITS 32]
	;; --------------------------------------------------------------------
	;; Multiboot 1
	;; --------------------------------------------------------------------
	MULTIBOOT_MAGIC EQU 0x1BADB002
	MULTIBOOT_ALIGN EQU 1 << 0
	MULTIBOOT_MEMINFO EQU 1 << 1
	MULTIBOOT_FLAGS EQU MULTIBOOT_ALIGN | MULTIBOOT_MEMINFO

section .multiboot
align 4
	dd MULTIBOOT_MAGIC
	dd MULTIBOOT_FLAGS
	dd -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

	;; --------------------------------------------------------------------
	;; Multiboot 2
	;; --------------------------------------------------------------------
	MULTIBOOT2_MAGIC EQU 0xE85250D6
	MULTIBOOT2_ARCH EQU 0
	MULTIBOOT2_HEADER_LEN EQU multiboot2_header.end - multiboot2_header

section .multiboot
align 8
multiboot2_header:
	dd MULTIBOOT2_MAGIC
	dd MULTIBOOT2_ARCH
	dd MULTIBOOT2_HEADER_LEN
	dd -(MULTIBOOT2_MAGIC + MULTIBOOT2_ARCH + MULTIBOOT2_HEADER_LEN)

	;; end tag
	dw 0
	dw 0
	dd 8
.end:

	;; --------------------------------------------------------------------
	;; Stivale 2
	;; --------------------------------------------------------------------
section .stivale2hdr
align 4
	dq kmain
	dq stack_top
	dq 0
	dq 0

	;; --------------------------------------------------------------------
	;; Stack
	;; --------------------------------------------------------------------
section .bss
align 16
stack_bottom:
	resb 16384
stack_top:

	;; --------------------------------------------------------------------
	;; Entry point
	;; --------------------------------------------------------------------
section .text
global _start:function (_start.end - _start)
_start:
	mov esp, stack_top

        extern kmain
        call kmain

	cli
.hang:
	hlt
	jmp .hang
.end:
