# Wiktor Bachta

function calculate_max(T::Type)
    max::T = T(1)
    while !isinf(max) 
        max *= T(2)
    end
    while isinf(max)  
        max = prevfloat(max)  
    end
    return max  
end

float_types = [Float16, Float32, Float64]

for T in float_types
    iterative_max::T = calculate_max(T)
    builtin_max = floatmax(T)
    
    println("Typ: $T")
    println("Iteracyjnie obliczona max: $iterative_max")
    println("Wartość zwrócona przez floatmax($T): $builtin_max")
end

