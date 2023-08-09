#!/bin/sh

project="timer"

if [ "$1" = "build" ] || [ "$1" = "make" ]; then
  cmake -B build/cmake/ -S .
  make -C build/cmake/
elif [ "$1" = "rebuild" ]; then
  rm -rf build/bin/* build/cmake/*
  cmake -B build/cmake/ -S .
  make -C build/cmake/
elif [ "$1" = "clean" ]; then
  rm -rf build/
elif [ "$1" = "help" ]; then
  echo -e "Build project:\t ./run build"
  echo -e "Rebuild project: ./run rebuild"
  echo -e "Clean project:\t ./run clean"
  echo -e "Run project:\t ./run"
else
  if [ -e build/bin/$project ]; then
    exec build/bin/$project "$@"
  else
    echo "No binary executable named \"$project\" found in the directory \"build/bin/\"."
    echo "Building..."

    cmake -B build/cmake/ -S .
    make -C build/cmake/
    if [ -e build/bin/$project ]; then
      exec build/bin/$project "$@"
    else
      echo "Project built, but no binary executable found. Verify your project names match between the shell script and CMakeLists.txt"
    fi
  fi
fi
