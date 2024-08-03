% Señal no estacionaria
% La señal de ejemplo consiste en dos frecuencias
%   0.22 Hz y 0.34 HZ
% Esta señal con dos frecuencias existen en la mitad del tiempo

clear all;
close all;
% clc;

% Definir el tamaño de las muestras
N = 128;
n = 0:1:N-1;
% Frecuencia de muestreo 1
fs1 = 0.22;
% Frecuencia de muestreo 2
fs2 = 0.34;
% señal 1
x1 = sin (2 * pi * n * fs1);
% señal 2
x2 = sin (2 * pi * n * fs2);
% señal 3
x3 = x1(1:N/2);            % low part
x3((N/2)+1:N) = x2(1:N/2); % high part

% transofrmada de fourier
fx = fft(x3, N);
% definir omega
wn = 2 * ((N-1)/N);
% crear un eje x para grafica
k = linspace(0,wn/2,128);
% graficar la señal
figure(1)
plot(x3); title("Señal estacionaria"); xlabel("tiempo");
ylabel("amplitud");
% grafica para cwt
figure(2);
coefs = cwt(x3,1:32,'sym6');
mesh(abs(coefs))
% grafica de la transformada
figure(3);
plot(k,abs(fx)); title("Señal estacionaria: FFT"); xlabel("Frecuencia");
ylabel("Magnitud");
