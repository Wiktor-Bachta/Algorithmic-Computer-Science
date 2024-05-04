% X występuje dokładnie jeden raz na liście L:
% jednokrotnie(X, L)

jednokrotnie(X, L) :-
    select(X, L, B),        % B to L bez X
    \+ member(X, B).

dwukrotnie(X, L) :-
    append(P, [X | R], L),
    \+ member(X, R),
    jednokrotnie(X, P).
