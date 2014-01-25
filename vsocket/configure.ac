#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libvsocket], [0.0.4], [info@fortmax.se])
AM_INIT_AUTOMAKE(libvsocket, 0.0.4)
LT_INIT
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcrypto':
AC_CHECK_LIB([crypto], [main])
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])
# FIXME: Replace `main' with a function in `-lrt':
AC_CHECK_LIB([rt], [main])
# FIXME: Replace `main' with a function in `-lsocket':
AC_CHECK_LIB([socket], [main])
# FIXME: Replace `main' with a function in `-lssl':
AC_CHECK_LIB([ssl], [main])
# FIXME: Replace `main' with a function in `-ludt':
AC_CHECK_LIB([udt], [main])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h stdint.h stdlib.h sys/ioctl.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_FUNCS([bzero gethostbyname gettimeofday inet_ntoa memset socket strerror])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
