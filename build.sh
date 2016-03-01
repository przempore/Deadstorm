#!/bin/bash

if [ -z "$1" ]; then
  mkdir -p bin/
  cd bin
  cmake ..
  make
elif [ "$1" == "run" ]; then
  bin/game/Deadstorm
elif [ "$1" == "clean" ]; then
  rm -rf bin/
fi
