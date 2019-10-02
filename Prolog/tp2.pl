prem([E|_], E).

rest([_|R], R).

der([E], E).
der([_|X], E):-der(X, E).

elem([E|_],E).
elem([_|X], E) :- elem(X, E).

longueur([], 0).
longueur([_|X], N):-longueur(X, K), N is K+1.

nieme(1, [E|_], X):-E=X.
nieme(N, [_|L], X):-nieme(K, L, X), N is K+1.
