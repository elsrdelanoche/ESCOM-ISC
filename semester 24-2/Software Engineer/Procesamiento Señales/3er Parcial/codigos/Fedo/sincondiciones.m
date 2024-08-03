%Ejemplo de un sistema de filtro. Se deben calcular las primeras
%20 muestras ed Y.
%Calcular
 %y(n) = 2x(n) - 4x(n-1) - 0.5y(n-1) - y(n-2)
 %Este sistema tiene las siguientes condiciones iniciales
 %y(-2)=1
 %y(-1)
 %x(-1) = -1
%Este sistema tiene como entrada x
%x(n) = 0.8^n*u(n)

    %Definir vector de salida
    y = zeros(1,20);
    %Ajuste a Y, donde creamos espacio para condiciones iniciales
    y = [1 0 y];
    %Generar el tiempo n
    n = 0:1:19;
    %Calcular las primeras 20 muestras de x
    x = 0.8.^n;
    %Ajuste de x, donde creamos espacio para condiciones iniciales
    %x(-2) = 0
    %x(-1) = 0
    x = [0 -1 x];


    %Calcular las 20 muestras de salida
    for n=1:20
        y(n+2) = 2*x(n+2) - 4*x(n+1) - 0.5*y(n+1) - y(n);
    end

    %Generar el tiempo n
    n = 0:1:19;
    %Graficar x(n)
    subplot(3,1,1); stem (n,x(3:22)); xlabel('Tiempo'); ylabel('x(n)');
    %Graficar x(n)
    subplot(3,1,2); stem (n,y(3:22)); xlabel('Tiempo'); ylabel('y(n)');


    %Sin cndiciones iniciales
     %Definir vector de salida
    y = zeros(1,20);
    %Ajuste a Y, donde creamos espacio para condiciones iniciales
    y = [0 0 y];
    %Generar el tiempo n
    n = 0:1:19;
    %Calcular las primeras 20 muestras de x
    x = 0.8.^n;
    %Ajuste de x, donde creamos espacio para condiciones iniciales
    x = [0 0 x];

    %Calcular las 20 muestras de salida
    for n=1:20
        y(n+2) = 2*x(n+2) - 4*x(n+1) - 0.5*y(n+1) - y(n);
    end

    %Generar el tiempo n
    n = 0:1:19;
    %Graficar x(n)
    subplot(3,1,3); stem (n,y(3:22)); xlabel('Tiempo'); ylabel('x(n)');
    %Graficar x(n)