#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([yviland], [0.1], [info@gunibert.de])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects foreign])
LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AM_PROG_VALAC([0.32])

# Checks for libraries.
PKG_CHECK_MODULES(YVILAND, [
			gio-2.0 >= 2.42
			glib-2.0
			gobject-2.0
			sdl2
			SDL2_image
            SDL2_ttf
			gee-0.8
			gxml-0.10
])

PKG_CHECK_MODULES(ENGINE, [
			gobject-2.0
			glib-2.0
			gee-0.8
])

PKG_CHECK_MODULES(TILED, [
			glib-2.0
			gobject-2.0
			gxml-0.10
			sdl2
])

# Checks for header files.
AC_CHECK_HEADERS([float.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 data/Makefile
                 m4/Makefile
                 src/Makefile
                 tmx/Makefile
								 engine/Makefile
                 vapi/Makefile])
AC_OUTPUT
