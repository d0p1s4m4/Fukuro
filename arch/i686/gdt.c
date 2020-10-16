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
#include "gdt.h"

struct gdt_entry gdt_entries[5];
struct gdt_ptr  gdt_ptr;

static __inline__ void
gdt_set_table(struct gdt_entry *table, uint32_t base, uint32_t limit,
			  uint8_t access, uint8_t flags)
{
	table->base_low = (base & 0xffff);
	table->limit_low = (limit & 0xffff);
	table->base_high = (base & 0xff000000) >> 24;
	table->base_mid = (base & 0xff0000) >> 16;
	table->flags = ((limit >> 16) & 0x0F) | (flags & 0xF0);
	table->access = access;
}

void
gdt_init(void)
{
	gdt_ptr.limit = sizeof(struct gdt_entry) * 5;
	gdt_ptr.base = (uint32_t)&gdt_entries;

	gdt_set_table(&gdt_entries[0], 0, 0, 0, 0);
	gdt_set_table(&gdt_entries[1], 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_table(&gdt_entries[2], 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_table(&gdt_entries[3], 0, 0xFFFFFFFF, 0xFA, 0xC);
	gdt_set_table(&gdt_entries[4], 0, 0xFFFFFFFF, 0xF2, 0xC);
	gdt_flush((uint32_t)&gdt_ptr);
}
