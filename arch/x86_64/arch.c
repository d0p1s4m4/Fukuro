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
#include <kern/logger.h>

void	kmain(void);
void	_start(struct stivale2_struct *data);

static char     stack[4096] = { 0 };

__attribute__((section(".stivale2hdr"), used))
struct stivale2_header stivale2hdr = {
	(uint64_t)&_start,
	(uint64_t)stack + sizeof(stack),
	0,
	0
};

void
arch_init(void)
{
	greeting_screen();
}

void
_start(struct stivale2_struct *data)
{
	serial_init(COM1);

	LOG(INFO, "Boot protocol: Stivale2");
	LOG(INFO, "Bootloader: %s", data->bootloader_brand);

	kmain();

	__asm__ volatile ("hlt");
}