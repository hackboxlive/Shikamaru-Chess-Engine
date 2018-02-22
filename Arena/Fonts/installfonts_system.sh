#!/bin/bash

# this script requires superuser privileges.
# copy font files to system folder, so that Arena can use it:

# f='dirname $0'
# echo $f

# MY_ROOT=$(dirname $MY_PATH)
# echo -e "CWD \t$MY_ROOT"

script_dir=$(dirname "$0")
echo copying from: $script_dir

# echo ${0%%/*}
sudo cp $script_dir/*.TTF /usr/share/fonts/truetype
sudo cp $script_dir/*.ttf /usr/share/fonts/truetype
echo please restart Arena after the command is finished
read -p "Press [Enter] key to finish."

# please restart Arena after the command is finished
 

