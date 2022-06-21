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

#ifndef _I686_VGA_H_
# define _I686_VGA_H_ 1

# define VGA_COLOR_BLACK 0x0
# define VGA_COLOR_BLUE 0x1
# define VGA_COLOR_GREEN 0x2
# define VGA_COLOR_CYAN 0x3
# define VGA_COLOR_RED 0x4
# define VGA_COLOR_MAGENTA 0x5
# define VGA_COLOR_BROWN 0x6
# define VGA_COLOR_LIGHT_GRAY 0x7
# define VGA_COLOR_DARK_GRAY 0x8
# define VGA_COLOR_LIGHT_BLUE 0x9
# define VGA_COLOR_LIGHT_GREEN 0xA
# define VGA_COLOR_LIGHT_CYAN 0xB
# define VGA_COLOR_LIGHT_RED 0xC
# define VGA_COLOR_LIGHT_MAGENTA 0xD
# define VGA_COLOR_YELLOW 0xE
# define VGA_COLOR_WHITE 0xF

void vga_puts(const char *, uint8_t, uint8_t);
void vga_putchar(char, uint8_t, uint8_t);
void vga_clear(void);

#endif /* !_I686_VGA_H_ */
