#!/bin/sh

. $HOME/eg-cs/scripts/egcs.env

if [ -f $EGCS_EXEC ];
then
    $EGCS_EXEC
else
    echo "$EGCS_EXEC not found"
    exit
fi