:- use_module(library(clpfd)).


kolorowanie(X):-
    X = [X1, X2, X3, X4, X5, X6, X7, X8, X9],
    X ins 1..3,
    X1 #\= X6,
    X1 #\= X5,
    X1 #\= X4,
    X1 #\= X2,
    X2 #\= X4,
    X2 #\= X3,
    X2 #\= X9,
    X3 #\= X4,
    X3 #\= X5,
    X3 #\= X9,
    X4 #\= X5,
    X5 #\= X6,
    X5 #\= X7,
    X5 #\= X9,
    X6 #\= X7,
    X6 #\= X8,
    X7 #\= X8,
    X7 #\= X9,
    X9 #\= X8.