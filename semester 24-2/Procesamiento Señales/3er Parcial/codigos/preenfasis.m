%Diseño de un filtro preenfasis (pre-emphasis)
%Como primer punto, leeremos un archivo a filtrar, y posteriormente
%grabar la voz
close all;
clear all;
clc;
%Definir la frecuencia de muestreo
fs = 8000;
%Alphha es el factor de filtrado
alpha = 0.9;
%Lectura del archivo con voz (en etse momento ECG)

figure (1);
%Calcular y graficas la respuesta a la frecuencia
freqz(1-alpha,1,512,fs);
%Cargar el archivo - se deberá intercambiar en la pt 2 de la practica
%%voz = load("ECG.txt");
% grabacion de voz
% vector donde se grabara la voz
grabacion = audiorecorder;
% tiempo que se grabara la voz
tiempo = 2;
disp("comienza grabacion");
recordblocking(grabacion, tiempo);
disp("termina grabacion");
play(grabacion);
voz = getaudiodata(grabacion);
plot(voz);
%----------------
figure (2);
%aplicamos el filtro para la voz
y = filter(1-alpha, 1, voz);
%Primera imagen, voz original
subplot (2,1,1); xlabel('Numero de muestras'); ylabel('Muestras de voz');
title('Voz: Original'); plot(voz);
subplot(2,1,2); xlabel('Numero de muestras'); ylabel('Muestras de voz');
title('Voz: filtro preenfasis'); plot(y);

figure (3);
% se necesita saber la longitud de voz
N = length(voz);
% espectro de la voz original
Axk = abs(fft(voz.*hamming(N)'))/N;
% espectro de la voz con filtro preenfasis
Ayk = abs(fft(y.*hamming(N)'))/N;
% frecuencia
f = (0:N/2)*fs/N;
% ---------------------
% obtener nuevamente el espectro de la voz original
Axk(2:N) = 2*Axk(2:N);
% obtener nuevamente el espectro de la voz con filtro
Ayk(2:N) = 2*Ayk(2:N);
% grafica de la voz original
subplot(2,1,1); plot (f,Axk(1:N/2+1));
xlabel("frequencia Hz"); ylabel("Espectro de amplitud Axk");
title('Voz original');
% grafica de la voz con filtro preenfasis
subplot(2,1,2); plot(f, Ayk(1:N/2+1));
xlabel('frecuencia Hz'); ylabel('Espectro de amplitud Ayk');
title('Voz con filtro preenfasis');