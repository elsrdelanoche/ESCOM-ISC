%Definir las wavelets madre
%en este caso definen las wavelets mas empleadas

%se empleaemplean subrutinas de generacion de waveletes de acuerdo
%a la toolbod de waveletes en matlab

%definicion de la primera wavelet madre - daubechies
%en esta wavelet se pueden explorar todas las variaciones
d = dbwavf('db8');
%defincion de la wavelet madre - symlet
%en esta wavelet se pueden explorar todas las variaciones
s = symwavf('sym6');
%Definicion de la wavelet madre - coiflet
%en esta wavelet se pueden explorar todas las variaciones
c = coifwavf('coif3');

%ambiente parpara graficar cada wavelet
%primera parte de wwavelet 
x = [0 250];
y = [-0.045 -0.045];
%Primer grafico
subplot (2, 2, 1);
title('Haar 4');
line(x,y);
%Segunda parte del wavelet
x = [250 400];
y = [-0.045 0.045];
line(x,y);
%tercera parte del wavelet
x = [400 550];
y = [0.045 0.045];
line(x,y);
axis([0, 600, -0.05, 0.05]);
%Segundo grafico
line(x,y);
axis([0, 600, -0.05, 0.05]);
subplot(2, 2, 2);
plot(d);
title('Daubechies - DBB');
%Tercer grafico
subplot(2, 2, 3);
plot(s);
title('Symlet - Sym6');
%Cuarto grafico
subplot(2, 2, 4);
plot(c);
title('Coiflet - coif3');