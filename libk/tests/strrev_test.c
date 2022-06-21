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
strrev_test_empty_string(void **state)
{
	(void)state;
	assert_string_equal(strrev(""), "");
}

static void
strrev_test_fixed_length_strings(void **state)
{
	char buff[] = "abc";

	(void)state;
	assert_string_equal(strrev(buff), "cba");
}

int
strrev_group_tests(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(strrev_test_empty_string),
		cmocka_unit_test(strrev_test_fixed_length_strings),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
