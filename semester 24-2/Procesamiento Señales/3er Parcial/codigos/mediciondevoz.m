%Grabación de voz
%vector donde se grabará la voz
voz = audiorecorder;
%tiempo que se grabarå la voz en segundos
tiempo =5;
disp('Comienza grabación');
recordblocking(voz,tiempo);
disp('Termina grabación');
play(voz);
voz2= getaudiodata(voz);
plot(voz2);
