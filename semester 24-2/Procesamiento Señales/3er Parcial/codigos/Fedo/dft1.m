f = zeros(30,30);
f(5:24,13:17) =1;
imshow (f,'InitialMagnification','fit');
F = fft2(f);
F2 = log(abs(F));
imshow (F2, [-1 5],'InitialMagnification','fit');
colormap(jet);colorbar;

%f2 = log(abs(f));
%imshow(f2, [-1 5],'InitialMagnification','fit');
%colormap(jet);colorbar;

F = fft2(f,256,256);
F2  = fftshift(F);
F3 = log(abs(F2));
imshow (F3, [-1 5],'InitialMagnification','fit');
colormap(jet);colorbar;