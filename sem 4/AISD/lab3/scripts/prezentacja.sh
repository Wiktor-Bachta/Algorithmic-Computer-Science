# !/bin/bash

N=(8 32)
programs=(insertion_sort quick_sort hybrid_sort dp_quick_sort)

for program in ${programs[@]}; do
    for n in ${N[@]}; do
        echo $program, ciąg losowy, n=$n
        echo "$(../bin/generator $n | ../bin/$program)"
        echo
        echo $program, ciąg rosnący, n=$n
        echo "$(../bin/generator -i $n | ../bin/$program)"
        echo
        echo $program, ciąg malejący, n=$n
        echo "$(../bin/generator -d $n | ../bin/$program)"
        echo
    done
done