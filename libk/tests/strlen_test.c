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
