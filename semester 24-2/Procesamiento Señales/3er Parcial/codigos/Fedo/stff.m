% short time fourier transform
% longitud de mi señal 
L = 128;
% frecuencia de muestreo para x1
fs1 = 0.22;
% frecuencia de muestreo para x2
fs2 = 0.34;
% crear eje de las x
n = 0:L-1;
% generacion de la primera señal
x1 = 2 * sin (4 * pi * fs1 * n);
% generacion de la segunda señal
x2 = 2 * sin (8 * pi * fs2 * n);
% graficar la primera señal
subplot (4,1,1);
plot (n,x1);
% graficar la segunda señal
subplot (4,1,2);
plot (n,x2);
% crear una tercera señal, la cual estara compuesta por 
% 64 muestras de x1 y 64 muestras de x3
x3 = x1(1:L/2);
x3 ((L/2)+1:L) = x2 (1:L/2);
% graficar la tercera señal
subplot (4,1,3);
plot (n,x3);
% transormada de x3
subplot (4,1,4);
specgram (x3, L/2, 1, hamming(32),0);