fs=10;  %�趨����Ƶ��
t=-5:0.1:5; %ʱ����

%---------------���ɾ�������------------
x=rectpuls(t,2);
x=x(1:99);
figure(1);
subplot(2,1,1);
plot(t(1:99),x);%�����β���ʱ����
xlabel('t');
ylabel('y');
title('���β�ʱ����');
axis([-5,5,-2,2])
grid;

%--------------����FFT�任����Ƶ��ͼ--------------
y=fft(x);%����fft�任
mag=abs(y);%���ֵ
f=(0:length(y)-1)'*fs/length(y);%���ж�Ӧ��Ƶ��ת��
subplot(2,1,2);
plot(f,mag);%��Ƶ��ͼ
xlabel('Ƶ��(Hz)');
ylabel('��ֵ');
title('���β���Ƶ��ͼ');
axis([0,6,-1,25])
grid;