% grabacion de voz
% vector donde se grabara la voz
voz = audiorecorder;
% tiempo que se grabara la voz
tiempo = 5;
disp("comienza grabacion");
recordblocking(voz, tiempo);
disp("termina grabacion");
play(voz);
voz2 = getaudiodata(voz);
plot(voz2);