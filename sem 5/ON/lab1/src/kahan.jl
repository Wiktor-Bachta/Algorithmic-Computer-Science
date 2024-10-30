# Wiktor Bachta
function calculate_kahan_epsilon(T::Type)
    return T(3) * (T(4) / T(3) - T(1)) - T(1)  
end

float_types = [Float16, Float32, Float64]

for T in float_types
    kahan_eps::T = calculate_kahan_epsilon(T)
    builtin_eps = eps(T)
    
    println("Typ: $T")
    println("Epsilon maszynowy według Kahana: $kahan_eps")
    println("Wartość zwrócona przez eps($T): $builtin_eps")
end

