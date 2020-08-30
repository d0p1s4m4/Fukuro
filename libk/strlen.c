int
strlen(const char *str)
{
	const char     *s;

	for (s = str; *s != '\0'; s++);

	return (s - str);
}
