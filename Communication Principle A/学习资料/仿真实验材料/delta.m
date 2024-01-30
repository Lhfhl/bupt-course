clear all;%清空workspaces
fs = 100;%采样频率
N = 256;%采样点数

%-----------生成冲激响应--------------
x=(-10:0.1:10)*fs/200;
y=(x==0); %只在x=0有值       
figure(1);
subplot(2,1,1);
plot(x,y);

%---------做频谱变换与画图------------
y1 = abs(fft(y,N));
f = (0:length(y1)-1)*fs/length(y1);
subplot(2,1,2);
plot(f,y1);
