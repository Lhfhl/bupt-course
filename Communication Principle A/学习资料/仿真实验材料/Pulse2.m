fs=10;  %设定采样频率
t=-5:0.1:5; %时间轴

%---------------生成矩形脉冲------------
x=rectpuls(t,2);
x=x(1:99);
figure(1);
subplot(2,1,1);
plot(t(1:99),x);%作矩形波的时域波形
xlabel('t');
ylabel('y');
title('矩形波时域波形');
axis([-5,5,-2,2])
grid;

%--------------进行FFT变换并做频谱图--------------
y=fft(x);%进行fft变换
mag=abs(y);%求幅值
f=(0:length(y)-1)'*fs/length(y);%进行对应的频率转换
subplot(2,1,2);
plot(f,mag);%做频谱图
xlabel('频率(Hz)');
ylabel('幅值');
title('矩形波幅频谱图');
axis([0,6,-1,25])
grid;