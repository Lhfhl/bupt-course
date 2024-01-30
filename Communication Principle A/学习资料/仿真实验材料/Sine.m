fs=100; %采样频率
N=128;  %采样点数
n=0:N-1;
t=n/fs; %时间轴
f0=10;  %设定正弦信号频率


%-----------------------生成正弦信号-------------------------
x=sin(2*pi*f0*t);
figure(1);
subplot(2,1,1);
plot(t,x);  %作正弦信号的时域波形
xlabel('t');
ylabel('y');
title('正弦信号y=2*pi*10t时域波形');
grid;

%-------------------进行FFT变换并做频谱图-------------------
y=fft(x,N); %进行fft变换
mag=abs(y); %求幅值
f=(0:length(y)-1)'*fs/length(y);    %进行对应的频率转换
subplot(2,1,2);
plot(f,mag);    %做频谱图
axis([0,100,0,80]);
xlabel('频率(Hz)');
ylabel('幅值');
title('正弦信号y=2*pi*10t幅频谱图N=128');