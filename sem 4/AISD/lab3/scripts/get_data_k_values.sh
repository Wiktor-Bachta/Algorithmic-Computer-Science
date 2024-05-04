#!/bin/bash

average() {
    local data=("$@")
    local sum=0
    for i in ${data[@]}; do
        sum=$(($sum + $i))
    done
    echo "scale=2; $sum / ${#data[@]}" | bc
}

modes=(random one half)
k_values=(3 5 7 9)
k=100
N=()

for ((i=1; i<51; i++)); do
    N+=( $((1000*$i)) )
done

for mode in ${modes[@]}; do
    rm -rf ../data/k_values/$mode/*
    for k_value in ${k_values[@]}; do
        echo n,c,s,c/n,s/n >> "../data/k_values/$mode/select-$k_value-$mode.csv"
        for n in ${N[@]}; do
            comparisons=()
            swaps=()
            for ((i=0; i<k; i++)); do
                data=( $(../bin/generator select $mode $n | ../bin/select $k_value) )
                data_len=${#data[@]}
                comparisons+=(${data[$(($data_len - 4))]}) 
                swaps+=(${data[$(($data_len - 1))]})
            done

            avg_comparisons=$(average ${comparisons[@]})
            avg_swaps=$(average ${swaps[@]})

            echo $n,$avg_comparisons,$avg_swaps,$(echo "scale=2; $avg_comparisons / $n" | bc),$(echo "scale=2; $avg_swaps / $n" | bc) >> "../data/k_values/$mode/select-$k_value-$mode.csv"
        done
    done
done 


