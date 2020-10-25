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
#include <kern/logger.h>
#include <kern/string.h>
#include "isr.h"
#include "pic.h"

void
isr_handler(struct registers reg)
{
	LOG(WARNING, "INTERRUPT 0x%X", reg.int_number);

	pic_send_end_of_interrupt(reg.int_number);
}
