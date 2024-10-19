#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

files=$(find $1 -type f)
unique_words_in_file=""

for file in ${files[@]}; do
    unique_words_in_file=$(echo $unique_words_in_file $(cat $file | tr -s " \n" | tr " " "\n" | sort -u))
done

echo $unique_words_in_file | tr " " "\n" | sort | uniq -c