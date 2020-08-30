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
			buffer[idx++] = digit + '0';
		else
			buffer[idx++] = (digit - 0xA) + 'A';
		number /= 10;
	}
	while (number);
	buffer[idx] = '\0';
	return strrev(buffer);
}
