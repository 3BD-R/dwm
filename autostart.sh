#!/bin/bash


setxkbmap -layout "us,ara" -option "grp:win_space_toggle" &

# conky -qc  ~/MyConkyConfig/.centerclock.conf --pause=1 &

# albert &

#run conky from dwm status bar#
#conky -qc  ~/MyConkyConfig/conkydwm.conf --pause=1 | while read -r ; do xsetroot -name "$REPLY"; done &

#redshift -O 3000 &

#sh ~/.sh/fehbg &

# libinput-gestures-setup start &

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &

#numlockx &

slstatus &

rfkill block bluetooth &

#picom &

#my script

# sh ~/.dwm/bar &
