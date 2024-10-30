# Wiktor Bachta

for (start_interval::Float64, end_interval::Float64) in [(1 / 2, 1), (1, 2), (2, 4)]

	step::Float64 = nextfloat(start_interval) - start_interval

	println("Przedział [$start_interval, $end_interval]:")

	steps = 10
	current_float::Float64 = start_interval
	for _ in 1:steps
		println(bitstring(current_float))
		current_float = nextfloat(current_float)
	end

	println("Krok obliczony: $step\n")

end
