%Limpiar una señal ruidosa
clear all;
close all;
clc;

%Para la practica se crea una señal con dos frecuencias
dt = .001;
t = 0:dt:1;
%sumar dos señales en diferente frecuencia
%esta señal es la señal limpia
fclean = sin(2*pi*t*50) + sin(2*pi*t*120);
%a continuacion se agrega ruido a la señal
f = fclean + 2.5*randn(size(t));
%graficar ambas señales
figure (1);
subplot(2,1,1);
plot(fclean); title("Señal original Limpia");
subplot(2,1,2);
plot(f); title("Señal original limpia + ruido");

%Obtener la longitud de t
n = length(t);
%Calcular la FFT
fhat = fft(f, n);
fhatclean = fft(fclean, n);
%graficar la fft
%figure (2);
%plot(fhat);
%Obtener el espectro de nuestra señal
%Obtener la densidad de energia de nuestra señal
PSD = fhat.*conj(fhat)/n;
PSDclean = fhatclean.*conj(fhatclean)/n;
%obtener la frecuencia de nuestra señal en Hz, para eje x
freq = 1/(dt*n)*(0:n);
%obtener la primera parte de la señal
L = 1:floor(n/2);

%graficar PSD para señal limpia y ruidosa
figure (2);
subplot (2,1,1);
plot(freq(L), PSDclean(L));
title("Espectro de la señal limpia");
subplot(2,1,2);
plot(freq(L), PSD(L));
title("Espectro de la señal ruidosa");

%%%Filtrar y calcular la IFFT
%Encontrar las frecuencias que deseemos eliminar
indices = PSD > 50;
%Hacer ceros las frecuencias menores a 50
PSD2 = PSD.*indices;
%Hacer ceros los coeficientes de la transformada
fhat2 = fhat.*indices;
%Graficar el espectro "limpio"
figure(3)
plot(freq(L), PSD2(L));
title("Se eliminan menores a 50");
%obtener la fft inversa de fhat
ifftfhat2 = ifft(fhat2);
%obtener la fft inversa de la PSD2
ifftPSD2 = ifft(PSD2);
%graficar la señal con espectro limpio
figure(4);
subplot(2,1,1);
plot(fclean); title("Señal original Limpia");
subplot(2,1,2);
plot(ifftfhat2);
title("Señal reconstruida a partir del espectro ruidoso");
