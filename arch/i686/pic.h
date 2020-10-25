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

#ifndef _I686_PIC_H_
# define _I686_PIC_H_ 1

# define PIC_MASTER_CMD		0x0020
# define PIC_MASTER_DATA	0x0021
# define PIC_SLAVE_CMD		0x00A0
# define PIC_SLAVE_DATA		0x00A1

# define PIC_CMD_EOI		0x20

# define ICW1_ICW4			0x01
# define ICW1_INIT			0x10
# define ICW4_8086			0x01

# define PIC_MASTER_OFFSET	0x20
# define PIC_SLAVE_OFFSET	0xA0

void            pic_remap();
void            pic_send_end_of_interrupt(uint8_t irq);
void            pic_disable(void);

#endif							/* !_I686_PIC_H_ */
