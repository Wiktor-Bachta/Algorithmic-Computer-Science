# Wiktor Bachta

function calculate_machine_epsilon(T::Type)
    epsilon::T = T(1)
    while T(1) + epsilon / T(2) > T(1)
        epsilon /= T(2)
    end
    return epsilon 
end 

float_types = [Float16, Float32, Float64]

for T in float_types
    iterative_eps::T = calculate_machine_epsilon(T)
    builtin_eps = eps(T)
    
    println("Typ: $T")
    println("Iteracyjnie obliczony epsilon maszynowy: $iterative_eps")
    println("Wartość zwrócona przez eps($T): $builtin_eps")
end

