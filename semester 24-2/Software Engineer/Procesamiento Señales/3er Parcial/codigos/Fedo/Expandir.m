%%Alumno: José Antonio Flores Escobar-MISTI
%%Programa: expandir.m
%%Descripción: Expande una imagen, el usuario especifica cuantos pixeles   
%%desea expandir por renglon y por columna, en caso de no querer expandir
%%el numero que se introduce es 1.
clear all;
clc;
images=imread('imagenfinalcomprimida.bmp');
tam=size(images);
images=double(images);
fprintf('\nIMAGEN DE %d x %d PIXELES\n\n',tam(1),tam(2));
numren=input('Cuantos pixeles se expanden por renglon?: ');
numcol=input('Cuantos pixeles se expanden por columna?: ');
picfinal=[];
for renglon=1:tam(1)
    for columna=1:tam(2)
        vector=zeros(numren,numcol);
        vector=vector+images(renglon,columna);
        picfinal((renglon*numren)-(numren-1):renglon*numren,(columna*numcol)-(numcol-1):columna*numcol)=vector;
    end
end
picfinal=uint8(picfinal);
tam=size(picfinal);
fprintf('\nLa imagen que se ha expandido es de %d x %d\n',tam(1), tam(2));
imwrite(picfinal,'imagenfinalexpandida.bmp');
figure (1)
imshow(picfinal)