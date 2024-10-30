# Wiktor Bachta

x::Float64 = nextfloat(Float64(1))

while x * (Float64(1) / x) == Float64(1)
	global x
	x = nextfloat(x)
end

wrong_unit::Float64 = x * (Float64(1) / x)

println("Znaleziona liczba: $x")
println("x(1/x) = $wrong_unit")