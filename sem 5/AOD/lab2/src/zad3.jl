# Wiktor Bachta

using JuMP
using GLPK

function solve(max_basic_supply::Vector, basic_supply_costs::Vector, max_additional_supply::Vector,
	additional_supply_costs::Vector, demand::Vector, storage_cost::Int, starting_stored_amount::Int, max_storage::Int)

	m = length(max_basic_supply)
	model = Model(GLPK.Optimizer)
	set_silent(model)

	# Liczba podstawowych produktów
	@variable(model, basic_units_produced[1:m] >= 0, Int)

	# Liczba dodatkowych produktów
	@variable(model, additional_units_produced[1:m] >= 0, Int)

	# Stan magazynu na początku dnia
	@variable(model, units_stored[1:m+1] >= 0, Int)

	# Magazyn na początku ma ileś produktów, na końcu 0
	@constraint(model, units_stored[1] == starting_stored_amount)
	@constraint(model, units_stored[m+1] == 0)

	# Maksy
	@constraint(model, units_stored .<= max_storage)
	@constraint(model, basic_units_produced .<= max_basic_supply)
	@constraint(model, additional_units_produced .<= max_additional_supply)

	# Warunek "główny" zdadnia - magazyn jutro = magazyn dziś + produkcja - sprzedaż
	for t in 1:m
		@constraint(model, units_stored[t+1] == units_stored[t] + basic_units_produced[t] + additional_units_produced[t] - demand[t])
	end

	#nie trzeba constraint na aditional, wtedy kiey wyczerpane basic bo i tak są droższe

	# Minimalny koszt = proukcja + przechowywanie
	@objective(model, Min, sum(units_stored[2:m] .* storage_cost) + sum(basic_units_produced .* basic_supply_costs) + sum(additional_units_produced .* additional_supply_costs))

	optimize!(model)

	if termination_status(model) == MOI.OPTIMAL
		println("Produkcja podstawowa")
		println(value.(basic_units_produced))
		println("Produkcja dodatkowa")
		println(value.(additional_units_produced))
		println("Stan magazynu")
		println(value.(units_stored))
		println("Sprzedaż")
		println(demand)
		println("Koszt ")
		println(objective_value(model))
	elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end
end

max_basic_supply = [100, 100, 100, 100]
basic_supply_costs = [6000, 4000, 8000, 9000]
max_additional_supply = [60, 65, 70, 60]
additional_supply_costs = [8000, 6000, 10000, 11000]
demand = [130, 80, 125, 195]
storage_cost = 1500
starting_stored_amount = 15
max_storage = 70

solve(max_basic_supply, basic_supply_costs, max_additional_supply, additional_supply_costs, demand, storage_cost, starting_stored_amount, max_storage)
