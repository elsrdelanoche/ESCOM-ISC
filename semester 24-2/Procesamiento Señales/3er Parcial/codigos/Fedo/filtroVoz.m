%Diseño de un filtro preenfasis (pre-enfasis)
%Como primer punto, leeremos un archvio a filtrar, y posteriormente gravar
%la voz
close all;
close all;
clc;
%definir la frecuencia de muestreo
fs = 8000;
%Alpha es el factor de filtrado
alpha = 039;
%Lectura del archivo con voz (En este momento ECG)
figure(1);
%Calcular y graficar la respuesta a la frecuencia
freqz(1-alpha,1,512,fs);
%Cargar el archivo
voz=load("ECG.txt");

figure(2);
%Aplicamos el filtro para voz
y = filter(1-alpha,1,voz);
%La imagen voz original
subplot(2,1,1); plot(voz); xlabel('Numero de muestras'); ylabel('Muestras de voz');
title('Voz original'); 
%2a imagen voz con filtro
subplot(2,1,2); plot(y);
xlabel('Numero de muestras'); ylabel('Muestras de voz');
title('Voz: Filtro Preenfasis'); 
figure(3);
%se necesita saber la longitud de la voz
N=length(voz);
%Espectro de la voz
Axk= abs(fft(voz.*hamming(N)'))/N;
%Espectro de la voz con filtro preenfasis
Ayk= abs(fft(y.*hamming(N)'))/N;
%Frecuencia
f = (0:N/2)*fs/N;



Axk(2:N)=2*Axk(2:N);

Ayk(2:N)=2*Ayk(2:N);

subplot(2,1,1); plot(f,Axk(1:N/2+1));
xlabel("Frecuencia Hz"); ylabel("Espectro de amplitud Axk");
title("Voz Original");

subplot(2,1,2); plot(f,Ayk(1:N/2+1));
xlabel("Frecuencia Hz"); ylabel("Espectro de amplitud Ayk");
title("Voz con filtro preenfasis");