#ifndef _I686_GDT_H_
# define _I686_GDT_H_ 1

# include <machine/types.h>

struct gdt_ptr {
	uint16_t        limit;
	uint32_t        base;
} __attribute__((packed));

struct gdt_entry {
	uint16_t        limit_low;
	uint16_t        base_low;
	uint8_t         base_mid;
	uint8_t         access;
	uint8_t         flags;
	uint8_t         base_high;
} __attribute__((packed));

void            gdt_init(void);
extern void     gdt_flush(uint32_t);

#endif							/* !_I686_GDT_H_ */
