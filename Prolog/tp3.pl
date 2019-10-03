prefixe([], _).
prefixe([X|P], [X|L]):-prefixe(P, L).

suffixe(L, L).
suffixe(S, [_|L]):-suffixe(S, L).

ajouter_fin(X, [], [X]).
ajouter_fin(X, [W|L], [W|R]):-ajouter_fin(X, L, R).

sousliste([], _).
sousliste([X|M],[X|L]):-sousliste(M, L).
sousliste([Y|M],[_|L]):-sousliste([Y|M],L).

sousliste_cons([], _).
sousliste_cons([X|S], [X|L]):-sousliste_cons(S, L).
sousliste_cons(S, [_|L]):-sousliste_cons(S, L).

extraire(_, [], []).
extraire(X, [X|L], R):-extraire(X, L, R).
extraire(X, [E|L], [E|R]):-X\=E, extraire(X, L, R).

pgcd(X, X, X).
pgcd(X, Y, Z):- X<Y, K is Y-X, pgcd(X, K, Z).
pgcd(X, Y, Z):- X>Y, K is X-Y, pgcd(K, Y, Z).