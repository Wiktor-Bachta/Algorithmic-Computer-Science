#Wiktor Bachta

#funkcja, której pochodną liczymy
function f(x::Float64)
	return sin(x) + cos(3 * x)
end

#prawdziwa pochodna funkcji
function real_derivative_f(x::Float64)
    return cos(x) - 3 * sin(3 * x)
end

#przybliżona pochodna funkcji, dla danego h
function approximate_derivative_f(x::Float64, h::Float64)
    return (f(x + h) - f(x)) / h
end

for n in 0:54
    x::Float64 = Float64(1)
    h::Float64 = Float64(2)^(-n)

    real_der = real_derivative_f(x)
    approx_der = approximate_derivative_f(x, h)

    println("h = 2^-$n")
    println("h + 1 = $(h + 1)")
    println("prawdziwa pochodna = $real_der")
    println("przybliżona pochodna = $approx_der")
    println("błąd bezwzględny = $(abs(approx_der - real_der))")

end
