clear all;%���workspaces
fs = 100;%����Ƶ��
N = 256;%��������

%-----------���ɳ弤��Ӧ--------------
x=(-10:0.1:10)*fs/200;
y=(x==0); %ֻ��x=0��ֵ       
figure(1);
subplot(2,1,1);
plot(x,y);

%---------��Ƶ�ױ任�뻭ͼ------------
y1 = abs(fft(y,N));
f = (0:length(y1)-1)*fs/length(y1);
subplot(2,1,2);
plot(f,y1);
