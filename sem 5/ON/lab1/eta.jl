# Wiktor Bachta

function calculate_eta(T::Type)
    eta::T = T(1)
    while eta / T(2) > T(0)
        eta /= T(2)
    end
    return eta  
end

float_types = [Float16, Float32, Float64]

for T in float_types
    iterative_eta::T = calculate_eta(T)
    builtin_eta = nextfloat(T(0))
    
    println("Typ: $T")
    println("Iteracyjnie obliczona eta: $iterative_eta")
    println("Wartość zwrócona przez nextfloat($T): $builtin_eta")
end

