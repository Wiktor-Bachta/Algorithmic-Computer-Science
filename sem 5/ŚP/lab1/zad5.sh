#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

files=$(find $1 -type f)

for file in ${files[@]}; do
    sed -i -e "s/a/A/g" $file
done
