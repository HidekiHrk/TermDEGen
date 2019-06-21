#!/bin/bash

if [ -f "/usr/bin/tdgen" ]; then
    rm "/usr/bin/tdgen"
fi

if [ ! -f "/usr/bin/tdgen" ]; then
    echo "Sucessfully uninstalled!"
else
    echo "Uninstall failed :(\nPlease, try running as root!"
fi