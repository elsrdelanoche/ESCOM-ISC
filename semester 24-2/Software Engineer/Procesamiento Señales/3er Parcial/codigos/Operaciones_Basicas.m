%Entregable         1-Teorema de muestreo
%Grupo              5CV1
%Equipo:            Equipo 5
%Alumno:            Contreras Vargas Oscar Daniel 

% Definición de las señales (ejemplo)
x = [3, 7, 12, 18, 23, 29, 34, 39, 44, 50]; % Primera señal
y = [8, 16, 24, 32, 40, 48, 56, 64, 72, 80]; % Segunda señal
a = 2; % Escalar
n = 2; % Desplazamiento

% Suma
suma = x + y;

% Multiplicación
multiplicacion = x .* y;

% Multiplicación escalar
multiplicacionEscalar = a * x; % Multiplicando la primera señal por un escalar

% Desplazamiento
desplazamientoX = circshift(x, n); % Desplazamiento de la señal x
desplazamientoY = circshift(y, n); % Desplazamiento de la señal y

% Time Reversal
timeReversalX = fliplr(x); % Invierte la señal x
timeReversalY = fliplr(y); % Invierte la señal y

% Imprimir resultados
disp('Suma:');
disp(suma);
disp('Multiplicación:');
disp(multiplicacion);
disp('Multiplicación Escalar:');
disp(multiplicacionEscalar);
disp('Desplazamiento x:');
disp(desplazamientoX);
disp('Desplazamiento y:');
disp(desplazamientoY);
disp('Time Reversal x:');
disp(timeReversalX);
disp('Time Reversal y:');
disp(timeReversalY);
