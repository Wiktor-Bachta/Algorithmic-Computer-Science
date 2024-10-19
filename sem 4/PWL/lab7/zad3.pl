filozofowie :-
    mutex_create(fork1),
    mutex_create(fork2),
    mutex_create(fork3),
    mutex_create(fork4),
    mutex_create(fork5),
    thread_create(filozof(1, fork5, fork1), _, []),
    thread_create(filozof(2, fork1, fork2), _, []),
    thread_create(filozof(3, fork2, fork3), _, []),
    thread_create(filozof(4, fork3, fork4), _, []),
    thread_create(filozof(5, fork4, fork5), _, []).

filozof(N, LeftFork, RightFork) :-
    loop(N, LeftFork, RightFork).

loop(N, LeftFork, RightFork) :-
    format('Filozof ~w: zaczyna myśleć~n', [N]),
    random_think,
    format('Filozof ~w: stara się podnieść lewy widelec~n', [N]),
    mutex_lock(LeftFork),
    format('Filozof ~w: podniósł lewy widelec~n', [N]),
    format('Filozof ~w: stara się podnieść prawy widelec~n', [N]),
    mutex_lock(RightFork),
    format('Filozof ~w: podniósł prawy widelec~n', [N]),
    format('Filozof ~w: je~n', [N]),
    eat,
    format('Filozof ~w: odkłada prawy widelec~n', [N]),
    mutex_unlock(RightFork),
    format('Filozof ~w: odkłada lewy widelec~n', [N]),
    mutex_unlock(LeftFork),
    loop(N, LeftFork, RightFork).

random_think :-
    random_between(1, 5, Time), 
    sleep(Time).

eat :-
    sleep(1).  
