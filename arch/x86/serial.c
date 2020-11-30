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
#include "serial.h"

void
serial_init(uint16_t port)
{
	outb(port + 1, 0x00);		/* disable all interrupts */

	outb(port + 2, 0x80);		/* enable DLAB */
	outb(port + 0, 0x0C);		/* 9600 baud */
	outb(port + 1, 0x00);

	outb(port + 3, 0x08);		/* 7 bits , no parity , 1 stop bit */
	outb(port + 2, 0xC7);
	outb(port + 4, 0x0B);		/* enable IRQs and set RTS/DTS */
}

static int
serial_is_buffer_empty(uint16_t port)
{
	return (inb(port + 5) & 0x20);
}

void
serial_write(uint16_t port, uint8_t data)
{
	while (serial_is_buffer_empty(port) == 0);
	outb(port, data);
}

static int
serial_received(uint16_t port)
{
	return (inb(port + 5) & 1);
}

uint8_t
serial_read(uint16_t port)
{
	while (serial_received(port) == 0);
	return (inb(port));
}

void
debug_puts(const char *str)
{
	while (*str != '\0')
		serial_write(COM1, *str++);
}

void
debug_putchar(char c)
{
	serial_write(COM1, c);
}
