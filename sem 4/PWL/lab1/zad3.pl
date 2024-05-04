composite(N) :-
    M is floor(sqrt(N)),
    between(2, M, X),
    (N mod X) =:= 0, !.

prime(LO, HI, N) :-
    between(LO, HI, N),
    N > 1,
    \+ composite(N).

