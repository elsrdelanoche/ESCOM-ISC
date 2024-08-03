%ventana rectangular
ventana1 = ones(1,9);
plot(ventana1)

transformada1 =  fft (ventana1, 512);
transshift1 = fftshift(transformada1);
trans1 = 10*log10(abs(transshift1));
plot (trans1);

%grafica de una ventana triangular
%ventana 2 =
ventana2 = triang(9);
plot (ventana2);

transformada2 = fft(ventana2, 512);
transshift2 = fftshift(transformada2);
trans2 = 10*log10(abs(transshift2));
plot(trans2);

%grafica de una ventana hamming
ventana3 = hamming(32);
plot(ventana3);
%wvtool(ventana3);
transformada3 = fft(ventana3,512);
transshift3 = fftshift(transformada3);
trans3 = 10*log10(abs(transshift3));
plot(trans3)

%blackman-harris
ventana4 = blackman (9);
plot (ventana4)
transformada4 = fft(ventana4, 512);
transshift4 = fftshift(transformada4);
trans4 = 10*log10(abs(transshift4));
plot(trans4)

%barlet
ventana5 = bartlett(9);
plot (ventana5);

transformada5 = fft(ventana5, 512);
transshift5 = fftshift(transformada5);
trans5 = 10*log10(abs(transshift5));
plot(trans5);

%kaiser
ventana6 = kaiser(9);
plot (ventana6);

transformada6 = fft(ventana6, 512);
transshift6 = fftshift(transformada6);
trans6 = 10*log10(abs(transshift6));
plot(trans6);

%gaussiana
ventana7 = gausswin(9);
plot (ventana7);

transformada7 = fft(ventana7, 512);
transshift7 = fftshift(transformada7);
trans7 = 10*log10(abs(transshift7));
plot(trans7);

%flat top
ventana8 = flattopwin(9);
plot (ventana8);

transformada8 = fft(ventana8, 512);
transshift8 = fftshift(transformada8);
trans8 = 10*log10(abs(transshift8));
plot(trans8);