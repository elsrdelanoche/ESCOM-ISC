%SHort time Fourier Transform
%Longitud  d emi señal
L=128;
%Frecuencia de muestreo para x1
fs1=0.22;
%Frecuencia de muestreo para x2
fs2=0.34;
%Crear el eje de las x
n=0:L-1;
%Generacion de la primera señal
x1=2 * sin(4 * pi * fs1 * n);
%Generacion de la segunda señal
x2=2 * sin(8 * pi * fs2 * n);
%Graficamo primera señal
subplot(4,1,1)
plot(n,x1)
%Graficamos segunda señal
subplot(4,1,2)
plot(n,x2)
%Crear una tecera señal, la cual estara compuesta por
%64 muestras de x1 y 64 muestras de x2
x3=x1(1:L/2);
x3((L/2)+1:L) = x2 (1:L/2);
%Graficamos tercera señal
subplot(4,1,3);
plot(n,x3);
%Transformada de x3
subplot(4,1,4);
specgram(x3,L/2,1,hamming(32),0);