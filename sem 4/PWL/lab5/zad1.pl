

scanner(S, [H | L]) :-
    helper(S, [H | L], 4).

helper(S, [H | L], N) :-
    N >= 0,
    get_char(S, H),
    N1 is N - 1,
    helper(S, L, N1).