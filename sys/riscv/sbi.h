/*
 * Copyright © 2023, d0p1
 *
 * This file is part of Fukurō.
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://cecill.info". 
 * 
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 */
#ifndef FUKURO_SYS_RISCV_SBI_H
# define FUKURO_SYS_RISCV_SBI_H 1

# define SBI_SUCCESS               0
# define SBI_ERR_FAILED            -1
# define SBI_ERR_NOT_SUPPORTED     -2
# define SBI_ERR_INVALID_PARAM     -3
# define SBI_ERR_DENIED            -4
# define SBI_ERR_INVALID_ADDRESS   -5
# define SBI_ERR_ALREADY_AVAILABLE -6
# define SBI_ERR_ALREADY_STARTED   -7
# define SBI_ERR_ALREADY_STOPPED   -8
# define SBI_ERR_NO_SHMEM          -9

typedef struct 
{
	long error;
	long value;
} SbiRet;

# define SBI_EID_BASE_EXT           0x10
# define SBI_FID_GET_SPEC_VERSION   0x0
# define SBI_FID_GET_IMPLEM_ID      0x1
# define SBI_FID_GET_IMPLEM_VERSION 0x2
# define SBI_FID_PROBE_EXTENSION    0x3
# define SBI_FID_GET_MACHINE_VENDOR 0x4
# define SBI_FID_GET_MACHINE_ARCH   0x5
# define SBI_FID_GET_MACHINE_IMPLEM 0x6

enum
{
	SBI_IMPLEM_BBL = 0,
	SBI_IMPLEM_OPENSBI,
	SBI_IMPLEM_XVISOR,
	SBI_IMPLEM_KVM,
	SBI_IMPLEM_RUSTSBI,
	SBI_IMPLEM_DIOSIX,
	SBI_IMPLEM_COFFER,
	SBI_IMPLEM_XEN,
	SBI_IMPLEM_POLAFIRE
};

# define SBI_EID_LEGACY_SET_TIMER   0x00
# define SBI_EID_LEGACY_PUTCHAR     0x01
# define SBI_EID_LEGACY_GETCHAR     0x02
# define SBI_EID_LEGACY_CLEAR_IPI   0x03
# define SBI_EID_LEGACY_SHUTDOWN    0x08

# define SBI_EID_TIMER_EXT 0x54494D45
# define SBI_FID_SET_TIMER 0x0

# define SBI_EID_DEBUG_CONSOLE_EXT  0x4442434E
# define SBI_FID_CONSOLE_WRITE      0x0
# define SBI_FID_CONSOLE_READ       0x1
# define SBI_FID_CONSOLE_WRITE_BYTE 0x2

# define SBI_EID_SYSTEM_SUSPEND_EXT 0x53555350
# define SBI_FID_SYSTEM_SUSPEND     0x0

inline SbiRet
sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4,
		long arg5, long fid, long eid)
{
	SbiRet ret;
	register long a0 __asm__("a0") = arg0;
	register long a1 __asm__("a1") = arg1;
	register long a2 __asm__("a2") = arg2;
	register long a3 __asm__("a3") = arg3;
	register long a4 __asm__("a4") = arg4;
	register long a5 __asm__("a5") = arg5;
	register long a6 __asm__("a6") = fid;
	register long a7 __asm__("a7") = eid;

	__asm__ __volatile__("ecall"
							: "=r"(a0), "=r"(a1)
							: "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
							"r"(a6), "r"(a7)
							: "memory");
	ret.error = a0;
	ret.value = a1;
	return (ret);
}



#endif /* !FUKURO_SYS_RISCV_SBI_H */
