%Limpiar la señal
%denoising
%Cargar la señal predefinida en Matlab
load leleccum;
idx = 2600:3100;
imagenx = leleccum(idx);
%Hacer uso de la funcion ddencmp //default denoising compression
[thr, sorh, keepapp] = ddencmp('den', 'wv', imagenx);
%Hacer uso de la funcion  wdencmp // wavelet denoising compression 
imageny = wdencmp('gbl', imagenx, 'db3', 2, thr, sorh, keepapp);

%Graficar los resultados obtenidos
figure(1);
subplot(2,1,1);
plot(imagenx); 
title('Señal original');
subplot(2,1,2);
plot(imageny);
title('Señal sin ruido');
