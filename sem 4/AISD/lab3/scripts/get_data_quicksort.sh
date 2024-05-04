#!/bin/bash

average() {
    local data=("$@")
    local sum=0
    for i in ${data[@]}; do
        sum=$(($sum + $i))
    done
    echo "scale=2; $sum / ${#data[@]}" | bc
}

programs=(quicksort dp_quicksort quicksort_select dp_quicksort_select)
modes=(-i -d -n)
k=100
N=()

rm -rf ../data/quicksort/*

for ((i=1; i<101; i++)); do
    N+=( $((100*$i)) )
done

for program in ${programs[@]}; do
    for mode in ${modes[@]}; do
        echo "n,c,s,c/(n*ln(n)),s/(n*ln(n)),c/(n*n),s/(n*n)" >> "../data/quicksort/$program$mode.csv"
        for n in ${N[@]}; do
            comparisons=()
            swaps=()
            for ((i=0; i<k; i++)); do
                data=( $(../bin/generator $mode $n | ../bin/$program) )
                data_len=${#data[@]}
                comparisons+=(${data[$(($data_len - 4))]}) 
                swaps+=(${data[$(($data_len - 1))]})
            done

            avg_comparisons=$(average ${comparisons[@]})
            avg_swaps=$(average ${swaps[@]})

            echo $n,$avg_comparisons,$avg_swaps,$(echo "scale=2; $avg_comparisons / ($n * l($n))" | bc -l),$(echo "scale=2; $avg_swaps / ($n * l($n))" | bc -l),$(echo "scale=2; $avg_comparisons / ($n * $n)" | bc),$(echo "scale=2; $avg_swaps / ($n * $n)" | bc) >> "../data/quicksort/$program$mode.csv"
        done
    done
done 


