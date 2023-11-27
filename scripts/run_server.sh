#!/bin/sh

. $HOME/eg-cs/scripts/egcs.env

if [ -f $EGS_EXEC ];
then
    $EGS_EXEC
else
    echo "$EGS_EXEC not found"
    exit
fi