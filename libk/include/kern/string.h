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

#ifndef _KERN_STRING_H_
# define _KERN_STRING_H_ 1

char           *itoa(int, char *, int);
char           *strrev(char *);
int             strlen(const char *);
void           *memset(void *, int, unsigned int);
void            bzero(void *, unsigned int);

#endif							/* !_KERN_STRING_H_ */
