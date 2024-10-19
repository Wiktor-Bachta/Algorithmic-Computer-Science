#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

cat $(find $1 -type f)| tr -s " \n" | tr " " "\n" | sort | uniq -c
