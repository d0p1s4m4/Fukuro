#include <machine/arch.h>
#include "serial.h"

void
debug_puts(const char *str)
{
	char           *ptr;

	ptr = (char *) str;
	while (*ptr != '\0')
		serial_write(COM1, *ptr++);
}

void
debug_putchar(char c)
{
	serial_write(COM1, c);
}

void
arch_init(void)
{
	/*
	 * COM1 will be used for our debug log 
	 */
	serial_init(COM1);
}
