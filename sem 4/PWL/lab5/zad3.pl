% Predykat, który pozwala obchodzić drzewo odpowiadające termowi Term
browse(Term) :-
    browse_helper(Term, []).

% Predykat pomocniczy do obchodzenia drzewa
browse_helper(Term, Path) :-
    write(Term),
    nl,
    read_command(Command),
    process_command(Command, Term, Path).

% Predykat czytający polecenie od użytkownika
read_command(Command) :-
    write('command: '),
    read_atom(Command).

% Predykat przetwarzający polecenie
process_command(i, Term, Path) :-
    Term =.. [_|Args],
    (Args = [Child | _] -> true ; browse_helper(Term, Path)),
    browse_helper(Child, [Term|Path]).

process_command(o, _, [Parent|Path]) :-
    browse_helper(Parent, Path).

process_command(n, Term, [Parent|Path]) :-
    Parent =.. [_ | ParentTerm],
    (append(_, [Term , NextTerm | _ ], ParentTerm) -> true ; browse_helper(Term, [Parent|Path])),
    browse_helper(NextTerm, [Parent|Path]).

process_command(p, Term, [Parent | Path]) :-
    Parent =.. [_ | ParentTerm],
    (append(_, [PreviousTerm, Term | _ ], ParentTerm) -> true ; browse_helper(Term, [Parent|Path])),
    browse_helper(PreviousTerm, [Parent|Path]).

% Predykat czytający atom (polecenie) od użytkownika
read_atom(Atom) :-
    read_line_to_string(user_input, Line),
    atom_string(Atom, Line).
