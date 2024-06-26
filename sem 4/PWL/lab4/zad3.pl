duże(L, W) :-
    (L = [1,1,1,1,_,_,1,_,_,_,1,_,_,1,_,_,_,1,_,_,1,1,1,1] -> Y1 is 1; Y1 is 0),
    W =:= Y1.

średnie(L, W) :-
    (L = [1,1,_,1,_,1,_,_,_,_,1,_,1,_,1,1,_,_,_,_,_,_,_,_] -> Y1 is 1; Y1 is 0),
	(L = [_,_,_,_,_,_,_,1,1,_,1,_,1,_,_,_,_,1,_,1,_,1,1,_] -> Y2 is Y1+1; Y2 is Y1),
	(L = [_,1,1,_,1,_,1,_,_,_,_,1,_,1,_,1,1,_,_,_,_,_,_,_] -> Y3 is Y2+1; Y3 is Y2),
	(L = [_,_,_,_,_,_,_,_,1,1,_,1,_,1,_,_,_,_,1,_,1,_,1,1] -> Y4 is Y3+1; Y4 is Y3),
	W =:= Y4.

małe(L, W) :-
    (L = [1,_,_,1,1,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_] -> Y1 is 1; Y1 is 0),
	(L = [_,1,_,_,1,1,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_] -> Y2 is Y1+1; Y2 is Y1),
	(L = [_,_,1,_,_,1,1,_,_,1,_,_,_,_,_,_,_,_,_,_,_,_,_,_] -> Y3 is Y2+1; Y3 is Y2),
	(L = [_,_,_,_,_,_,_,1,_,_,1,1,_,_,1,_,_,_,_,_,_,_,_,_] -> Y4 is Y3+1; Y4 is Y3),
	(L = [_,_,_,_,_,_,_,_,1,_,_,1,1,_,_,1,_,_,_,_,_,_,_,_] -> Y5 is Y4+1; Y5 is Y4),
	(L = [_,_,_,_,_,_,_,_,_,1,_,_,1,1,_,_,1,_,_,_,_,_,_,_] -> Y6 is Y5+1; Y6 is Y5),
	(L = [_,_,_,_,_,_,_,_,_,_,_,_,_,_,1,_,_,1,1,_,_,1,_,_] -> Y7 is Y6+1; Y7 is Y6),
	(L = [_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,1,_,_,1,1,_,_,1,_] -> Y8 is Y7+1; Y8 is Y7),
	(L = [_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,1,_,_,1,1,_,_,1] -> Y9 is Y8+1; Y9 is Y8),
	W =:= Y9.

zabierz(0, L, W, _) :-
    W = L.

zabierz(K, L, W, S) :-
    K =\= 0,
    append(Left, [1 | Right], L),
    append(Left, [0 | Right], L2),
    length(Left, S2),
    S2 >= S,
    K2 is K - 1,
    zabierz(K2, L2, W, S2).

zapałki(K, D, S, M) :-
    L = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
    between(1, 24, K),
    zabierz(K, L, W, 0),
    duże(W, D),
    średnie(W, S),
    małe(W, M),
    rysuj(1, W),
    nl.

rysuj(25, _).

rysuj(N,[H| L]) :-
    (
    mod(N,7) =:= 1;
    mod(N,7) =:= 2;
    mod(N,7) =:= 3
    ),
    write('+'),
    (H =:= 1 -> write('---'); write('   ')),
    (mod(N,7) =:= 3 -> (write('+'),nl); true),
    N2 is N + 1,
    rysuj(N2, L).
    
rysuj(N,[H| L]) :-
    (
    mod(N,7) =:= 4;
    mod(N,7) =:= 5;
    mod(N,7) =:= 6;
    mod(N,7) =:= 0
    ),
    (H =:= 1 -> write('|'); write(' ')),
    (mod(N,7) =:= 0 -> nl; write('   ')),
    N2 is N+1,
    rysuj(N2, L).
