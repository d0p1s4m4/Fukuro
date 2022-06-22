#ifndef _AARCH64_RPI_H_
# define _AARCH64_RPI_H_ 1

# define RPI2	0xC07
# define RPI3	0xD03
# define RPI4	0xD08

# define GPIO_BASE	g_mmio_base + 0x200000
# define GPFSEL0	GPIO_BASE
# define GPFSEL1	GPIO_BASE + 0x04
# define GPFSEL2	GPIO_BASE + 0x08
# define GPFSEL3	GPIO_BASE + 0x0C
# define GPFSEL4	GPIO_BASE + 0x10
# define GPFSEL5	GPIO_BASE + 0x14
# define GPSET0		GPIO_BASE + 0x1C
# define GPSET1		GPIO_BASE + 0x20
# define GPCLR0		GPIO_BASE + 0x28
# define GPCLR1		GPIO_BASE + 0x2C
# define GPLEV0		GPIO_BASE + 0x34
# define GPLEV1		GPIO_BASE + 0x38
# define GPEDS0		GPIO_BASE + 0x40
# define GPEDS1		GPIO_BASE + 0x44
# define GPREN0		GPIO_BASE + 0x4C
# define GPREN1		GPIO_BASE + 0x50
# define GPFEN0		GPIO_BASE + 0x58
# define GPFEN1		GPIO_BASE + 0x5C
# define GPHEN0		GPIO_BASE + 0x64
# define GPHEN1		GPIO_BASE + 0x68
# define GPLEN0		GPIO_BASE + 0x70
# define GPLEN1		GPIO_BASE + 0x74
# define GPAREN0	GPIO_BASE + 0x7C
# define GPAREN1	GPIO_BASE + 0x80
# define GPAFEN0	GPIO_BASE + 0x88
# define GPAFEN1	GPIO_BASE + 0x8C
# define GPPUD		GPIO_BASE + 0x94
# define GPPUDCLK0	GPIO_BASE + 0x98
# define GPPUDCLK1	GPIO_BASE + 0x9C

# define UART0_BASE	GPIO_BASE + 0x1000
# define UART0_DR	UART0_BASE		/* Data Register */
# define UART0_RSRECR	UART0_BASE + 0x04	/* ???? */
# define UART0_FR	UART0_BASE + 0x18	/* Flag register */
# define UART0_ILPR	UART0_BASE + 0x20	/* not in use ????? */
# define UART0_IBRD	UART0_BASE + 0x24	/* Integer Baudrate divisor */
# define UART0_FBRD	UART0_BASE + 0x28	/* Fractional Baudrate divisor */
# define UART0_LCRH	UART0_BASE + 0x2C	/* Line Control Register */
# define UART0_CR	UART0_BASE + 0x30	/* Control Register */
# define UART0_IFLS	UART0_BASE + 0x34	/* Interupt FIFO Level Select Register */
# define UART0_IMSC	UART0_BASE + 0x38	/* Interupt Mask Set Clear Register */
# define UART0_RIS	UART0_BASE + 0x3C	/* Raw Interupt Status Register */
# define UART0_MIS	UART0_BASE + 0x40	/* Masked Interupt Status Register */
# define UART0_ICR	UART0_BASE + 0x44	/* Interupt Clear Register */
# define UART0_DMACR	UART0_BASE + 0x48	/* DMA Control Register */
# define UART0_ITCR	UART0_BASE + 0x80	/* Test Control Register */
# define UART0_ITIP	UART0_BASE + 0x84	/* Integration test input reg */
# define UART0_ITOP	UART0_BASE + 0x88	/* Integration test output reg */
# define UART0_TDR	UART0_BASE + 0x8C	/* Test Data reg */

extern uint32_t	g_mmio_base;
extern uint16_t	g_board;

#endif /* !_AARCH64_RPI_H_ */
