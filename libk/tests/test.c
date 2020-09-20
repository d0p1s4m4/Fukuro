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

int             strlen_group_tests(void);
int             strrev_group_tests(void);
int             itoa_group_tests(void);
int             memset_group_tests(void);

/*
 * required by logger.c 
 */
void
debug_puts(const char *str)
{
	(void) str;
}

/*
 * required by logger.c 
 */
void
debug_putchar(const char c)
{
	(void) c;
}

int
main(void)
{
	int             result;

	result = 0;
	result |= strlen_group_tests();
	result |= strrev_group_tests();
	result |= itoa_group_tests();
	result |= memset_group_tests();

	return (result);
}
