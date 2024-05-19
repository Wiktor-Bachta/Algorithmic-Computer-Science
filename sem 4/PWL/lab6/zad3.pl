anbn --> [].
anbn --> [a], anbn, [b].

% phrase(anbn, [a,a,b,b]).

anbn(0) --> [].
anbn(X) --> [a], anbn(X2), [b], {X is X2 + 1}. 

cn(0) --> [].
cn(X) --> [c], cn(X2), {X is X2 + 1}. 

anbncn --> anbn(X), cn(X).

% phrase(anbncn, [a,a,b,b,c,c]).

an(0) --> [].
an(X) --> [a], an(X2), {X is X2 + 1}. 

bfibn(0) --> [].
bfibn(1) --> [b].
bfibn(X) --> {X > 1, X2 is X - 1, X1 is X - 2}, bfibn(X1), bfibn(X2).

anbfibn --> an(X), bfibn(X).

% phrase(anbfibn, [a,a,a,a,b,b,b]).