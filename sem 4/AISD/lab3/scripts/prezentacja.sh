# !/bin/bash

N=(8 32)
programs=(select randomized_select)

for program in ${programs[@]}; do
    for n in ${N[@]}; do
        echo $program, pierwszy element, n=$n
        echo "$(../bin/generator select one $n | ../bin/$program)"
        echo
        echo $program, środkowy element, n=$n
        echo "$(../bin/generator select half $n | ../bin/$program)"
        echo
        echo $program, losowy element, n=$n
        echo "$(../bin/generator select random $n | ../bin/$program)"
        echo
    done
done

for n in ${N[@]}; do
    echo binary_search, pierwszy element, n=$n
    echo "$(../bin/generator binary start $n | ../bin/binary_search)"
    echo
    echo binary_search, środkowy element, n=$n
    echo "$(../bin/generator binary middle $n | ../bin/binary_search)"
    echo
    echo binary_search, nieistniejący element, n=$n
    echo "$(../bin/generator binary out $n | ../bin/binary_search)"
    echo
    echo binary_search, losowy element, n=$n
    echo "$(../bin/generator binary random $n | ../bin/binary_search)"
    echo
done

programs=(quicksort dp_quicksort quicksort_select dp_quicksort_select)

for program in ${programs[@]}; do
    for n in ${N[@]}; do
        echo $program, ciąg losowy, n=$n
        echo "$(../bin/generator -n $n | ../bin/$program)"
        echo
        echo $program, ciąg rosnący, n=$n
        echo "$(../bin/generator -i $n | ../bin/$program)"
        echo
        echo $program, ciąg malejący, n=$n
        echo "$(../bin/generator -d $n | ../bin/$program)"
        echo
    done
done