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
is_natural_number(Token) :-
    atom_number(Token, Number), 
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
    atom_string(T, Token),
    is_natural_number(T).

process_token(Token, id(T)) :-
    atom_string(T, Token),
    is_identifier(T).

process_token(Token, sep(T)) :-
    atom_string(T, Token),
    is_separator(T).


