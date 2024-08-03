% practica IIR
% limpiar nuestro workspace
clear
close all
clc
% cargar nuestro archivo ecg.txt
s = load("ECG.txt");
fs = 250;                % fs = frecuencia de muestreo
fc = 60;                 % frecuencia de corte de nuestra señal 
n = 6;                   % orden del filtro

% diseño del filtro
wn = fc/(fs/2);          % normalizar la señal con respecto a la frecuencia
                         % de muestreo
% recuperar los coeficientes de a y b. que son necesarios para la
% construccion del filtro. el filtro a utilizar es ButterWorth
[b,a] = butter(n, wn,"low")
% respuesta al filtro
freqz(b,a);
figure()
% s1 tiene nuestra señal filtrada
s1 = filter(b, a, s);
subplot (2,1,1); plot(s);
% graficar señal filtrada
subplot(2,1,2); plot(s1);