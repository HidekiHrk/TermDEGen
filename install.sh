#!/bin/bash
sh ./build.sh

mv ./build/tdgen /usr/bin/

if [ -f "/usr/bin/tdgen" ]; then
    echo "Sucessfully installed!"
else
    echo "Install Failed :(\nTry running with sudo perms xD"
fi

if [ -d "./build/" ]; then
    rm -R ./build/
fi