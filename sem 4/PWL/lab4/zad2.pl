lewy(L, P, [L, P | _]).
lewy(L, P, [_ | X]) :-
    lewy(L, P, X).

obok(A, B, L) :-
    lewy(A, B, L);
    lewy(B, A, L).

rybki(Kto) :-
    % nr, mieszkaniec, kolor, picie, palenie, zwierzę
    Rozwiązanie = [[1, _, _, _, _, _], [2, _, _, _, _, _], [3, _, _, _, _, _], [4, _, _, _, _, _], [5, _, _, _, _, _]],
    member([1, norweg, _, _, _, _], Rozwiązanie),
    member([_, anglik, czerwony, _, _, _], Rozwiązanie),
    lewy([_, _, zielony, _, _, _], [_, _, biały, _, _, _], Rozwiązanie),
    member([_, duńczyk, _, herbatka, _, _], Rozwiązanie),
    obok([_, _, _, _, light, _], [_, _, _, _, _, kot], Rozwiązanie),
    member([_, _, żółty, _, cygaro, _], Rozwiązanie),
    member([_, niemiec, _, _, fajka, _], Rozwiązanie),
    member([3, _, _, mleko, _, _], Rozwiązanie),
    obok([_, _, _, _, light, _], [_, _, _, woda, _, _], Rozwiązanie),
    member([_, _, _, _, bez_filtra, ptak], Rozwiązanie),
    member([_, szwed, _, _, _, pies], Rozwiązanie),
    obok([_, norweg, _, _, _, _], [_, _, niebieski, _, _, _], Rozwiązanie),
    obok([_, _, _, _, _, koń], [_, _, żółty, _, _, _], Rozwiązanie),
    member([_, _, _, piwo, mentolowe, _], Rozwiązanie),
    member([_, _, zielony, kawa, _, _], Rozwiązanie),
    member([_, Kto, _, _, _, rybka], Rozwiązanie).

/* Norweg zamieszkuje pierwszy dom
Anglik mieszka w czerwonym domu.
Zielony dom znajduje się bezpośrednio po lewej stronie domu białego.
Duńczyk pija herbatkę.
Palacz papierosów light mieszka obok hodowcy kotów.
Mieszkaniec żółtego domu pali cygara.
Niemiec pali fajkę.
Mieszkaniec środkowego domu pija mleko.
Palacz papierosów light ma sąsiada, który pija wodę.
Palacz papierosów bez filtra hoduje ptaki.
Szwed hoduje psy.
Norweg mieszka obok niebieskiego domu.
Hodowca koni mieszka obok żółtego domu.
Palacz mentolowych pija piwo.
W zielonym domu pija się kawę. */