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

if [ -z "$1" ]; then
  buildAndMake
elif [ "$1" == "run" ]; then
  bin/game/Deadstorm
elif [ "$1" == "clean" ]; then
  remove
elif [ "$1" == "rebuild" ]; then
  remove
  buildAndMake
fi
