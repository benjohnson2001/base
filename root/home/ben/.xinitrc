xset fp+ /home/ben/.fonts
xset fp rehash
urxvtd -q -o -f
clockmenu_update 2> /dev/null &
exec dwm 2> /dev/null
