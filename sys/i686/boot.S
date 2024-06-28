/*
 * Copyright © 2024, d0p1
 *
 * This file is part of Fukurō.
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://cecill.info". 
 * 
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 */

#include <sys/multiboot.h>

	.section .text.boot

#define MULTIBOOT_FLAGS (MULTIBOOT_PAGE_ALIGN \
						| MULTIBOOT_MEMORY_INFO \
						| MULTIBOOT_VIDEO)

#define MULTIBOOT_CHECKSUM -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_FLAGS)

#define FRAMEBUFFER_WIDTH  1024
#define FRAMEBUFFER_HEIGHT 768
#define FRAMEBUFFER_BPP    32 

	.align 4
	.long MULTIBOOT_HEADER_MAGIC
	.long MULTIBOOT_FLAGS
	.long MULTIBOOT_CHECKSUM

	.long 0x0
	.long 0x0
	.long 0x0
	.long 0x0
	.long 0x0

	/* framebuffer */
	.long 0x0
	.long FRAMEBUFFER_WIDTH
	.long FRAMEBUFFER_HEIGHT
	.long FRAMEBUFFER_BPP

	.section .bss
	.align 16
stack_bottom:
	.skip 4096
stack_top:

	.section .text
	.globl _entry
	.type _entry, @function
_entry:
	cli

	movl $stack_top, %esp
	movl $stack_bottom, %ebp

	pushl %ebx /* struct */
	pushl %eax /* magic */
	
	.extern unpaged_init
	call unpaged_init

	orl %eax, %eax
	je 1f

	pushl %eax

	.extern kmain
	call kmaim

1:
	hlt
	jmp 1b
