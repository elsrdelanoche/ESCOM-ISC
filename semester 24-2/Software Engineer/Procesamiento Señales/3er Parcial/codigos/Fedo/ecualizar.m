%%Programa: ecualizar.m
%%Nombre: José Antonio Flores Escobar - MISTI
%%Descripción: Ecualizar un histograma.
clc;
clear all;
format long eng;
x=imread('2lena512x512','bmp');            %%Se lee la imagen
figure(1);
imshow(x);
x=double(x);
[a b]=size(x);                             %%Obtenemos el tamaño de la matriz
nuevaimagen=zeros(a,b);                    %%Aqui va a ir mi nueva matriz, que sera mi nueva imagen
colores=zeros(256,2);
colores(:,1)=(0:255);                      %%Nuestra matriz que contara los colores

%Contamos cuantos colores iguales hay en la matriz
for i=0 :a-1
    for j=0:b-1
        color=x(i+1,j+1);                  %%Este es el color
        numero=colores(color+1,2);         %%Cuantos colores iguales se han encontrado
        colores(color+1,2)=numero+1;
    end
end

%%El total de colores encontrados es a*b y es igual a sum(colores(:,2))
total=sum(colores(:,2));                 
colores=[colores,(colores(:,2))/total];    %%Agregamos una tercer columna a colores
maximo=max(max(x));
acumular=zeros(256,1);                     %%Aqui vamos a acumular
acumulado=0;

%%En esta parte calculamos el vector con las nuevas escalas de grises
for i=1:maximo
    acumulado=acumulado+colores(i,3);
    acumular(i)=acumulado;                 %%Aqui acumulamos
end;
acumular=round(acumular*255);              %%Multiplicamos por 255 para obtener la nueva gama de grises (redondeamos)
colores=[colores,acumular];

%%Aqui hacemos la ecualizacion, tambien lo encontre como "igualacion" y/o
%%"transformada"
for i=1:a
    for j=1:b
        nuevaimagen(i,j)=acumular(x(i,j)); %%Llenamos la nueva matriz (que sera la nuestra imagen ecualizada) con los nuevos valores calculados
    end
end

%%Aqui mostramos la imagen ecualizada
nuevaimagen=uint8(nuevaimagen);
imwrite(nuevaimagen,'222.bmp');
figure(2);
imshow(nuevaimagen);