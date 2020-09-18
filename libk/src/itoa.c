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

#include <kern/string.h>

char *
itoa(int number, char *buffer, int base)
{
	int             digit;
	int             idx;

	idx = 0;
	do
	{
		digit = number % base;
		if (digit < 0xA)		/* base16 support */
			buffer[idx] = digit + '0';
		else
			buffer[idx] = (digit - 0xA) + 'A';
		number /= base;
		idx++;
	}
	while (number);
	buffer[idx] = '\0';
	return (strrev(buffer));
}
