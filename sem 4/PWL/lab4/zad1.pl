wyrażenie([Wartość], Wartość, Wartość).

wyrażenie(Lista, Wartość, Wyrażenie) :-
    append(Początek, Koniec, Lista),
    Początek \= [], Koniec \= [],
    wyrażenie(Początek, Wynik1, Wyrażenie1),
    wyrażenie(Koniec, Wynik2, Wyrażenie2),
    operator(Operator),
    wyrażenie(Operator, Wynik1, Wynik2, Wartość),
    format(atom(Wyrażenie), '(~w~w~w)', [Wyrażenie1, Operator, Wyrażenie2]).

operator(+).
operator(-).
operator(*).
operator(/).

wyrażenie(+, X, Y, Z) :- Z is X + Y.
wyrażenie(-, X, Y, Z) :- Z is X - Y.
wyrażenie(*, X, Y, Z) :- Z is X * Y.
wyrażenie(/, X, Y, Z) :- Y =\= 0, Z is X / Y.

