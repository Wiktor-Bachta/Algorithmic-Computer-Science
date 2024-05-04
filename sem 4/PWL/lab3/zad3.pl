even_permutation(L, P) :-
    permutation(L, P),
    num_inversions(L, A),
    num_inversions(P, N),
    0 is (N - A) mod 2.

odd_permutation(L, P) :-
    permutation(L, P),
    num_inversions(L, A),
    num_inversions(P, N),
    1 is (N - A) mod 2.

num_smaller_elements(_, [], N) :-
    N is 0.

num_smaller_elements(E, [X | L], N) :-
    num_smaller_elements(E, L, N1),
    ((X < E) -> N is N1 + 1; N is N1).

num_inversions([], N) :-
    N is 0.

num_inversions([X | L], N) :-
    num_inversions(L, N1),
    num_smaller_elements(X, L, S),
    N is N1 + S.