#include <kern/string.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

static void
strrev_test_empty_string(void **state)
{
	(void) state;
	assert_string_equal(strrev(""), "");
}

static void
strrev_test_fixed_length_strings(void **state)
{
	char            buff[] = "abc";

	(void) state;
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
