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

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

static void
itoa_test_hex_deadbeef(void **state)
{
	char            buff[7];

	(void) state;
	assert_string_equal(itoa(0xC0FFEE, buff, 16), "C0FFEE");
}

static void
itoa_test_hex_f(void **state)
{
	char            buff[2];

	(void) state;
	assert_string_equal(itoa(0xF, buff, 16), "F");
}

static void
itoa_test_binary_2(void **state)
{
	char            buff[3];

	(void) state;
	assert_string_equal(itoa(2, buff, 2), "10");
}

static void
itoa_test_42(void **state)
{
	char            buff[3];

	(void) state;
	assert_string_equal(itoa(42, buff, 10), "42");
}

int
itoa_group_tests(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(itoa_test_hex_deadbeef),
		cmocka_unit_test(itoa_test_hex_f),
		cmocka_unit_test(itoa_test_binary_2),
		cmocka_unit_test(itoa_test_42),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
