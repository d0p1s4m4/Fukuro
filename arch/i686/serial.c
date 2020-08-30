#include <machine/arch.h>

void
serial_init(uint16_t port)
{
	outb(port + 1, 0x00);		/* disable all interrupts */

	outb(port + 2, 0x80);		/* enable DLAB */
	outb(port + 0, 0x0C);		/* 9600 baud */
	outb(port + 1, 0x00);

	outb(port + 3, 0x08);		/* 7 bits , no parity , 1 stop bit */
	outb(port + 2, 0xC7);
	outb(port + 4, 0x0B);		/* enable IRQs and set RTS/DTS */
}

static int
serial_is_serial_buffer_empty(uint16_t port)
{
	return (inb(port + 5) & 0x20);
}

void
serial_write(uint16_t port, uint8_t data)
{
	while (serial_is_serial_buffer_empty(port) == 0);
	outb(port, data);
}

static int
serial_received(uint16_t port)
{
	return (inb(port + 5) & 1);
}

uint8_t
serial_read(uint16_t port)
{
	while (serial_received(port) == 0);
	return (inb(port));
}
