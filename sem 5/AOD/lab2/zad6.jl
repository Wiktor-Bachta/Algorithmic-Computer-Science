# Wiktor Bachta

using JuMP
using GLPK

function solve(containers_matrix::Matrix, camera_range::Int)

	m, n = size(containers_matrix)
	model = Model(GLPK.Optimizer)
	set_silent(model)

	# Czy kamera postawiona?
	@variable(model, 0 <= camera_placed[1:m, 1:n] <= 1, Int)

	for i in 1:m, j in 1:n
		if containers_matrix[i, j] == 1

			# Pola inne niż kontenery
			@constraint(model, camera_placed[i, j] == 0)
            
			# Dla każdedgo kontenera suma kamer w odległości patrzenia >= 1
			@constraint(model, sum(camera_placed[i, max(j - camera_range, 1):min(j + camera_range, n)]) +
							   sum(camera_placed[max(i - camera_range, 1):min(i + camera_range, m), j]) >= 1)
		end
	end

	# Minimum kamer
	@objective(model, Min, sum(camera_placed))

	optimize!(model)

	if termination_status(model) == MOI.OPTIMAL
		println("Rozmieszczenie kamer")
		display(containers_matrix -= value.(camera_placed))
		println("Liczba kamer")
		println(objective_value(model))
	elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end
end

containers_matrix = [
	0 0 1 0 0;
	1 0 0 1 0;
	0 1 0 0 0;
	0 0 0 0 0;
	0 1 1 0 1;
	1 0 1 0 0]

camera_range = 3

solve(containers_matrix, camera_range)
