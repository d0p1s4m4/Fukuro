#ifndef _GENERIC_STIVALE2_H_
# define _GENERIC_STIVALE2_H_ 1

struct stivale2_header
{
	uint64_t        entry_point;
	uint64_t        stack;
	uint64_t        flags;
	uint64_t        tags;
} __attribute__((packed));

struct stivale2_struct
{
	char bootloader_brand[64];
	char bootloader_version[64];

	uint64_t tags;
} __attribute__((packed));

#endif							/* !_GENERIC_STIVALE2_H_ */
