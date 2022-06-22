#ifndef _AARCH64_SERIAL_H_
# define _AARCH64_SERIAL_H_ 1

void serial_init(void);
void serial_write(uint8_t);
uint8_t  serial_read(void);

#endif /* !_AARCH64_SERIAL_H_ */
