#ifndef _I686_SERIAL_H_
# define _I686_SERIAL_H_ 1

# define COM1 0x3F8
# define COM2 0x2F8
# define COM3 0x3E8
# define COM4 0x2E8

void            serial_init(uint16_t);
void            serial_write(uint16_t, uint8_t);
uint8_t         serial_read(uint16_t);

#endif							/* !_I686_SERIAL_H */
