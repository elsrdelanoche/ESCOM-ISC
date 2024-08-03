% transformada z
% funcion ztrans()

% definicion de nuestra señal x1
% x1(n) = 1.3*nu(n)

% definir n
n = 0:10;

%definir nuestro escalon unitario
u1 = ones(size(n)); %size regresa cada uno de los elementos
%plot (n,u1)

% operar elemento a elemento (por eso es el punto)
x1 = 1.3.^-n.*u1;
figure, stem (n,x1); title ('x(n)=1.3^-nu(n)'); xlabel('n'); ylabel('x1(n)');

% definir señal x2
% x(n) =  -0.6^nu(-n-1)

% definir escalon unitario
u2 = ones(size(n));

% operar elemento a elemento 
x2 = -0.6.^n.*u2;
figure, stem (n,x2); title ('x(n)=-0.6^-nu(n-1)'); xlabel('n'); ylabel('x2(n)');

% calcular las transformadas
syms n z  % variables simbolicas para la transformada
n1 = 1.3.^-n;
n2 = -0.6.^n;
zn1 = ztrans(n1);
zn2 = ztrans(n2);

% calcular y graficar la rdc x1
m = linspace (-2, 2, 670);
% para crear un mayado para preparar una figura de 2 dimensiones

[x1, y1] = meshgrid(m);
z1 = sqrt(x1.^2+y1.^2);
% definir los valores de la roc (region de convergencia)
roc1 = (z1>1);

%graficar la transformada z
RI = imref2d(size(roc1));
% en este ejemplo el eje x es el eje real
RI.XWorldLimits=[-2,2];
% en este ejemplo el eje y es el eje imaginario
RI.YWorldLimits=[-2,2];

% graficar la funcion de la transformada
figure, imshow(roc1, RI); title('ROC >1'); xlabel('Eje real'); ylabel('Eje Imaginario');

%Hay que interpretar nuestra grafica
% en este ejemplo todos los valores que son mayores a 1, convergen, es
% decir, la parte blanca de nuestra imagen representan los valores
% convergentes y la parte oscura representa los valores que divergen.

% calcular y graficar la roc x2
m = linspace(-2,2,670);
% para crear un mallado para preparar una figura de 2 dimensiones
[x2, y2] = meshgrid(m);

% funcion de un circulo
z2 = sqrt(x1.^2+y1.^2);
% definir los valores de la roc
roc2 = (z2<1);

% graficar la transformada z
RI = imref2d(size(roc2));
% eje de las x es real
RI.XWorldLimits = [-2,2];
% eje de las y es imaginario
RI.YWorldLimits = [-2,2];

% graficar la funcion de la transformada
figure, imshow(roc2,RI); title('ROC < 1'); xlabel('Eje real'); ylabel('Eje Imaginario');