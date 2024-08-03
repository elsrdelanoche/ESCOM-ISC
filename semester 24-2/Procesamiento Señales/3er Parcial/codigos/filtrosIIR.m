%practica :ITR
%limpiamos nuestro workspace
clear
close all
clc
%cargar nuestro archivo ECG.txt
s=load("ECG.txt");
%Parametros iniciales
fs=250;     %fs=frecuencia de muestreo
fc=60;      %fc=frecuencia de corte
n= 6;       %orden del filtro

%Diseño del filtro
wn=fc/(fs/2);   %normalizar la señal con respecto a la 
                %frecuencia de muestreo
%recuperar los coeficientes de a y b. Que son necesarios para la 
%constreccion del filtro.EL filtro a utilizar es ButterWorth 
[b,a]= butter(n, wn, "low");
%respuestas alf filtro
freqz(b,a);
figure()
%si tiene 
s1= filter(b,a,s);
subplot(2,1,1); plot(s);
%graficar señal filtrada
subplot(2,1,2); plot(s1);