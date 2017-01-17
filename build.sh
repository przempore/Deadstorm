#!/bin/bash

BASEDIR=$(pwd)

function buildAndMake {
  mkdir -p bin/
  cd bin
  cmake ..
  cd game
  make
  cd "$BASEDIR"
}

function buildTest {
    mkdir -p bin/test
    cd bin/test
    cmake ../../test/
    make
    cd -
}

function buildTest {
    mkdir -p bin/test
    cd bin/test
    cmake ../../test/
    make
    cd -
}

function remove {
  rm -rf bin/
}

function run {
  if [ -e bin/game/Deadstorm ]; then
    cd bin/game/
    ./Deadstorm
    cd "$BASEDIR"
  else
    echo "Can't run without build before."
  fi
}

if [ "$1" == "-b" ]; then
  buildAndMake
elif [ "$1" == "-r" ]; then
  run
elif [ "$1" == "-d" ]; then
  remove
elif [ "$1" == "-rb" ]; then
  remove
  buildAndMake
elif [ "$1" == "-bar" ]; then
  buildAndMake
  run
elif [ "$1" == "-bt" ]; then
 buildTest
elif [ "$1" == "-t" ]; then
  buildAndMake
  cd bin/test
  make
  ./runUnitTests
  cd "$BASEDIR"
else
  echo "  -b build
  -r run
  -d remove
  -rb rebuild
  -t test"
fi
