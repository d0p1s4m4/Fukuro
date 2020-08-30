#ifndef _MACHINE_ARCH_H_
# define _MACHINE_ARCH_H_ 1

# include <generic/arch.h>
# include <machine/types.h>

static __inline__ void
outb(uint16_t port, uint8_t value)
{
	__asm__ volatile ("outb %0, %1"::"a" (value), "Nd"(port));
}

static __inline__ uint8_t
inb(uint16_t port)
{
	uint8_t         ret;

	__asm__ volatile ("inb %1, %0":"=a" (ret):"Nd"(port));

	return (ret);
}

#endif							/* !_MACHINE_ARCH_H_ */
