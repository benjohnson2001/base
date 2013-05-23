#!/bin/bash

mkdir /var/cache/flashplugin-nonfree/
cp ./install_flash_player_11_linux.i386.tar.gz /var/cache/flashplugin-nonfree/install_flash_player_11_linux.i386.tar.gz
dpkg -i libnss3-1d_3.12.8-1+squeeze6_i386.deb
dpkg -i flashplugin-nonfree_1%3a2.8.2+squeeze1_i386.deb


