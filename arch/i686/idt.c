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

#include <machine/types.h>
#include <kern/string.h>
#include <kern/logger.h>
#include "idt.h"
#include "isr.h"

static struct idt_entry idt[256];

static void
idt_set_table(uint8_t idx, uint16_t selector, uint8_t attr)
{
	uint32_t base;

	base = isr_list[idx];
	idt[idx].base_low = base & 0xFFFF;
	idt[idx].base_high = (base >> 16) & 0xFFFF;
	idt[idx].selector = selector;
	idt[idx].attr = attr;
}

void
idt_init(void)
{
	struct idt_ptr  ptr;
	unsigned int    idx;

	bzero(idt, sizeof(idt));

	for (idx = 0; idx < 32; idx++)
	{
		idt_set_table(idx, 0x08, 0x8E);
	}

	ptr.limit = sizeof(idt);
	ptr.base = (uint32_t)&idt;

	idt_flush((uint32_t)&ptr);
}
