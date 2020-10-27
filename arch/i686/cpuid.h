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

#ifndef _X86_64_CPUID_H_
# define _X86_64_CPUID_H_ 1

# define INTEL_MAGIC 0x756E6547
# define AMD_MAGIC 0x68747541

# define cpuid(in, a, b, c, d) __asm__( \
    "cpuid": "=a"(a), "=b"(b), "=c"(c), "=d"(d) : "a"(in))

void            cpuid_dump_info(void);

#endif							/* !_X86_64_CPUID_H_ */
