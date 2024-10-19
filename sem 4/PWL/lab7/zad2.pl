:- [zad1].

split(A, B, C) :-                       
    freeze(A,                           
    (   A = [HA | TA]                   
    ->  B = [HA | TB],                  
        split(TA, C, TB)                
    ;   B = [],                         
        C = []                          
    )).

merge_sort(A, B) :-                     
    freeze(A,                           
    (   A = [_ | TA]                    
    ->  freeze(TA,                     
        (   TA = [_ | _]                
        ->  split(A, A1, A2),           
            merge_sort(A1, B1),        
            merge_sort(A2, B2),       
            merge(B1, B2, B)    
        ; B = A                         
        ))
    ;   B = A                         
    )).
