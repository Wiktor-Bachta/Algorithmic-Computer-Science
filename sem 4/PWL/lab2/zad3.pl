arc(a, b).
arc(b, a).
arc(b, c).
arc(c, d).

% aby zapobiec nieskończonym pętlom trzeba pamiętać odwiedzone już wierzchołki

osiągalny(X,X). % osiągalny sam z siebie 
osiągalny(X,Y) :- znajdź(X, Y, [X]). % lub Y osiągalne z X gdy:

znajdź(X, Y, V) :-      			% jest łuk z X do Y i Y nie jest jeszcze odwiedzony
	arc(X, Y),         
    \+ (member(Y, V)).

znajdź(X, Y, V) :-      			% jest łuk z X do jakiegoś nieodwiedzonego wierzchołka P
	arc(X, P),          			
	\+ (member(P, V)), 				
        znajdź(P, Y, [P | V]).		% z którego osiągalny jest Y (dopisujemy P do odwiedzonych)