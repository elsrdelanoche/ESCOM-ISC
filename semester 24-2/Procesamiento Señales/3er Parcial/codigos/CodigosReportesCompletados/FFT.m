%Se debera construir una  imagen f(m,n), donde
%tolo lo que se encuentre dentro de dicha region
%valdra 1 y todo lo que se encuentre fuera
%valdra 0

%Imagen de 30*30 tendra todo en 0
f=zeros (30,30);
%Definimos una region dentro de la funcion.
f(5:24,13:17)=1;;
imshow(f,'InitialMagnification','fit')
%Calcular de la FFT de 2 dimensiones
F=fft2(f);
F2=log(abs(f));
imshow(F2,[-1,5],'InitialMagnification','fit');
colormap("jet"); colorbar;
%Para visualizacion de la imagen, agregamos mas pixeles
%hasta tener una matriz de 256*256
%f2=log(abs(f));
%imshow(f2,[-1,5],'InitialMagnification', 'fit');
%colormap("jet");colorbar;
F=fft2(f,256,256);
F2=fftshift(F);
F3=log(abs(F2));
imshow(F3,[-1,5],'InitialMagnification','fit');
colormap("jet"); colorbar;
