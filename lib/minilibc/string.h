#ifndef FUKURO_MINILIBC_H
# define FUKURO_MINILIBC_H 1

# include <stddef.h>

void *memset(void *dest, int c, size_t count);
size_t strlen(const char *str);

#endif /* !FUKURO_MINILIBC_H */
