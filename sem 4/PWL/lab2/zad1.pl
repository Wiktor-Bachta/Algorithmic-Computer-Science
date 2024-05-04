% X jest środkowym elementem listy L:
% środkowy(L, X) 

środkowy([X], X).
środkowy([_ | L], X) :-
    append(M, [_], L),      % M to lista bez pierwszego i ostatniego elementu
    środkowy(M, X).