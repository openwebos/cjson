# Use of this file is subject to license terms as set forth in the file COPYING found in this directory.

## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall -std=gnu99 -D_GNU_SOURCE -D_REENTRANT -Werror

EXTRA_DIST = README.md

lib_LTLIBRARIES = libcjson.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = cjson.pc

libcjsonincludedir = $(includedir)/cjson
libcjsoninclude_HEADERS = \
        json.h \
	bits.h \
	debug.h \
	linkhash.h \
	arraylist.h \
	json_util.h \
	json_object.h \
	json_object_iterator.h \
	json_tokener.h \
	printbuf.h

## Set the library version to the package version from AC_INIT (see
## configure.in)
libcjson_la_LDFLAGS = -version-number @CJSON_VERSION_NUMBER@

libcjson_la_SOURCES = \
	arraylist.c \
	debug.c \
	json_object.c \
	json_object_iterator.c \
	json_tokener.c \
	json_util.c \
	linkhash.c \
	printbuf.c

check_PROGRAMS = test1 test2 test3orig test3 test5

test1_SOURCES = test1.c
test1_LDADD = $(lib_LTLIBRARIES)

test2_SOURCES = test2.c
test2_LDADD = $(lib_LTLIBRARIES)

test3orig_SOURCES = test3orig.c
test3orig_LDADD = $(lib_LTLIBRARIES)

test3_SOURCES = test3.c
test3_LDADD = $(lib_LTLIBRARIES)

test5_SOURCES = test5.c
test5_LDADD = $(lib_LTLIBRARIES)

.PHONY: doc
doc:
	(cat Doxyfile ; echo 'PROJECT_NUMBER=$(PACKAGE_VERSION)') | doxygen -

clean-local:
	[ -n "$(top_srcdir)" ] && rm -rf $(top_srcdir)/doc

# We ignore the automake heuristic for the maintainer-clean target (see
# http://www.gnu.org/software/automake/manual/automake.html#Clean) and
# remove everything created by autogen.sh .
AUTOGEN_CREATED = INSTALL m4 configure Makefile.in depcomp config.guess config.sub missing aclocal.m4 install-sh ltmain.sh config.h.in config.h.in~
maintainer-clean-local:
	[ -n "$(top_srcdir)" ] && cd $(top_srcdir) && rm -rf $(AUTOGEN_CREATED)
