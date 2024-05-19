% PARSER

% Program jest listą instrukcji.
program([]) --> [].
program([Instrukcja | Program]) -->
    instrukcja(Instrukcja), [sep(;)], program(Program).

% Definicje instrukcji.
instrukcja(assign(ID, Wyrazenie)) -->
    [id(ID)], [sep(:=)], wyrazenie(Wyrazenie).
instrukcja(read(ID)) -->
    [key(read)], [id(ID)].
instrukcja(write(Wyrazenie)) -->
    [key(write)], wyrazenie(Wyrazenie).
instrukcja(if(Warunek, Program)) -->
    [key(if)], warunek(Warunek), [key(then)], program(Program), [key(fi)].
instrukcja(if(Warunek, Program1, Program2)) -->
    [key(if)], warunek(Warunek), [key(then)], program(Program1), [key(else)], program(Program2), [key(fi)].
instrukcja(while(Warunek, Program)) -->
    [key(while)], warunek(Warunek), [key(do)], program(Program), [key(od)].

% Definicje wyrażeń.
wyrazenie(W) --> skladnik(S), wyrazenie_tail(S, W).

wyrazenie_tail(W1, W) -->
    [sep(+)], !, skladnik(S2), wyrazenie_tail(W1 + S2, W).
wyrazenie_tail(W1, W) -->
    [sep(-)], !, skladnik(S2), wyrazenie_tail(W1 - S2, W).
wyrazenie_tail(W, W) --> [].

% Definicje składników.
skladnik(S) --> czynnik(C), skladnik_tail(C, S).

skladnik_tail(S1, S) -->
    [sep(*)], !, czynnik(C2), skladnik_tail(S1 * C2, S).
skladnik_tail(S1, S) -->
    [sep(/)], !, czynnik(C2), skladnik_tail(S1 / C2, S).
skladnik_tail(S1, S) -->
    [sep(mod)], !, czynnik(C2), skladnik_tail(S1 mod C2, S).
skladnik_tail(S, S) --> [].

% Definicje czynników.
czynnik(id(ID)) --> [id(ID)].
czynnik(int(NUM)) --> [int(NUM)].
czynnik(W) --> [sep('(')], wyrazenie(W), [sep(')')].

% Definicje warunków.
warunek(W) --> koniunkcja(K), warunek_tail(K, W).

warunek_tail(W1, W) -->
    [key(or)], !, koniunkcja(K2), warunek_tail(W1 ; K2, W).
warunek_tail(W, W) --> [].

% Definicje koniunkcji.
koniunkcja(K) --> prosty(P), koniunkcja_tail(P, K).

koniunkcja_tail(K1, K) -->
    [key(and)], !, prosty(P2), koniunkcja_tail(K1 , P2, K).
koniunkcja_tail(K, K) --> [].

% Definicje prostych warunków.
prosty(W1 =:= W2) --> wyrazenie(W1), [sep(=)], wyrazenie(W2).
prosty(W1 =\= W2) --> wyrazenie(W1), [sep(/=)], wyrazenie(W2).
prosty(W1 < W2) --> wyrazenie(W1), [sep(<)], wyrazenie(W2).
prosty(W1 > W2) --> wyrazenie(W1), [sep(>)], wyrazenie(W2).
prosty(W1 =< W2) --> wyrazenie(W1), [sep(=<)], wyrazenie(W2).
prosty(W1 >= W2) --> wyrazenie(W1), [sep(>=)], wyrazenie(W2).
prosty(W) --> [sep('(')], warunek(W), [sep(')')].

%SCANNER

% Predykaty rozpoznające słowa kluczowe
is_keyword(Token) :-
    member(Token, [read, write, if, then, else, fi, while, do, od, and, or, mod]).

% Predykaty rozpoznające separatory
is_separator(Token) :-
    member(Token, [';', '+', '-', '*', '/', '(', ')', '<', '>', '=<', '>=', ':=', '=', '/='])
.
% Predykat rozpoznający identyfikatory
is_identifier(Token) :-
    atom_chars(Token, Chars),
    maplist(char_type_upper, Chars).

% Predykat sprawdzający, czy dany znak jest dużą literą
char_type_upper(Char) :-
    char_type(Char, upper).

% Predykat rozpoznający liczby naturalne
is_natural_number(Number) :-
    integer(Number), 
    Number >= 0.

% Predykat zamieniający strumień na listę tokenów
scanner(Stream, Tokens) :-
    read_line_to_string(Stream, Line),
    (Line \= end_of_file ->
        tokenize_line(Line, TokensLine),
        append(TokensLine, RestTokens, Tokens),
        scanner(Stream, RestTokens)
    ;   Tokens = []).

% Predykat rozpoznający tokeny w linii
tokenize_line(Line, Tokens) :-
    split_string(Line, ' ', ' ', SplitLine),
    last(SplitLine, L),
    % Sprawdzam średniki
    (sub_atom(L, _, 1, 0, ;) -> 
        split_string(L, ';', ';', [L1]),
        append(N, [_], SplitLine),
        append(N, [L1, ";"], SplitLineFinal) 
    ;   SplitLineFinal = SplitLine),
    maplist(process_token, SplitLineFinal, Tokens).

% Predykat przetwarzający pojedynczy token
process_token(Token, key(T)) :-
    atom_string(T, Token),
    is_keyword(T).

process_token(Token, int(T)) :-
    atom_number(Token, T),
    is_natural_number(T).

process_token(Token, id(T)) :-
    atom_string(T, Token),
    is_identifier(T).

process_token(Token, sep(T)) :-
    atom_string(T, Token),
    is_separator(T).


