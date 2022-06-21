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

#ifndef _MACHINE_ARCH_H_
# define _MACHINE_ARCH_H_ 1

# include <generic/arch.h>
# include <machine/types.h>

static __inline__ void
outb(uint16_t port, uint8_t value)
{
	__asm__ volatile ("outb %0, %1"::"a" (value), "Nd"(port));
}

static __inline__ uint8_t
inb(uint16_t port)
{
	uint8_t ret;

	__asm__ volatile ("inb %1, %0":"=a" (ret):"Nd"(port));

	return (ret);
}

#endif /* !_MACHINE_ARCH_H_ */
