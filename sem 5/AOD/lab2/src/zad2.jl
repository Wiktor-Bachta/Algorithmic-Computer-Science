# Wiktor Bachta

using JuMP
using GLPK

function solve(machine_time_matrix::Matrix, availibility::Vector, machine_costs::Vector, material_costs::Vector, max_demand::Vector, sell_prices::Vector)
	m, n = size(machine_time_matrix)
	model = Model(GLPK.Optimizer)
	set_silent(model)

	# Ile kg produkuje każda maszyna
	@variable(model, kg_produced[1:m] >= 0, Int)

	# Maszyny nie przekraczają dostępności
	@constraint(model, sum(repeat(kg_produced, 1, n) .* machine_time_matrix, dims = 1) .<= availibility)

	# Nie produkujemy więcej produktu niż można sprzedać
	@constraint(model, kg_produced .<= max_demand)

	# Maks profit = zysk - materiały - maszyny
	@objective(model, Max, sum((sell_prices .- material_costs) .* kg_produced) - sum(machine_costs .* vec(sum(repeat(kg_produced, 1, n) .* machine_time_matrix, dims = 1))))

	optimize!(model)

	if termination_status(model) == MOI.OPTIMAL
		println("Kg na produkt na maszynę")
		display(value.(kg_produced))
		println("Minuty na produkt na maszynę")
		display(value.(kg_produced) .* machine_time_matrix)
		println("Profit")
		println(objective_value(model))
	elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end
end

machine_time_matrix = [5 10 6; 3 6 4; 4 5 3; 4 2 1]
availibility = [3600, 3600, 3600]
machine_costs = [2 / 60, 2 / 60, 3 / 60]
material_costs = [4, 1, 1, 1]
max_demand = [400, 100, 150, 500]
sell_prices = [9, 7, 6, 5]

solve(machine_time_matrix, availibility, machine_costs, material_costs, max_demand, sell_prices)
