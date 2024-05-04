#!/bin/bash

average() {
    local data=("$@")
    local sum=0
    for i in ${data[@]}; do
        sum=$(($sum + $i))
    done
    echo "scale=2; $sum / ${#data[@]}" | bc
}

programs=(select randomized_select)
modes=(random one half)
k=100
N=()

rm -rf ../data/algorithms/*

for ((i=1; i<51; i++)); do
    N+=( $((1000*$i)) )
done

for program in ${programs[@]}; do
    for mode in ${modes[@]}; do
        echo n,c,s,c/n,s/n >> "../data/algorithms/$program-$mode.csv"
        for n in ${N[@]}; do
            comparisons=()
            swaps=()
            for ((i=0; i<k; i++)); do
                data=( $(../bin/generator select $mode $n | ../bin/$program) )
                data_len=${#data[@]}
                comparisons+=(${data[$(($data_len - 4))]}) 
                swaps+=(${data[$(($data_len - 1))]})
            done

            avg_comparisons=$(average ${comparisons[@]})
            avg_swaps=$(average ${swaps[@]})

            echo $n,$avg_comparisons,$avg_swaps,$(echo "scale=2; $avg_comparisons / $n" | bc),$(echo "scale=2; $avg_swaps / $n" | bc) >> "../data/algorithms/$program-$mode.csv"
        done
    done
done 


