merge(A, B, C) :-                     
    freeze(A,                           
    (   A = [HA | TA]                   
    ->  freeze(B,                       
        (   B  = [HB | TB]              
        ->  (  HA =< HB                 
            ->  C = [HA | TC],          
                merge(TA, B, TC)      
            ;   C = [HB | TC],          
                merge(A, TB, TC)
            )
        ;   C = A                       
        ))
    ; C = B                            
    )).
    
