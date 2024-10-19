:- use_module(library(clpfd)).

odcinek(X):-
    length(X,16),
    length(X1,8),
    X ins 0..1,
    sum(X, #=, 8),
    append(X1,X2,X),
    chain(X1, #=<),
    chain(X2, #>=).