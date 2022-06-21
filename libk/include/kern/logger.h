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

#ifndef _KERN_LOGGER_H_
# define _KERN_LOGGER_H_ 1

enum log_level {
	INFO,
	SUCCESS,
	WARNING,
	ERROR,
	NONE = -1
};

# ifndef NDEBUG
#  define LOG(level, ...) __log(level, __FILE__, __LINE__, __VA_ARGS__);
# else
#  define LOG(level, msg, ...)
# endif							/* !NDEBUG */

void __log(int, const char *, uint16_t, const char *, ...);

#endif /* !_KERN_LOGGER_H_ */
