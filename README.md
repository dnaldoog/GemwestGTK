#GEMWEST

#NOTE

(When installing on Windows 10 move all file from C:\Program Files (x86)\gemwest to C:\Program Files\gemwest)

Linux requires GTK+-2.0 development libraries and pkg-config

eg Debian/Ubuntu apt-get install libgnomevfs2-dev libgtk2.0-dev
eg Fedora/Red Hat yum install pkgconfig gtk2-devel gnome-vfs2-devel

$ ./configure
$ make
# make install

See Windows README in source folder win32 for building in Windows
or download Windows installable file GemWest-setup_0.9.9.zip
from http://gemwest.sourceforge.net

NOTE:

If you want to compile the interface.glade XML file into the executable
so that the glade (XML) is not loaded at run time
run this file 'glade2string.py' 

$ python glade2string.py

(make sure it is executable chmod+x (requires python))
Change the variable XML2FILE in src/header.h to TRUE ie (1) for either Windows/Linux or both
