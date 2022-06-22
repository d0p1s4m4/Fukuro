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

#include <stdint.h>
#include <kern/logger.h>
#include "cpuid.h"

void cpuid_dump_info(void)
{
	uint32_t ebx;
	uint32_t unused;

	cpuid(0, unused, ebx, unused, unused);
	if (ebx == INTEL_MAGIC)
	{
		LOG(INFO, "Intel CPU detected!");
	}
	else if (ebx == AMD_MAGIC)
	{
		LOG(INFO, "AMD CPU detected!");
	}
	else
	{
		LOG(WARNING, "Unable to detect CPU!");
	}
}
