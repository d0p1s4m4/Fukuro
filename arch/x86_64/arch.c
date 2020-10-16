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
#include "stivale.h"

static char     stack[4096] = { 0 };

struct stivale_header stivalehdr = {
	(uint64_t) stack + sizeof(stack),
	0,
	0,
	0,
	0,
	0
};

void
debug_puts(const char *str)
{
	(void) str;
}

void
debug_putchar(char c)
{
	(void) c;
}

void
arch_init(void)
{
}

void
_start(void)
{
	*((uint16_t *) 0xB8000) = 'O';
	*((uint16_t *) 0xB8002) = 'K';
}
