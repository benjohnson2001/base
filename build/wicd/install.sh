#!/bin/bash

# wicd
dpkg -i python-dbus_0.83.1-1_i386.deb
dpkg -i python-notify_0.1.1-2+b2_i386.deb
dpkg -i python-wicd_1.7.0+ds1-5+squeeze3_all.deb
dpkg -i python-iniparse_0.3.2-1_all.deb
dpkg -i wicd-daemon_1.7.0+ds1-5+squeeze3_all.deb
dpkg -i wicd-gtk_1.7.0+ds1-5+squeeze3_all.deb
dpkg -i wicd_1.7.0+ds1-5+squeeze3_all.deb

# the current version of python-urwid doesn't work with wicd-curses therefore we build from source
# but we still install the old package so apt-get doesn't yell at us
dpkg -i python-urwid_0.9.9.1-1_i386.deb

cd urwid-1.0.2
python setup.py install
cd ..

dpkg -i wicd-curses_1.7.0+ds1-5+squeeze3_all.deb

# gksu
dpkg -i libgtop2-common_2.28.1-1_all.deb
dpkg -i libgtop2-7_2.28.1-1_i386.deb
dpkg -i libgksu2-0_2.0.13~pre1-3_i386.deb
dpkg -i gksu_2.0.2-5_i386.deb



