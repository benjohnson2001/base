#!/bin/sh

# This script launches the current time as a thingmenu button that will launch a floating calendar window when pressed
# and will kill the same calendar window when it is pressed again
# ---------------------------------------------

POSARGS="-s -x -ww 1.0 -wh 1.0 -g -0-0"

case "$1" in
	"options")
		clockmenu $POSARGS -- \
            "$2" "ps aux | grep 'urxvt -hold +sb +bc -cr black -geometry 66x8-3-17 -title cal -e sh -c cal -3 && xdotool key Shift+Prior && /home/ben/clockmenu/clock-menu.sh options' | awk '{print \$2}' | xargs kill"
		;;
	*)
		clockmenu $POSARGS -- \
			"$(date +%_I:%M)" "urxvt -hold +sb +bc -cr black -geometry 66x8-3-17 -title cal -e sh -c \"cal -3 && xdotool key Shift+Prior && /home/ben/clockmenu/clock-menu.sh options $(date +%_I:%M) 2> /dev/null\""
		;;
esac


# command-line version left here for reference
# ---------------------------------------------
# clockmenu -s -x -ww 1.0 -wh 1.0 -g -0-0 "$(date +%_I:%M)" "urxvt +sb +bc -cr black -geometry 66x8-3-17 -title cal -e sh -c \"cal -3 && xdotool key Shift+Prior && sleep 600\"" 2> /dev/null




