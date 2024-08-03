%Señal estacionaria
%La señal de ejemplo consiste en dos frecuencias
%   0.22 Hz y 0.34 HZ
%Esta señal con dos frecuencias existen en todo el tiempo

clear all;
close all;
clc;

% definir el tamaño de las muestras
N = 128;
n = 0:1:N-1;
% frecuencia de muestreo 1
fs1 = 0.22;
% frecuencia de muestreo 2
fs2 = 0.34;
% definicion de la señal
x = sin (2 * pi * n * fs1) + sin (2 * pi * n * fs2);

% transofrmada de fourier
fx = fft(x, N);
% definir omega
wn = 2 * ((N-1)/N);
% crear un eje x para grafica
k = linspace(0,wn/2,128);
% graficar la señal
figure(1)
plot(x); title("Señal estacionaria"); xlabel("tiempo");
ylabel("amplitud");
% grafica para cwt
figure(2);
coefs = cwt(x,1:32,'sym6');
mesh(abs(coefs))
% grafica de la transformada
figure(3);
plot(k,abs(fx)); title("Señal estacionaria: FFT"); xlabel("Frecuencia");
ylabel("Magnitud");