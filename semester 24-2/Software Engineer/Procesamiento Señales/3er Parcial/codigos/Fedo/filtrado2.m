%Ejemplo para la verificación de la solución A
B= [0 1];
A= [1 0 -0.5];
x= [1 0.5 .25 0.125];
Xi = [-1 0];
Yi = [0 1];
Zi = filtic(B,A,Yi,Xi);
y = filter(B,A,x,Zi);