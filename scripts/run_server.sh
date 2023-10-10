#!/bin/sh

# START TNH SERVER SETTINGS
export TNH_IP=192.168.1.174
# END TNH SERVER SETTINGS

cd /home/webserver/source_directory

if [ -f ./build/src/tnh-server ];
then
    ./build/src/tnh-server
else
    echo "./build/src/tnh-server not found"
    exit
fi