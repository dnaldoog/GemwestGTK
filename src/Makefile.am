## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" 
bin_PROGRAMS = gemwest

gemwest_SOURCES = \
	main.c \
	header.h \
	functions.h \
	functions.c \
	pixmaps_c.h \
	pixmaps_s.h

LIBS = \
	`pkg-config gnome-vfs-2.0 --cflags --libs gtk+-2.0`

AM_CFLAGS =\
	-Wall \
	-g \
	`pkg-config gnome-vfs-2.0 --cflags --libs gtk+-2.0`

gemwest_CFLAGS= \
	-Wl,-export-dynamic \
	`pkg-config gnome-vfs-2.0 --cflags --libs gtk+-2.0`

gemwest_LDFLAGS = \
	-Wl,-export-dynamic

EXTRA_DIST = \
	main.c \
	header.h \
	functions.h \
	functions.c \
	pixmaps_c.h \
	pixmaps_s.h

DISTCLEANFILES = \
	Makefile.in
