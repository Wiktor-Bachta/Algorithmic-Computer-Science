średnia(L, S) :-
    length(L, N),
    sumlist(L, A),
    S is A / N.

suma_kwadratów([], S) :-
    S is 0.

suma_kwadratów([X | L], S) :-
    suma_kwadratów(L, S1),
    S is (X * X) + S1.

wariancja(L, X) :-
    suma_kwadratów(L, S),
    length(L, N),
    średnia(L, A),
    X is S / N - A * A.