#ifndef _X86_64_STIVALE_H_
# define _X86_64_STIVALE_H_ 1

struct stivale_header
{
	uint64_t        stack;
	uint16_t        framebuffer_bpp;
	uint16_t        framebuffer_width;
	uint16_t        framebuffer_height;
	uint16_t        flags;
	uint64_t        entry;
} __attribute__((packed));

struct stivale_struct
{
	uint64_t        cmdline;
} __attribute__((packed));

#endif							/* !_X86_64_STIVALE_H_ */
