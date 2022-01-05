iconsdir = $(DESTDIR)$(pkgdatadir)/icons
#iconhdir = $(datadir)/icons

icons_DATA = gemwest.png \
	gemwest.svg \
	gemwest_16x16.png \
	gemwest_24x24.png \
	gemwest_32x32.png \
	gemwest_48x48.png
	
iconhdir = $(datadir)/pixmaps/
iconh_DATA = gemwest.png

iconh_16x16dir = $(datadir)/icons/hicolor/16x16/apps/
iconh_16x16_DATA = gemwest_16x16.png

iconh_24x24dir = $(datadir)/icons/hicolor/24x24/apps/
iconh_24x24_DATA = gemwest_24x24.png

iconh_32x32dir = $(datadir)/icons/hicolor/32x32/apps/
iconh_32x32_DATA = gemwest_32x32.png

iconh_48x48dir = $(datadir)/icons/hicolor/48x48/apps/
iconh_48x48_DATA = gemwest_48x48.png

iconh_scalabledir = $(datadir)/icons/hicolor/scalable/apps/
iconh_scalable_DATA = gemwest.svg

		$(mkdir_p) $(iconsdir); \
		$(INSTALL_DATA) $(srcdir)/icons $(iconsdir)/$(icons_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconhdir)/$(iconh_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconh_16x16dir)/$(iconh_16x16_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconh_24x24dir)/$(iconh_24x24_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconh_32x32dir)/$(iconh_32x32_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconh_48x48dir)/$(iconh_48x48_DATA);
		$(INSTALL_DATA) $(srcdir)/icons $(iconh_scalablexscalabledir)/$(iconh_scalablexscalable_DATA);

#gtk_update_icon_cache = gtk-update-icon-cache -f -t $(iconsdir)
gtk_update_icon_cache = gtk-update-icon-cache -f -t $(datadir)/icons

EXTRA_DIST = $(icons_DATA)
