fs = 400;
t = [0:1/fs:1.5];
xt = 2 * sin (4 * pi * t);
%diezmado de la señal xt 
ydiezmada = decimate (xt, 4);

subplot (2, 2, 1)
%stem （t,x）
stem (0:120, xt(1:121), 'filled', 'MarkerSize', 3)
grid on 
xlabel ("Tiempo");
ylabel ("Señal Original x(t)");

subplot (2, 2, 2)
%stem (y)
stem (0:30, ydiezmada(1:31), 'filled', 'MarkerSize', 3)
grid on
xlabel("Tiempo");
ylabel("Señal Diezmada y(t)");

%%%%%%%%%%%%INTERPOLACION
%interpolacion de la señal xt 
yinterpolada = interp (xt, 4);

subplot (2, 2, 3)
stem (0:30, xt(1:31), 'filled', 'MarkerSize', 3)
grid on
xlabel ("Tiempo");
ylabel ("Señal Original x(t)");

subplot (2, 2, 4)
stem (0:120, 1:121,'filled', 'MarkerSize', 3)
xlabel ("Tiempo");
ylabel ("Señal Interpolada y(t)");