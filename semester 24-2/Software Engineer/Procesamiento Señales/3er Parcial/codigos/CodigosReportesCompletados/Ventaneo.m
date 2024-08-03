%Grafica de una ventan rectangular
Ventana1= ones(1,9);
plot(Ventana1);

%Transformada de ventana 1
transformada1=fft(Ventana1,512);
transshift1=fftshift(transformada1);
trans1=10*log10(abs(transshift1));
plot(trans1);

%Grafica de una ventana triangular
ventana2=triang(9);
plot(ventana2);

transformada2= fft(ventana2,512);
transshift2= fftshift(transformada2);
trans2=10*log10(abs(transshift2));
plot(trans2);
%Grafica de una ventana Haming
ventana3=hamming(32);
plot(ventana3);
%wvtool(ventana3);
transformada3=fft(ventana3,512);
transshift3= fftshift(transformada3);
trans3=10*log10(abs(transshift3));
plot(trans3);
%Grafica de una ventana de blackman-harris

ventana4= blackman(4);
plot(ventana4);

transformada4=fft(ventana4,512);
transshift4= fftshift(transformada4);
trans4= 10*log10(abs(transshift4));
plot(trans4);
%Graficas de una ventana de Barlet
ventana5=bartlett(9);
plot(ventana5);

transformada5=fft(ventana5,512);
transhift5=fftshift(transformada5);
trans5=10*log10(abs(transhift5));
plot(trans5);

%Grafica Gaussiana
ventana5=gausswin();
plot(ventana5);

transformada5=fft(ventana5,512);
transhift5=fftshift(transformada5);
trans5=10*log10(abs(transhift5));
plot(trans5);
