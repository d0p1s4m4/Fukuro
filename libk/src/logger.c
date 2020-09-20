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
#include <kern/logger.h>
#include <kern/string.h>

static const char *LOG_LEVEL_STR[] = {
	"   ", "\033[32m[+]\033[0m", "\033[33m[-]\033[0m", "\033[31m[!]\033[0m"
};

static void
debug_print_int(int number)
{
	char            buff[5];	/* 99 999 */

	itoa(number, buff, 10);
	debug_puts(buff);
}

void
__log(int level, const char *file, uint16_t line, const char *msg)
{
	debug_puts(file);
	debug_putchar(':');
	debug_print_int(line);
	debug_putchar(' ');

	debug_puts(LOG_LEVEL_STR[level]);
	debug_putchar(' ');
	debug_puts(msg);
	debug_putchar('\n');
}
