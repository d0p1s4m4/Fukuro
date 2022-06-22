#include <machine/arch.h>
#include "rpi.h"

void
serial_init(void)
{
	mmio_write(UART0_CR, 0x00000000);
	mmio_write(GPPUD, 0x00000000);
	delay_cycles(150);

	mmio_write(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay_cycles(150);

	mmio_write(GPPUDCLK0, 0x00000000);
	mmio_write(UART0_ICR, 0x7FF);	/* clear pending interupts */

	mmio_write(UART0_IBRD, 1);
	mmio_write(UART0_FBRD, 40);

	mmio_write(UART0_LCRH, 0x70);
	mmio_write(UART0_IMSC, 0x7FE);

	mmio_write(UART0_CR, 0x301);
}

void
serial_write(uint8_t c)
{
	while (mmio_read(UART0_FR) & 0x20)
		;;
	mmio_write(UART0_DR, c);
}

uint8_t
serial_read(void)
{
	while (mmio_read(UART0_FR) & 0x10)
		;;
	return (mmio_read(UART0_DR));
}
