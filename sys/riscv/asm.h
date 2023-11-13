#ifndef FUKURO_SYS_RISCV_ASM_H
# define FUKURO_SYS_RISCV_ASM_H 1

# ifndef __ASSEMBLY__

#  include <stdint.h>

typedef struct __attribute__((packed))
{
  uint32_t ra;
  uint32_t sp;
  uint32_t gp;
  uint32_t tp;
  uint32_t t0;
  uint32_t t1;
  uint32_t t2;
  uint32_t s0;
  uint32_t s1;
  uint32_t a0;
  uint32_t a1;
  uint32_t a2;
  uint32_t a3;
  uint32_t a4;
  uint32_t a5;
  uint32_t a6;
  uint32_t a7;
  uint32_t s2;
  uint32_t s3;
  uint32_t s4;
  uint32_t s5;
  uint32_t s6;
  uint32_t s7;
  uint32_t s8;
  uint32_t s9;
  uint32_t s10;
  uint32_t s11;
  uint32_t t3;
  uint32_t t4;
  uint32_t t5;
  uint32_t t9;
} TrapFrame;

# endif /* __ASSEMBLY__ */

#endif /* !FUKURO_SYS_RISCV_ASM_H */
