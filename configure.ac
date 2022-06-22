m4_define([fukuro_VERSION],
    m4_esyscmd([build-aux/git-version]))
AC_INIT([Fukuro],
    m4_defn([fukuro_VERSION]),
    [https://github.com/d0p1s4m4/Fukuro/issues])
AC_COPYRIGHT([Copyright (C) 2023 d0p1])

CFLAGS="-ffreestanding -nostdlib -fno-builtin"

AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([foreign subdir-objects])

dnl overide default AC_LANG_PROGRAM(C) macro
m4_ifdef([AC_LANG_PROGRAM(c)], m4_undefine[AC_LANG_PROGRAM(c)])
m4_define([AC_LANG_PROGRAM(C)],
[$1

int
_start (void)
{
$2
  ;
  return 0;
}])

AC_CANONICAL_HOST

AS_CASE([$host_cpu],
    [i?86], [
        systype=i686
    ],
    [x86_64], [systype=amd64],
    [systype=$host_cpu]
)
AC_SUBST([systype])

m4_include([sys/configfrag.ac])

AS_IF([! test -d "$srcdir/sys/$systype"],
    [AC_MSG_ERROR(["$host_cpu isn't supported by Fukuro"])])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile lib/Makefile srv/Makefile sys/Makefile])

AC_LANG([C])
save_cross_compiling=$cross_compiling
cross_compiling=yes
AM_PROG_AS
cross_compiling=$save_cross_compiling
AC_PROG_CC
AC_PROG_CPP
AC_PROG_RANLIB
AC_PROG_LN_S
AC_PROG_MKDIR_P
AC_PROG_CC_C_O
AM_PROG_AR

AC_CHECK_TOOL([STRIP], [strip])
AC_CHECK_TOOL([OBJCOPY], [objcopy])
AC_CHECK_PROG([GZIP], [gzip], [gzip])
AC_CHECK_PROG([QEMU], [qemu-system-$host_cpu], [qemu-system-$host_cpu])
AC_CHECK_PROG([PYTHON3], [python3], [python3])
AC_CHECK_PROG([DOXYGEN], [doxygen], [doxygen])

AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_C_BIGENDIAN
AC_CHECK_HEADERS([stdarg.h])
AC_C_STRINGIZE

AC_CHECK_TYPE(uintptr_t)
AC_TYPE_SIZE_T

AC_CONFIG_LINKS(["sys/machine":"$srcdir/sys/$systype"])

AC_ARG_ENABLE([ncpus],
	AS_HELP_STRING([--enable-ncpus=N], []),
	[ncpu=$enable_ncpus]
	[ncpu=1])
AC_DEFINE_UNQUOTED([NCPUS], [$ncpus], [number of CPUs])

m4_include([srv/configfrag.ac])

AC_OUTPUT
AC_MSG_RESULT([
    Fukurō version: $PACKAGE_STRING
    Architecture:   $host_cpu

    C Compiler:     $CC
    Asm Compiler:   $CCAS

    CFLAGS:         $CFLAGS
    CCASFLAGS:      $CCASFLAG
    LDFLAGS:        $LDFLAGS
])
