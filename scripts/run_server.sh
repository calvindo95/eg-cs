#!/bin/sh

if [ -f ./build/source/egs ];
then
    ./build/source/egs
else
    echo "./build/source/egs not found"
    exit
fi