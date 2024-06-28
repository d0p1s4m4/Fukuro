fukuro_SOURCES =

AM_CFLAGS = -I$(srcdir) -I$(srcdir)/include
AM_LDFLAGS = -nostdlib -T$(srcdir)/$(systype)/kernel.lds

if HOST_aarch64
include aarch64/Makefrag.am
endif

if HOST_amd64
include amd64/Makefrag.am
endif

if HOST_arm
include arm/Makefrag.am
endif

if HOST_i686
include i686/Makefrag.am
endif

if HOST_riscv
include riscv/Makefrag.am
endif

fukuro_SOURCES += main.c version.c

exec_bootdir = \
	$(exec_prefix)/boot
exec_boot_PROGRAMS = \
	fukuro
