# Wiktor Bachta

function f(x::Float64)
	return sqrt(x^2 + Float64(1)) - Float64(1)
end

function g(x::Float64)
	return x^2 / (sqrt(x^2 + Float64(1)) + Float64(1))
end

power = -1
x::Float64 = Float64(8)^power
fx::Float64 = f(x)
gx::Float64 = g(x)

while !((fx == Float64(0)) && (gx == Float64(0)))

    global power
    global x
    global fx
    global gx

	println("x = 8^$power")
	println("f(x) = $fx")
	println("g(x) = $gx")
    println("x^2/2 = $(x^2 / 2)")

    power -= 1
    x /= Float64(8)
	fx = f(x)
	gx = g(x)

end
