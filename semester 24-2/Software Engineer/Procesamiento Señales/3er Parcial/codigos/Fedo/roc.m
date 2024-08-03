conv([1 -1],[1 -0.5])
[R, P, K] = residue([1 0],[1 -1.5 0.5]);


numerador = conv([1 0 0],[1 1]);
denominador = conv([1 -1],[1 -1 0.5])

[R, P, K] = residue([1 1 0 0], [1 -2 1.5 -0.5]);