% lista(N, X) = dla danego N, lista X:
% ma długość 2*N,
% każda liczba od 1 do N występuję na niej dokładnie dwa razy,
% między dwoma kolejnymi wystąpieniami tej samej liczby jest parzysta liczba innych liczb.

% alternatywnie

% każda liczba musi być raz na parzystym i raz na nieparzystym miejscu w L (parzysty odstęp)
% ze względu na rosnącą numerację:
% na nieparzystych miejscach są kolejno liczby od 1 do N
% na parzystych miejscach jest dowolna permutacja tych liczb
% (dlatego jest n! takich list - każda odpowiada permutacji)

lista(N, L) :-
    numlist(1, N, A), % A to lista 1 do N
    nieparzyste(L, A), % zawartość A jest na nieparzystych miejscach w N (i wypełnia wszystkie)
    permutation(A, B), % B to permutacja A
    parzyste(L, B). % zawartość B jest na parzystych miejscach w N (i wypełnia wszystkie)

nieparzyste([], []).
nieparzyste([X, _|L], [X|R]) :-
    nieparzyste(L, R).

parzyste([], []).
parzyste([_, X|L], [X|R]) :-
    parzyste(L, R).

% between(1, 12, X), time((lista(X, _), fail)).

% N         N!             inf           avg
% 1         1              21            21.00
% 2         2              35            17.50
% 3         6              84            14.00
% 4         24             311           12.96
% 5         120            1600          13.33
% 6         720            10215         14.19
% 7         5040           76406         15.16
% 8         40320          651391        16.16
% 9         362880         6225180       17.15
% 10        3628800        65880335      18.15
% 11        39916800       764600170     19.15
% 12        479001600      nie liczy     ?
