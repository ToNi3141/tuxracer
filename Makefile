# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ..
prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/tuxracer
pkglibdir = $(libdir)/tuxracer
pkgincludedir = $(includedir)/tuxracer

top_builddir = ..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = x86_64-apple-darwin19.6.0
host_triplet = x86_64-apple-darwin19.6.0
CC = gcc
CXX = c++
MAKEINFO = makeinfo
PACKAGE = tuxracer
RANLIB = ranlib
SDL_CFLAGS = -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
SDL_CONFIG = /opt/local/bin/sdl-config
SDL_LIBS = -L/opt/local/lib -lSDLmain -Wl,-framework,AppKit -lSDL -Wl,-framework,Cocoa
TR_CFLAGS = -O2 -Wall -fomit-frame-pointer -ffast-math -fexpensive-optimizations -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
TR_CPPFLAGS =  -DTUXRACER_NO_ASSERT=1  -DTCL_HEADER=\<tcl.h\> -DHAVE_SDL=1 -I/usr/X11R6/include
TR_CXXFLAGS = -O2 -Wall -fomit-frame-pointer -ffast-math -fexpensive-optimizations -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
TR_LIBS =  -ldl -lm  -ltcl -L/opt/local/lib -lSDLmain -Wl,-framework,AppKit -lSDL -Wl,-framework,Cocoa -lglu32
VERSION = 0.61

bin_PROGRAMS = tuxracer

tuxracer_SOURCES =  	alglib.c					alglib.h					audio.c						audio.h						audio_data.c					audio_data.h					button.c					button.h					course_load.c					course_load.h					course_mgr.c					course_mgr.h					course_quad.cpp					course_quad.h					course_render.c					course_render.h					credits.c					credits.h					debug.c						debug.h						error_util.c					error_util.h					event_select.c					event_select.h					file_util.c					file_util.h					fog.c						fog.h						fonts.c						fonts.h						fps.c						fps.h					        game_config.c				        game_config.h				        game_logic_util.c			        game_logic_util.h			        game_type_select.c			        game_type_select.h			        game_over.c				        game_over.h					gauss.c						gauss.h						gl_util.c					gl_util.h					hash.c						hash.h						hier.c						hier.h						hier_cb.c					hier_cb.h					hier_util.c					hier_util.h					hud.c						hud.h						image.c						image.h						intro.c						intro.h						joystick.c					joystick.h					keyboard.c					keyboard.h					keyboard_util.c					keyboard_util.h					keyframe.c					keyframe.h					lights.c					lights.h				        list.c					        list.h					        listbox.c				        listbox.h					loading.c					loading.h					loop.c						loop.h						main.c						mirror_course.c					mirror_course.h					multiplayer.c					multiplayer.h				        nmrcl.c					        nmrcl.h					        os_util.c				        os_util.h					part_sys.c					part_sys.h					paused.c					paused.h					phys_sim.c					phys_sim.h					pic.c						pic.h						preview.c					preview.h					quadgeom.cpp					quadgeom.hpp					quadtree.cpp					quadtree.hpp					race_select.c					race_select.h					racing.c					racing.h					render_util.c					render_util.h					reset.h					        reset.c						save.h						save.c						screenshot.c					screenshot.h					splash_screen.c					splash_screen.h					ssbutton.c					ssbutton.h					string_util.c					string_util.h					tcl_util.c					tcl_util.h					tex_font_metrics.c				tex_font_metrics.h				textarea.c					textarea.h					textures.c					textures.h				        track_marks.c				        track_marks.h					tux.c						tux.h					        tux_shadow.c				        tux_shadow.h					tux_types.h					tuxracer.h					ui_mgr.c					ui_mgr.h					ui_snow.c					ui_snow.h					ui_theme.c					ui_theme.h					view.c						view.h						viewfrustum.c					viewfrustum.h					winsys.c					winsys.h

mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(bin_PROGRAMS)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS =   -DTUXRACER_NO_ASSERT=1  -DTCL_HEADER=\<tcl.h\> -DHAVE_SDL=1 -I/usr/X11R6/include
LDFLAGS = 
LIBS =   -ldl -lm  -ltcl -L/opt/local/lib -lSDLmain -Wl,-framework,AppKit -lSDL -Wl,-framework,Cocoa -lglu32
X_CFLAGS = 
X_LIBS = 
X_EXTRA_LIBS = 
X_PRE_LIBS = 
tuxracer_OBJECTS =  alglib.o audio.o audio_data.o button.o course_load.o \
course_mgr.o course_quad.o course_render.o credits.o debug.o \
error_util.o event_select.o file_util.o fog.o fonts.o fps.o \
game_config.o game_logic_util.o game_type_select.o game_over.o gauss.o \
gl_util.o hash.o hier.o hier_cb.o hier_util.o hud.o image.o intro.o \
joystick.o keyboard.o keyboard_util.o keyframe.o lights.o list.o \
listbox.o loading.o loop.o main.o mirror_course.o multiplayer.o nmrcl.o \
os_util.o part_sys.o paused.o phys_sim.o pic.o preview.o quadgeom.o \
quadtree.o race_select.o racing.o render_util.o reset.o save.o \
screenshot.o splash_screen.o ssbutton.o string_util.o tcl_util.o \
tex_font_metrics.o textarea.o textures.o track_marks.o tux.o \
tux_shadow.o ui_mgr.o ui_snow.o ui_theme.o view.o viewfrustum.o \
winsys.o
tuxracer_LDADD = $(LDADD)
tuxracer_DEPENDENCIES = 
tuxracer_LDFLAGS = 
CXXFLAGS =  -O2 -Wall -fomit-frame-pointer -ffast-math -fexpensive-optimizations -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
CXXCOMPILE = $(CXX) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@
CFLAGS =  -O2 -Wall -fomit-frame-pointer -ffast-math -fexpensive-optimizations -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(tuxracer_SOURCES)
OBJECTS = $(tuxracer_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .cpp .o .s
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps src/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-binPROGRAMS:

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

distclean-binPROGRAMS:

maintainer-clean-binPROGRAMS:

install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(bin_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

tuxracer: $(tuxracer_OBJECTS) $(tuxracer_DEPENDENCIES)
	@rm -f tuxracer
	$(CXXLINK) $(tuxracer_LDFLAGS) $(tuxracer_OBJECTS) $(tuxracer_LDADD) $(LIBS)
.cpp.o:
	$(CXXCOMPILE) -c $<

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = src

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
alglib.o: alglib.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h gauss.h
audio.o: audio.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h audio_data.h hash.h
audio_data.o: audio_data.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio_data.h audio.h hash.h
button.o: button.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h button.h fonts.h textures.h ui_mgr.h
course_load.o: course_load.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h course_load.h course_render.h course_quad.h \
	image.h textures.h phys_sim.h tcl_util.h keyframe.h gl_util.h \
	lights.h fog.h part_sys.h multiplayer.h audio_data.h \
	track_marks.h
course_mgr.o: course_mgr.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h course_mgr.h tcl_util.h textures.h save.h \
	multiplayer.h
course_quad.o: course_quad.cpp tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h course_load.h quadtree.hpp \
	viewfrustum.h
course_render.o: course_render.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h course_load.h course_render.h \
	textures.h phys_sim.h hier_util.h gl_util.h render_util.h fog.h \
	course_quad.h viewfrustum.h track_marks.h
credits.o: credits.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h multiplayer.h gl_util.h fps.h \
	render_util.h phys_sim.h course_load.h view.h course_render.h \
	tux.h tux_shadow.h keyboard.h loop.h fog.h viewfrustum.h hud.h \
	game_logic_util.h fonts.h ui_mgr.h ui_theme.h ui_snow.h \
	joystick.h
debug.o: debug.c debug.h tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h \
	error_util.h os_util.h
error_util.o: error_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h
event_select.o: event_select.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h event_select.h ui_mgr.h \
	ui_theme.h button.h listbox.h loop.h render_util.h audio.h \
	gl_util.h keyboard.h multiplayer.h course_load.h fonts.h \
	textures.h course_mgr.h save.h ui_snow.h joystick.h
file_util.o: file_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h
fog.o: fog.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	fog.h gl_util.h tcl_util.h
fonts.o: fonts.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h fonts.h image.h hash.h tex_font_metrics.h \
	textures.h tcl_util.h render_util.h
fps.o: fps.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	fps.h render_util.h
game_config.o: game_config.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h
game_logic_util.o: game_logic_util.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h game_logic_util.h multiplayer.h \
	course_mgr.h save.h
game_over.o: game_over.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h multiplayer.h gl_util.h fps.h \
	render_util.h phys_sim.h course_load.h view.h course_render.h \
	tux.h tux_shadow.h keyboard.h loop.h fog.h viewfrustum.h hud.h \
	game_logic_util.h fonts.h ui_mgr.h joystick.h part_sys.h
game_type_select.o: game_type_select.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h game_type_select.h ui_mgr.h \
	ui_theme.h button.h loop.h render_util.h audio.h gl_util.h \
	keyboard.h multiplayer.h ui_snow.h joystick.h
gauss.o: gauss.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h gauss.h
gl_util.o: gl_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h gl_util.h
hash.o: hash.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	hash.h
hier.o: hier.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	hier.h hier_util.h
hier_cb.o: hier_cb.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h hier.h tcl_util.h
hier_util.o: hier_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h render_util.h hier.h
hud.o: hud.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	fonts.h gl_util.h textures.h fps.h phys_sim.h course_load.h \
	multiplayer.h ui_mgr.h game_logic_util.h
image.o: image.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h image.h
intro.o: intro.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h keyframe.h course_render.h multiplayer.h \
	gl_util.h fps.h loop.h render_util.h view.h tux.h tux_shadow.h \
	fog.h viewfrustum.h keyboard.h hud.h phys_sim.h course_load.h \
	part_sys.h joystick.h
joystick.o: joystick.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h joystick.h
keyboard.o: keyboard.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h keyboard.h keyboard_util.h loop.h
keyboard_util.o: keyboard_util.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h keyboard_util.h
keyframe.o: keyframe.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h tux.h phys_sim.h course_load.h hier.h loop.h
lights.o: lights.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h lights.h gl_util.h tcl_util.h
list.o: list.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h
listbox.o: listbox.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h listbox.h fonts.h ui_mgr.h ui_theme.h \
	render_util.h button.h
loading.o: loading.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h multiplayer.h gl_util.h fps.h \
	render_util.h phys_sim.h course_load.h view.h course_render.h \
	tux.h tux_shadow.h keyboard.h loop.h fog.h viewfrustum.h hud.h \
	game_logic_util.h fonts.h ui_mgr.h ui_snow.h ui_theme.h \
	joystick.h part_sys.h
loop.o: loop.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	loop.h ui_mgr.h
main.o: main.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	course_load.h course_render.h textures.h fonts.h tux.h \
	phys_sim.h part_sys.h keyframe.h preview.h gl_util.h loop.h \
	render_util.h splash_screen.h intro.h racing.h game_over.h \
	paused.h reset.h keyboard.h fog.h lights.h multiplayer.h \
	audio_data.h audio.h ui_mgr.h course_mgr.h game_type_select.h \
	race_select.h event_select.h save.h credits.h joystick.h \
	os_util.h loading.h tcl_util.h
mirror_course.o: mirror_course.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h course_load.h course_render.h \
	keyframe.h phys_sim.h course_quad.h multiplayer.h track_marks.h
multiplayer.o: multiplayer.c
nmrcl.o: nmrcl.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h nmrcl.h
os_util.o: os_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h
part_sys.o: part_sys.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h part_sys.h phys_sim.h course_load.h gl_util.h \
	tcl_util.h course_render.h render_util.h textures.h
paused.o: paused.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h multiplayer.h gl_util.h fps.h \
	render_util.h phys_sim.h course_load.h view.h course_render.h \
	tux.h tux_shadow.h keyboard.h loop.h fog.h viewfrustum.h hud.h \
	part_sys.h game_logic_util.h fonts.h ui_mgr.h joystick.h
phys_sim.o: phys_sim.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h course_load.h course_render.h hier.h hier_util.h \
	tux.h part_sys.h phys_sim.h nmrcl.h audio.h loop.h
pic.o: pic.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	pic.h
preview.o: preview.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h course_load.h view.h
quadgeom.o: quadgeom.cpp quadgeom.hpp tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h
quadtree.o: quadtree.cpp tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h textures.h course_load.h fog.h gl_util.h \
	course_render.h quadtree.hpp viewfrustum.h quadgeom.hpp
race_select.o: race_select.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h race_select.h ui_mgr.h ui_theme.h button.h \
	ssbutton.h listbox.h loop.h render_util.h audio.h gl_util.h \
	keyboard.h multiplayer.h course_load.h fonts.h textures.h \
	course_mgr.h textarea.h save.h game_logic_util.h ui_snow.h \
	joystick.h
racing.o: racing.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h keyboard.h keyframe.h course_render.h \
	multiplayer.h gl_util.h fps.h loop.h render_util.h view.h tux.h \
	tux_shadow.h phys_sim.h course_load.h part_sys.h screenshot.h \
	fog.h viewfrustum.h track_marks.h hud.h joystick.h
render_util.o: render_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h gl_util.h render_util.h textures.h ui_theme.h
reset.o: reset.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h multiplayer.h gl_util.h fps.h \
	render_util.h phys_sim.h course_load.h view.h course_render.h \
	tux.h tux_shadow.h loop.h fog.h viewfrustum.h hud.h
save.o: save.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	save.h hash.h
screenshot.o: screenshot.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h screenshot.h pic.h
splash_screen.o: splash_screen.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h audio.h keyboard.h gl_util.h \
	fps.h loop.h render_util.h textures.h multiplayer.h ui_mgr.h \
	ui_snow.h
ssbutton.o: ssbutton.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h ssbutton.h button.h ui_mgr.h ui_theme.h
string_util.o: string_util.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h
tcl_util.o: tcl_util.c tcl_util.h tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h
tex_font_metrics.o: tex_font_metrics.c tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h tex_font_metrics.h
textarea.o: textarea.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h textarea.h ui_mgr.h ui_theme.h button.h fonts.h \
	render_util.h
textures.o: textures.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h textures.h image.h hash.h
track_marks.o: track_marks.c track_marks.h tuxracer.h ../config.h \
	winsys.h tux_types.h string_util.h file_util.h list.h \
	game_config.h alglib.h debug.h error_util.h gl_util.h tux.h \
	hier.h phys_sim.h course_load.h textures.h course_render.h \
	render_util.h
tux.o: tux.c lights.h tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h hier_cb.h hier.h gl_util.h
tux_shadow.o: tux_shadow.c tux_shadow.h tuxracer.h ../config.h winsys.h \
	tux_types.h string_util.h file_util.h list.h game_config.h \
	alglib.h debug.h error_util.h gl_util.h tux.h hier.h phys_sim.h \
	course_load.h textures.h
ui_mgr.o: ui_mgr.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h ui_mgr.h hash.h textures.h ui_snow.h loop.h
ui_snow.o: ui_snow.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h ui_snow.h gl_util.h course_render.h render_util.h \
	textures.h ui_mgr.h loop.h
ui_theme.o: ui_theme.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h ui_theme.h textures.h
view.o: view.c tuxracer.h ../config.h winsys.h tux_types.h string_util.h \
	file_util.h list.h game_config.h alglib.h debug.h error_util.h \
	view.h phys_sim.h course_load.h tux.h hier.h
viewfrustum.o: viewfrustum.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h viewfrustum.h
winsys.o: winsys.c tuxracer.h ../config.h winsys.h tux_types.h \
	string_util.h file_util.h list.h game_config.h alglib.h debug.h \
	error_util.h audio.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am: install-binPROGRAMS
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-binPROGRAMS
uninstall: uninstall-am
all-am: Makefile $(PROGRAMS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(bindir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-binPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-binPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-binPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-binPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-binPROGRAMS distclean-binPROGRAMS clean-binPROGRAMS \
maintainer-clean-binPROGRAMS uninstall-binPROGRAMS install-binPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
