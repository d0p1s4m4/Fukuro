#include <kern/string.h>

char *
strrev(char *str)
{
	int             start;
	int             end;
	char            tmp;

	end = strlen(str) - 1;
	start = 0;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}
