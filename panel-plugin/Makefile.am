plugindir = $(libdir)/xfce4/panel/plugins
plugin_LTLIBRARIES = libnvgpumemgraph.la

libnvgpumemgraph_la_CFLAGS =							\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"		\
	@LIBXFCE4UI_CFLAGS@							\
	@LIBXFCE4PANEL_CFLAGS@

libnvgpumemgraph_la_LIBADD =							\
	@LIBXFCE4UI_LIBS@							\
	@LIBXFCE4PANEL_LIBS@

libnvgpumemgraph_la_SOURCES =						\
	mode.c										\
	mode.h										\
	cpu.c										\
	cpu.h										\
	os.c										\
	os.h										\
	properties.c								\
	properties.h								\
	settings.c									\
	settings.h

libnvgpumemgraph_la_LDFLAGS =	\
	-avoid-version	\
	-module	\
	-no-undefined	\
	-export-symbols-regex '^xfce_panel_module_(preinit|init|construct)'	\
	$(PLATFORM_LDFLAGS)

#
# .desktop file
#
desktop_in_files = nvgpumemgraph.desktop.in

desktopdir = $(datadir)/xfce4/panel/plugins
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST = $(desktop_in_files)

DISTCLEANFILES = $(desktop_DATA)
