ojciec(robert, maria).        % robert jest ojcem marii
ojciec(adam, ewa).
matka(ewa, maria).            % ewa jest matką marii
mężczyzna(robert).            % robert jest mężczyzną
mężczyzna(adam).
kobieta(maria).               % maria jest kobietą
kobieta(ewa).
rodzic(robert, maria).        % robert jest rodzicem marii
rodzic(ewa, maria).
rodzic(adam, ewa).
diff(X, Y) :- X \= Y.

jest_matką(X) :- matka(X, Y).
jest_ojcem(X) :- ojciec(X, Y).
jest_synem(X) :- mężczyzna(X),
    rodzic(Y, X).
siostra(X, Y) :- kobieta(X),
    ojciec(O, X),
    ojciec(O, Y),
    matka(M, X),
    matka(M, Y),
    diff(X, Y).
dziadek(X, Y) :- mężczyzna(X),
    ojciec(X, R),
    rodzic(R, Y).
rodzeństwo(X, Y) :- ojciec(O, X),
    ojciec(O, Y),
    matka(M, X),
    matka(M, Y),
    diff(X, Y).

