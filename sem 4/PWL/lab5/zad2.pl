board(L) :-
    length(L, N),
    numlist(1, N, A),
    permutation(L, A),
    Color is (N - 1) mod 2,
    draw_row(L, N, N, 1, Color, 1).


draw_row(_, N, _, R, _, Level) :-
    R is N + 1,
    Level is 2, !.

draw_row(L, N, To_draw, R, Color, Level) :-
    (To_draw =:= 0 -> 
        (Level =:= 1 ->
            write('+'),
            nl,
            draw_row(L, N, N, R, Color, 2)
        ;
            write('|'),
            nl,
            (Level =:= 2 ->
                Color1 is (N - R) mod 2,
                draw_row(L, N, N, R, Color1, 3)
            ;
                Color1 is (N - R + 1) mod 2,
                R1 is R + 1,
                draw_row(L, N, N, R1, Color1, 1)
            )
        )
    ;
        (Level =:= 1 ->
            write('+-----'),
            To_draw1 is To_draw - 1,
            draw_row(L, N, To_draw1, R, Color, Level)
        ;
            Row is N - R,
            Column is N + 1 - To_draw,
            (nth0(Row, L, Column) ->
                (Color =:= 0 ->
                    write('|:###:'),
                    To_draw1 is To_draw - 1,
                    Color1 is (Color + 1) mod 2,
                    draw_row(L, N, To_draw1, R, Color1, Level)
                ;
                    write('| ### '),
                    To_draw1 is To_draw - 1,
                    Color1 is (Color + 1) mod 2,
                    draw_row(L, N, To_draw1, R, Color1, Level)
                )
            ;
                (Color =:= 0 ->
                    write('|:::::'),
                    To_draw1 is To_draw - 1,
                    Color1 is (Color + 1) mod 2,
                    draw_row(L, N, To_draw1, R, Color1, Level)
                ;
                    write('|     '),
                    To_draw1 is To_draw - 1,
                    Color1 is (Color + 1) mod 2,
                    draw_row(L, N, To_draw1, R, Color1, Level)
                )
            )
        )
    ).
