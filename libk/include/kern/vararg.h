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

#ifndef _KERN_VARARG_H_
# define _KERN_VARARG_H_ 1

# define va_list __builtin_va_list
# define va_start(v, f) __builtin_va_start(v, f)
# define va_end(v) __builtin_va_end(v)
# define va_arg(v, a) __builtin_va_arg(v, a)

#endif							/* !_VARARG_LOGGER_H_ */
