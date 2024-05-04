# !/bin/bash

for ((i=1; i<21; i++)); do
    sum_comparisons=0
    sum_swaps=0
    for ((j=0; j<100; j++)); do
        data=( $(../bin/generator 10000 | ../bin/hybrid_sort $i) )
        data_len=${#data[@]}
        sum_comparisons=$(($sum_comparisons + ${data[$(($data_len - 4))]}))
        sum_swaps=$(($sum_swaps + ${data[$(($data_len - 1))]}))
    done
    echo rozmiar tablicy: 10000, przełączanie: $i, średnie porównania: $(($sum_comparisons/100)), średnie zamiany: $(($sum_swaps/100))
done