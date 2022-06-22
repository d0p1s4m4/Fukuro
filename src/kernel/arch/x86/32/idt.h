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

#ifndef _I686_IDT_H_
# define _I686_IDT_H_ 1

struct idt_ptr
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct idt_entry
{
	uint16_t base_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t attr;
	uint16_t base_high;
} __attribute__((packed));

void idt_init(void);
extern void idt_flush(uint32_t);

#endif /* !_I686_IDT_H_ */
