#!/bin/bash

echo "System Update!"

############
# PASSWORD #
############
read -s -p "Please enter your password : " PASSWORD
echo "  "

###################
# UPDATING SYSTEM #
###################
echo -e "Updating your system..."
sleep 3

echo $PASSWORD | sudo -S pacman -Syu 2> /dev/null

echo $PASSWORD | sudo -S yay -Syu 2> /dev/null

###############################
# CLEANUP PACMAN DEPENDENCIES #
###############################
echo -e "Removing Orphaned Packages..."
sleep 3

echo $PASSWORD | sudo -S pacman -Rns $(pacman -Qtdq) --noconfirm 2> /dev/null

############################
# CLEANUP AUR DEPENDENCIES #
############################
echo -e "Removing Unused AUR dependencies..."
sleep 3

echo $PASSWORD | sudo -S yay -Yc --noconfirm  2> /dev/null

echo -e "Cleanup is complete!"
sleep 3
exit
