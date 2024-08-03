%Entregable         1-Teorema de muestreo
%Grupo              5CV1
%Equipo:            Equipo 5
%Intregrantes:      Bautista Rios Jose Alfredo
%                   Cineros Araujo Karen 
%                   Contreras Vargas Oscar Daniel
%                   Cortes Velazquez Samuel Alejandro
%                   Ramirez Aguirre Jose Alfredo

%Definicion de eje x
% Segundo ejemplo: Frecuencia aún más alta
fs= 40;
t=[0:1/fs:1.5];
xt= 2 * sin (16*pi*t); % Frecuencia aún más alta, 16 Hz
stem(t,xt);
