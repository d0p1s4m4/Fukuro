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
strlen_test_empty_string(void **state)
{
	(void) state;
	assert_int_equal(strlen(""), 0);
}

static void
strlen_test_fixed_length_strings(void **state)
{
	(void) state;
	assert_int_equal(strlen("a"), 1);
	assert_int_equal(strlen("abcd"), 4);
}

int
strlen_group_tests(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(strlen_test_empty_string),
		cmocka_unit_test(strlen_test_fixed_length_strings),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
