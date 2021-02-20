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

#include <machine/types.h>
#include "vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static uint16_t *vram = (void *) 0xB8000;
static uint8_t  vga_x = 0;
static uint8_t  vga_y = 0;

void
vga_putchar(char c, uint8_t fg, uint8_t bg)
{
	uint8_t         color;

	if (c == '\n')
	{
		vga_y++;
		vga_x = 0;
	}
	else
	{
		color = fg | (bg << 4);
		vram[vga_y * VGA_WIDTH + vga_x] = c | (color << 8);
		vga_x++;
	}
}

void
vga_puts(const char *str, uint8_t fg, uint8_t bg)
{
	const char     *s;

	for (s = str; *s != '\0'; s++)
		vga_putchar(*s, fg, bg);

}


void
vga_clear(void)
{
	int             w;
	int             h;

	for (h = 0; h < VGA_HEIGHT; h++)
	{
		for (w = 0; w < VGA_WIDTH; w++)
		{
			vram[h * VGA_WIDTH + w] = 0x0020;
		}
	}
}
