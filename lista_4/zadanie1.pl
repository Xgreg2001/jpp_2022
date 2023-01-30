factorial(0, 1).
factorial(N, M) :- N > 0, 
    Prev is N -1, 
    factorial(Prev, M1), 
    M is M1 * N.

:- factorial(5,W), writeln(W).

gcd(A, 0, A).
gcd(A, B, G) :- B > 0, 
    C is A mod B, 
    gcd(B, C, G).

:- gcd(12, 18, W), writeln(W).

extended_gcd(A, 0, A, 1, 0).
extended_gcd(A, B, G, X, Y) :- B > 0, 
    C is A mod B, 
    D is A // B, 
    extended_gcd(B, C, G, X1, Y1), 
    X is Y1, 
    Y is X1 - Y1 * D.


solve_equation(A, B, C, X, Y) :- 
    extended_gcd(A, B, G, X1, Y1), 
    C mod G =:= 0,
    X is X1 * (C // G), 
    Y is Y1 * (C // G).

:- solve_equation(43, 7, 17, X, Y), writeln(X), writeln(Y).