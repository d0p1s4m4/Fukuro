#ifndef FUKURO_I386_PMAP_H
# define FUKURO_I386_PMAP_H 1

# include <stdint.h>
# include <fukuro/spinlock.h>

struct pmap 
{
	uintptr_t *dirbase;

	int refcount;

	struct spinlock lock;
};

#endif /* !FUKURO_I386_PMAP_H */
