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
#include "vga.h"
#include "gdt.h"

void
debug_puts(const char *str)
{
	char           *ptr;

	ptr = (char *) str;
	while (*ptr != '\0')
		serial_write(COM1, *ptr++);
}

void
debug_putchar(char c)
{
	serial_write(COM1, c);
}

static void
greeting_screen(void)
{
	static const char *LOGO_ASCII[] = {
		"    ______     _               ___ \n",
		"    |  ___|   | |             |___|\n",
		"    | |_ _   _| | ___   _ _ __ ___  \n",
		"    |  _| | | | |/ / | | | '__/ _ \\ \n",
		"    | | | |_| |   <| |_| | | | (_) |\n",
		"    \\_|  \\__,_|_|\\_\\\\__,_|_|  \\___/ \n",
		(void *) 0
	};
	static const char *MESSAGE_AND_COPYRIGHT =
		"                                    v" VERSION " - " COMMIT "\n\n"
		"/!\\ Use serial to interact with me /!\\\n\n"
		"Copyright (C) 2020 d0p1.\n"
		"License GPLv3+: GNU GPL version 3 or later "
		"<https://gnu.org/licenses/gpl.html>.\n"
		"This is free software: you are free to change and redistribute it. \n"
		"There is NO WARRANTY, to the extent permitted by law.";

	uint8_t         logo_color;
	int             idx;

	logo_color = 0x09;
	for (idx = 0; LOGO_ASCII[idx] != (void *) 0; idx++)
		vga_puts(LOGO_ASCII[idx], logo_color++, 0x0);

	vga_puts(MESSAGE_AND_COPYRIGHT, 0xf, 0x0);
}

void
arch_init(void)
{
	greeting_screen();

	/*
	 * COM1 will be used for our debug log 
	 */
	serial_init(COM1);

	gdt_init();
}
