:- use_module(library(clpfd)).

resources(5, 5).

tasks([

    [2, 1, 3],
    [3, 2, 1],
    [4, 2, 2],
    [3, 3, 2],
    [3, 1, 1],
    [3, 4, 2],
    [5, 2, 1]
]).

schedule(H, S, MS):-
    tasks(Tasks),
    create_tasks(Tasks,TX,TY,S,MS),
    S ins 0..H,
    resources(Limit1,Limit2),
    cumulative(TX, [limit(Limit1)]),
    cumulative(TY, [limit(Limit2)]),
    MS #=< H,
    once(labeling([min(MS)],S)).

create_tasks([],[],[],[],0).
create_tasks([[D,X,Y]|Rest],[task(S,D,E,X,_)|X1],[task(S,D,E,Y,_)|Y1],[S|S1],MS):-
    create_tasks(Rest,X1,Y1,S1,E2),
    MS #= max(E,E2).
   
