#ifndef FUKURO_PARAM_H
# define FUKURO_PARAM_H 1

# include <stdint.h>

# define MEMMAP_MAX 40

struct memory_map
{
	uintptr_t address;
	uintptr_t length;
};

struct kernel_info
{
	struct memory_map mmap[MEMMAP_MAX];
};

#endif /* FUKURO_PARAM_H */
