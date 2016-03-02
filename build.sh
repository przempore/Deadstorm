#!/bin/bash

function buildAndMake {
  mkdir -p bin/
  cd bin
  cmake ..
  make
}

function remove {
  rm -rf bin/
}

if [ "$1" == "-b" ]; then
  buildAndMake
elif [ "$1" == "-r" ]; then
  if [ -e bin/game/Deadstorm ]; then
    bin/game/Deadstorm
  else
    echo "Can't run without build before."
  fi
elif [ "$1" == "-d" ]; then
  remove
elif [ "$1" == "-rb" ]; then
  remove
  buildAndMake
else 
  echo "  -b build
  -r run
  -d remove
  -rb rebuild"
fi
