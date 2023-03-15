#!/bin/sh

project="template"

if [ "$1" == "build" ] || [ "$1" == "make" ]
then
    cmake -B build/cmake/ -S .
    echo
    make -C build/cmake/
elif [ "$1" == "clean" ]
then
    rm -rf build/
    # rm -rf build/bin/* build/cmake/*
elif [ $# -eq 0 ] 
then
    if [ -e build/bin/$project ]
    then
        exec build/bin/$project
    else 
        echo "No binary executable named \"$project\" found in the directory \"build/bin/\""
    fi
else 
    echo -e "Build project:\t./run build"
    echo -e "Clean project:\t./run clean"
    echo -e "Run project:\t./run"
fi
