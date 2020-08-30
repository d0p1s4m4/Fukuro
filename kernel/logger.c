#include <machine/arch.h>
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
