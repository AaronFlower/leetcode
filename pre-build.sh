#!/bin/bash
dir=`pwd`

glewc=`find lib/googletest -type d -maxdepth 0 | wc -l`

if [ $glewc -eq 0 ]; then
   echo "No googletest "
   git clone https://github.com/google/googletest.git lib/googletest
fi

if [ -d build ]
then
    cd build
    rm -rf *
else
    mkdir build
    cd build
fi
