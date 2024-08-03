%Calcular la DFT de una señal discreta
%Definir la señal x(n)
x1 = [1 2 3 4];
y = [0 0 0 0];
N = length(x1);
for k=0:N-1
    for n=0:N-1
        W = exp((-1i*2*pi*k*n)/N);
        x2(k+1, n+1) = W; 
    end 
end    
y = x2*x1';
y = y';
%Graficar y que es la dft de x1
subplot (2,1,1)
stem(x1, abs(y));
%Calcular la dft con la funcion matlab
subplot (2,1,2)
stem(x1,abs(fft(x1)))