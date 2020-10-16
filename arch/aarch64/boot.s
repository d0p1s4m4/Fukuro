/*
 *   This file is part of Fukurō.
 *
 *   Fukurō is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   Fukurō is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Fukurō.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <kern/string.h>

.section ".text.boot"

.extern kmain

.globl _start
_start:
	mrs x0, mpidr_el1			/* read multiprocessor affinity reg */
	and x0, x0, #3				/* check if core 0 otherwhise hang */
	cbz x0, master
proc_hang:
	b proc_hang

master:
	/* set stack before code */
	ldr x1, =_start
	mov sp, x1

	ldr x0, =bss_begin
	ldr x1, =bss_end
	sub x1, x1, x0
	bl bzero					/* clear .bss section */

	/* start kernel */
	bl kmain

	b proc_hang

