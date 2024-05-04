#!/bin/bash

average() {
    local data=("$@")
    local sum=0
    for i in ${data[@]}; do
        sum=$(($sum + $i))
    done
    echo "scale=2; $sum / ${#data[@]}" | bc
}

modes=(start middle out random)
k=100
N=()

rm -rf ../data/binary/*

for ((i=1; i<101; i++)); do
    N+=( $((1000*$i)) )
done

for mode in ${modes[@]}; do
    echo "n,c,time,c/ln(n)" >> "../data/binary/binary_search-$mode.csv"
    for n in ${N[@]}; do
        comparisons=()
        start=$(date +%s)
        for ((i=0; i<k; i++)); do
            data=( $(../bin/generator binary $mode $n | ../bin/binary_search) )
            data_len=${#data[@]}
            comparisons+=(${data[$(($data_len - 1))]})
        done
        end=$(date +%s)
        elapsed=$(($end - $start))
        avg_comparisons=$(average ${comparisons[@]})

        echo $n,$avg_comparisons,$(echo "scale=2; $elapsed / $k" | bc),$(echo "scale=2; $avg_comparisons / l($n)" | bc -l) >> "../data/binary/binary_search-$mode.csv"
    done
done

