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
bzero_test(void **state)
{
	char            buff[3] = "ok";

	(void) state;
	bzero(buff, 3);
	assert_memory_equal(buff, "\0\0\0", 3);
}

static void
memset_test(void **state)
{
	char            buff[5];

	(void) state;
	assert_ptr_equal(memset(buff, 'a', 5), buff);
	assert_memory_equal(buff, "aaaaa", 5);
}

int
memset_group_tests(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(bzero_test),
		cmocka_unit_test(memset_test),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
