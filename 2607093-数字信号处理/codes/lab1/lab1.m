%实验1：系统响应及系统稳定性
close all;clear

%=====内容1：调用filter解差分方程,由系统对u(n)的响应判断稳定性=====
A=[1,-0.9];B=[0.05,0.05];%系统差分方程系数向量B和A 
x1n=[1 1 1 1 1 1 1 1 zeros(1,50)];%产生信号xl(n)=R8(n)
x2n=ones(1,128);%产生信号x2(n)=u(n)
hn=impz(B,A,58);%求系统单位脉冲响应h(n)
subplot(2,2,1);y='h(n)';tstem(hn,y);%调用函数tstem绘图
title('(a)系统单位脉冲响应h(n)');box on 
y1n=filter(B,A,x1n);%求系统对xl(n)的响应yl(n)
subplot(2,2,2);y='y1(n)';tstem(y1n,y);
title('(b)系统对R8(n)的响应y1(n)');box on 
y2n=filter(B,A,x2n);%求系统对x2(n)的响应y2(n)
subplot(2,2,4);y='y2(n)';tstem(y2n,y);
title('(c)系统对u(n)的响应y2(n)');box on

%=====内容2：调用conv 函数计算卷积=====
x1n=[1 1 1 1 1 1 1 1];%产生信号x1(n)=R8(n)
h1n=[ones(1,10) zeros(1,10)];h2n=[1 2.5 2.5 1 zeros(1,10)];
y21n=conv(h1n,x1n);
y22n=conv(h2n,x1n);
figure(2)
subplot(2,2,1);y='h1(n)';tstem(h1n,y);%调用函数tstem绘图
title('(d)系统单位脉冲响应h1(n)');box on
subplot(2,2,2);y='y21(n)';tstem(y21n,y);
title('(e)hl(n)与R8(n)的卷积y21(n)');box on 
subplot(2,2,3);y='h2(n)';tstem(h2n,y);%调用函数tstem绘图
title('(f)系统单位脉冲响应h2(n)');box on 
subplot(2,2,4);y='y22(n)';tstem(y22n,y);
title('(g)h2(n)与R8(n)的卷积y22(n)');box on

%====内容3：谐振器分析====
un=ones(1,256);%产生信号u(n)
n=0:255;
xsin=sin(0.014*n)+sin(0.4*n);%产生正弦信号
A=[1,-1.8237,0.9801];B=[1/100.49,0,-1/100.49];%系统差分方程系数向量B和A 
y31n=filter(B,A,un);%谐振器对u(n)的响应y31(n)
y32n=filter(B,A,xsin);%谐振器对u(n)的响应y31(n)
figure(3)
subplot(2,1,1);y='y31(n)';tstem(y31n,y);
title('(h)谐振器对u(n)的响应y31(n)');box on 
subplot(2,1,2);y='y32(n)';tstem(y32n,y);
title('(i)谐振器对正弦信号的响应y32(n)');box on

function tstem(xn,yn)
%时域序列绘图函数
% xn:信号数据序列，yn:绘图信号的纵坐标名称（字符串）
n=0:length(xn)-1;
stem(n,xn,'.');
xlabel('n');ylabel(yn);
axis([0,n(end),min(xn),1.2*max(xn)])