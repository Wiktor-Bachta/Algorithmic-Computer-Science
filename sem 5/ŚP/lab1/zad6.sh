#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

declare -A word_map
files=$(find $1 -type f)

for file in ${files[@]}; do
    line_number=1
    while IFS="" read -r line; do
        for word in ${line[@]}; do
            word_map[$word]=$(echo "${word_map[$word]}$file:$line_number:$line\n")
        done
        line_number=$((line_number + 1))
    done < $file
done

for word in ${!word_map[@]}; do
    if (( $(echo -n -e ${word_map[$word]} | uniq -d | wc -l) == 0 )); then
        continue
    fi
        echo "$word:"
        echo -n -e ${word_map[$word]} | uniq -d
done
