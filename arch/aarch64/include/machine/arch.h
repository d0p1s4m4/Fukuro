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
# include <stdint.h>

extern void mmio_write(uint32_t, uint32_t);
extern uint32_t mmio_read(uint32_t);
extern void delay_cycles(uint32_t);

#endif /* !_MACHINE_ARCH_H_ */
