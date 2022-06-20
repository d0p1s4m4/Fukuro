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

#include <machine/arch.h>
#include <x86/serial.h>
#include <x86/greeting.h>
#include <generic/stivale2.h>
#include "gdt.h"
#include "idt.h"
#include "cpuid.h"
#include "pic.h"

void
arch_init(void)
{
	/*
	 * COM1 will be used for our debug log 
	 */
	serial_init(COM1);

	greeting_screen();

	gdt_init();
	cpuid_dump_info();
	pic_remap();
	idt_init();

	kmain();
}

void
boot_stivale2(struct stivale2_struct data)
{
	(void)data;

	arch_init();
}

void
boot_multiboot(void)
{
	arch_init();
}
