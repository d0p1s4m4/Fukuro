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
#include "rpi.h"
#include "serial.h"

uint16_t        g_board;
uint32_t        g_mmio_base;

static void
detect_rpi_board(void)
{
	uint64_t value;

	__asm__ volatile ("mrs %0, midr_el1":"=r" (value));

	g_board = (value >> 4) & 0xFFF;
	switch (g_board)
	{
	 case RPI2: /* RPI 2 */
	 case RPI3: /* RPI 3 */
		 g_mmio_base = 0x3F000000;
		 break;
	 case RPI4:
		 g_mmio_base = 0xFE000000;
		 break;
	 default:
		 g_mmio_base = 0x20000000;
		 break;
	}
}

void
debug_puts(const char *str)
{
	while (*str != '\0')
	{
		serial_write(*str++);
	}
}

void
debug_putchar(char c)
{
	serial_write(c);
}

void
arch_init(void)
{
	detect_rpi_board();
	serial_init();

	kmain();
}
