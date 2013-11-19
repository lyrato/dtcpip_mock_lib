#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([dtcpip_mock_lib], [1.0], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/MockDLL.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
LT_INIT

AC_CANONICAL_HOST
AM_CONDITIONAL([LINUX],false)
case "$host" in
    *linux*)
        AC_DEFINE(LINUX,[1],[Linux Host])
        AM_CONDITIONAL([LINUX],true)
        ;;
esac

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

AM_INIT_AUTOMAKE
AM_PROG_CC_C_O

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([rmdir strchr strerror strstr])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
