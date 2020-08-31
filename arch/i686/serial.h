/*
 *   This file is part of Fukurō.
 *
 *   Fukurō is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   Fukurō is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Fukurō.  If not, see <https://www.gnu.org/licenses/>.
 */

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
