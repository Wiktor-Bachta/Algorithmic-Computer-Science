% swipl
% ['functions.pl'].

merge([], B, B).
merge(A, [], A).
merge([HA | A], [HB | B], [HC | C]) :-                     
    (   HA =< HB 
    ->
        HC = HA,
        merge(A, [HB | B], C)
    ;
        HC = HB,
        merge([HA | A], B, C)
    ).

split(A, B, C) :-                                               
    (   A = [HA | TA]                   
    ->  
        B = [HA | TB],                  
        split(TA, C, TB)                
    ;   
        B = [],                         
        C = []                          
    ).

merge_sort(A, B) :-                                              
    (   A = [_ | TA]                    
    ->                      
        (   TA = [_ | _]                
        ->  
            split(A, A1, A2),           
            merge_sort(A1, B1),        
            merge_sort(A2, B2),       
            merge(B1, B2, B)    
        ; 
            B = A                         
        )
    ;   
        B = A                         
    ).

%-------------------------------------------------

extendedGCD(0, B, 0, 1, B).
extendedGCD(A, B, X, Y, G) :-
    dif(A, 0),
    A1 is B mod A,
    B1 is A,
    extendedGCD(A1, B1, X1, Y1, G),
    X is Y1 - (B // A) * X1,
    Y is X1.

de(A, B, X, Y, G) :-
    extendedGCD(A, B, X, Y, G).

%-------------------------------------------------

factorize(1, _, []).
factorize(N, F, [HX | X]) :-
    dif(N, 1),
    (   N mod F =:= 0 
    -> 
        N1 is N // F,
        HX = F,
        factorize(N1, F, X)
    ;
        F1 is F + 1,
        factorize(N, F1, [HX | X])
    ).

prime_factors(N, X) :-
    factorize(N, 2, X).

%-------------------------------------------------

totient_helper([], _, 0).
totient_helper([HL | L], N, T) :-
    (   gcd(HL, N) =:= 1
    ->
        T1 is T - 1,
        totient_helper(L, N, T1)
    ;
        totient_helper(L, N, T)
    ).

totient(N, T) :-
    findall(Num, between(1, N, Num), L),
    between(1, N, T),
    totient_helper(L, N, T).

%-------------------------------------------------

removeMultiples(_,[],[]).  
removeMultiples(N, [Head|Tail], Result):-  
    Head mod N =:= 0,  
    removeMultiples(N, Tail, Result).  
removeMultiples(N, [Head|Tail], [Head|Result]):-  
    Head mod N =\= 0,  
    removeMultiples(N, Tail, Result).

primes_helper([], []).
primes_helper([HL | L], [HX | X]) :-
    HL = HX,
    removeMultiples(HL, L, L1),
    primes_helper(L1, X).

primes(N, X) :-
    findall(Num, between(2, N, Num), L),
    primes_helper(L, X).