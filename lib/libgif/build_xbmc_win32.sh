#!/bin/bash

MAKEFLAGS=""
BGPROCESSFILE="$2"

if [ "$1" == "clean" ]
then
  if [ -d .libs ]
  then
    rm -r .libs
  fi
  mingw32-make distclean
fi

if [ $NUMBER_OF_PROCESSORS > 1 ]; then
  MAKEFLAGS=-j$NUMBER_OF_PROCESSORS
fi

if [ ! -d .libs ]; then
  mkdir .libs
fi

./configure &&
 
mingw32-make &&
cp lib/.libs/libgif-6.dll /xbmc/system/libgif.dll &&

#remove the bgprocessfile for signaling the process end
rm $BGPROCESSFILE
