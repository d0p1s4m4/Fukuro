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

	.section ".text.boot"

	.extern __stack_top
	.extern __bss_begin
	.extern __bss_end
	.extern kmain

	.globl _entry

_entry:
	la sp, __stack_top

	la t0, __bss_begin
	la t1, __bss_end

	bltu t1, t0, 2f
1:
	sw x0, (t0)
	addi t0, t0, 4
	bltu t0, t1, 1b
2:
	call kmain

hang:
	j hang
