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
#include "pic.h"

static __inline__ void
pic_wait(void)
{
	__asm__ volatile ("jmp 1f\n" "1:jmp 2f\n" "2:");
}

void
pic_remap(void)
{
	uint8_t a1;
	uint8_t a2;

	a1 = inb(PIC_MASTER_DATA);
	a2 = inb(PIC_SLAVE_DATA);

	outb(PIC_MASTER_CMD, ICW1_INIT | ICW1_ICW4);
	pic_wait();
	outb(PIC_SLAVE_CMD, ICW1_INIT | ICW1_ICW4);
	pic_wait();
	outb(PIC_MASTER_DATA, PIC_MASTER_OFFSET);
	pic_wait();
	outb(PIC_SLAVE_DATA, PIC_SLAVE_OFFSET);
	pic_wait();
	outb(PIC_MASTER_DATA, 4);
	pic_wait();
	outb(PIC_SLAVE_DATA, 2);
	pic_wait();

	outb(PIC_MASTER_DATA, ICW4_8086);
	pic_wait();
	outb(PIC_SLAVE_DATA, ICW4_8086);
	pic_wait();

	outb(PIC_MASTER_DATA, a1);
	outb(PIC_SLAVE_DATA, a2);
}

void
pic_send_end_of_interrupt(uint8_t irq)
{
	if (irq >= 8)
	{
		outb(PIC_SLAVE_CMD, PIC_CMD_EOI);
	}
	outb(PIC_MASTER_CMD, PIC_CMD_EOI);
}

void
pic_disable(void)
{
	/*
	 * disable pic for local APIC and IOAPIC 
	 */
	outb(PIC_MASTER_CMD, 0xFF);
	outb(PIC_SLAVE_DATA, 0xFF);
}
