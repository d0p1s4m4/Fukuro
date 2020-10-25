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
#include <kern/vararg.h>
#include <kern/logger.h>
#include <kern/string.h>

static const char *LOG_LEVEL_STR[] = {
	"[*]", "\033[32m[+]\033[0m", "\033[33m[-]\033[0m", "\033[31m[!]\033[0m"
};

static void
debug_print_int(int number, int base)
{
	char            buff[6];	/* 99 999 */

	itoa(number, buff, base);
	debug_puts(buff);
}

void
__log(int level, const char *file, uint16_t line, const char *msg, ...)
{
	va_list         args;

	debug_puts(file);
	debug_putchar(':');
	debug_print_int(line, 10);
	debug_putchar(' ');

	if (level != NONE)
	{
		debug_puts(LOG_LEVEL_STR[level]);
		debug_putchar(' ');
	}

	va_start(args, msg);
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			switch (*msg)
			{
			case 'c':
				debug_putchar((char)va_arg(args, int));
				break;
			case 'd':
				debug_print_int(va_arg(args, int), 10);
				break;
			case 'x':
				debug_print_hex(va_arg(args, int), 16);
				break;
			case 'X':
				debug_print_hex(va_arg(args, int), 16);
				break;
			case 's':
				debug_puts(va_arg(args, char *));
				break;
			default:
				debug_putchar('%');
				break;
			}
		}
		else
		{
			debug_putchar(*msg);
		}
		msg++;
	}
	va_end(args);
	debug_putchar('\n');
}