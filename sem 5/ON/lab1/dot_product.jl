# Wiktor Bachta

#funkcja obliczająca iloczyn skalarny dwóch wektorów
function calculate_dot_product(T::Type, length::Int, vector1::AbstractVector, vector2::AbstractVector)
	dot_product::T = T(0)

	for i in 1:length
		dot_product += vector1[i] * vector2[i]
	end

	return dot_product
end

# funkcja obliczająca iloczyn skalarny metodą od największego iloczynu
function calculate_dot_product_biggest_to_smallest(T::Type, length::Int, vector1::AbstractVector, vector2::AbstractVector)
	dot_product::T = T(0)
	positive_products::Vector{T} = []
	negative_products::Vector{T} = []

	for i in 1:length
		if vector1[i] * vector2[i] >= 0
			push!(positive_products, vector1[i] * vector2[i])
		else
			push!(negative_products, vector1[i] * vector2[i])
		end
	end

	sort!(positive_products, rev = true)
	sort!(negative_products)

	partial_positive::T = T(0)
	for product in positive_products
		partial_positive += product
	end

	partial_negative::T = T(0)
	for product in negative_products
		partial_negative += product
	end

	return partial_positive + partial_negative
end

# funkcja obliczająca iloczyn skalarny metodą od najmniejszego iloczynu
function calculate_dot_product_smallest_to_biggest(T::Type, length::Int, vector1::AbstractVector, vector2::AbstractVector)
	dot_product::T = T(0)
	positive_products::Vector{T} = []
	negative_products::Vector{T} = []

	for i in 1:length
		if vector1[i] * vector2[i] >= 0
			push!(positive_products, vector1[i] * vector2[i])
		else
			push!(negative_products, vector1[i] * vector2[i])
		end
	end

	sort!(positive_products)
	sort!(negative_products, rev = true)

	partial_positive::T = T(0)
	for product in positive_products
		partial_positive += product
	end

	partial_negative::T = T(0)
	for product in negative_products
		partial_negative += product
	end

	return partial_positive + partial_negative
end

float_types = [Float32, Float64]

for T in float_types

	x::Vector{T} = [2.718281828, -3.141592654, 1.414213562, 0.5772156649, 0.3010299957]
	y::Vector{T} = [1486.2497, 878366.9879, -22.37492, 4773714.647, 0.000185049]

	dot_product::T = calculate_dot_product(T, 5, x, y)
	dot_product_reverse::T = calculate_dot_product(T, 5, reverse(x), reverse(y))
	dot_product_biggest_to_smallest = calculate_dot_product_biggest_to_smallest(T, 5, x, y)
	dot_product_smallest_to_biggest = calculate_dot_product_smallest_to_biggest(T, 5, x, y)

	println("Typ: $T")
	println("Iloczyn skalarny liczony w przód: $dot_product")
	println("Iloczyn skalarny liczony w tył: $dot_product_reverse")
	println("Iloczyn skalarny liczony w od największego iloczynu: $dot_product_biggest_to_smallest")
	println("Iloczyn skalarny liczony w od największego iloczynu: $dot_product_smallest_to_biggest")

end
