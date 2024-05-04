#!/bin/bash

average() {
    local data=("$@")
    local sum=0
    for i in ${data[@]}; do
        sum=$(($sum + $i))
    done
    echo "scale=2; $sum / ${#data[@]}" | bc
}

programs=(quick_sort hybrid_sort dp_quick_sort merge_sort power_sort my_sort)
k=100
N=()

rm -rf ../data/high/*

for ((i=1; i<51; i++)); do
    N+=( $((1000*$i)) )
done

for program in ${programs[@]}; do
    echo n,c,s,c/n,s/n >> "../data/high/$program.csv"
    for n in ${N[@]}; do
        comparisons=()
        swaps=()
        for ((i=0; i<k; i++)); do
            data=( $(../bin/generator $1 $n | ../bin/$program) )
            data_len=${#data[@]}
            comparisons+=(${data[$(($data_len - 4))]}) 
            swaps+=(${data[$(($data_len - 1))]})
        done

        avg_comparisons=$(average ${comparisons[@]})
        avg_swaps=$(average ${swaps[@]})

        echo $n,$avg_comparisons,$avg_swaps,$(echo "scale=2; $avg_comparisons / $n" | bc),$(echo "scale=2; $avg_swaps / $n" | bc) >> "../data/high/$program.csv"
    done
done 


