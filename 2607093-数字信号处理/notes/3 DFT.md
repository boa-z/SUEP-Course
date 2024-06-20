# 3 离散傅里叶变换(DFT)

[Discrete Fourier Transform (DFT)](https://home.engineering.iastate.edu/~julied/classes/ee524/LectureNotes/l5.pdf)

[Lecture 7 - The Discrete Fourier Transform](https://www.robots.ox.ac.uk/~sjrob/Teaching/SP/l7.pdf)

[Chapter 4 - THE DISCRETE FOURIER TRANSFORM](https://web.mit.edu/~gari/teaching/6.555/lectures/ch_DFT.pdf)

## 3.1 离散傅里叶变换的定义及物理意义

### 3.1.1 DFT 的定义

设 $x(n)$ 是一个长度为 $M$ 的有限长序列，则定义 $x(n)$ 的 $N$ 点离散傅里叶变换为

$$
\color{#E45F59}
X(k) = \mathrm{DFT}[x(n)] = \sum_{n = 0}^{N - 1} x(n) W_N^{kn} \ \ \ 0 \leq k \leq N - 1 \\
x(n) = \mathrm{IDFT}[X(k)] = \frac{1}{N} \sum_{k = 0}^{N - 1} X(k) W_N^{-kn} \ \ \ 0 \leq n \leq N - 1 \\
$$

其中 $\color{#E45F59}{W_N = e^{-j\frac{2\pi}{N}}}$ 称为旋转因子。N称为DFT变换区间长度，$N \geq M$。

---

Example:【例3.1.1】 $x(n)=R_4 (n)$, 求x(n)的4点和8点DFT。

解：

设变换区间为 $N=4$, 则

$$
\begin{align*}
    X(k)
    &= \sum_{n=0}^{N-1} x(n) W_N^{kn} \\
    &= \sum_{n=0}^{3} \exp(-j\frac{2\pi}{4}kn) \\
    &= \frac{1-\exp(-j\frac{2\pi}{4}k4)}{1-\exp(-j\frac{2\pi}{4}k)} \\
    &= \begin{cases}
        4 & k = 0 (?????)\\
        0 & k = 1, 2, 3 \\
    \end{cases}
\end{align*}
$$

注: $e^{-j 2\pi} = 1$

设变换区间为 $N=8$, 则

$$
\begin{align*}
    X(k)
    &= \sum_{n=0}^{N-1} x(n) W_N^{kn} \\
    &= \sum_{n=0}^{3} e^{-j\frac{2\pi}{8}kn} \\
    &= \frac{1-\exp(-j\frac{2\pi}{8}k4)}{1-\exp(-j\frac{2\pi}{8}k)} \\
    &= \exp(-j\frac{3\pi}{8}k) \frac{\sin(\frac{\pi}{2}k)}{\sin(\frac{\pi}{8}k)} \\
\end{align*}
$$

关于这个难蚌欧拉

```nb
f[k_] := (1 - Exp[-I 2 Pi/8 k 4])/(1 - Exp[-I 2 Pi/8 k])
g[k_] := Exp[-I 3 Pi/8 k] Sin[Pi/2 k]/Sin[Pi/8 k]
Simplify[f[k] == g[k]]
```

### 3.1.2 DFT 与傅里叶变换和Z变换的关系

设 $x(n)$ 是一个长度为 $M$ 的有限长序列

$$
\color{#E45F59}{X(z) = \mathrm{ZT}[x(n)] = \sum_{n = -\infty}^{\infty} x(n) z^{-n} = \sum_{n = 0}^{M-1} x(n) z^{-n}} \\
X(e^{j\omega}) = \mathrm{DTFT}[x(n)] = \sum_{n = -\infty}^{\infty} x(n) e^{-j\omega n} \\
X(k) = \mathrm{DFT}[x(n)]_N = \sum_{n = 0}^{M - 1} x(n) W_N^{kn} \ \ \ 0 \leq k \leq N - 1 \\
$$

比较上面二式可得关系式

$$
\begin{split}
    X(k)
    &= X(z) \bigg|_{z=e^{j\frac{2\pi}{N}k}} \\
    &= X(e^{j\omega}) \bigg|_{\omega=\frac{2\pi}{N}k} \\
\end{split}
$$

**DFT与Z变换的关系**
表明序列 $x(n)$ 的 N点DFT是 $x(n)$ 的Z变换在单位圆上的N点等间隔采样。

**DFT与傅里叶变换的关系**
说明 $X(k)$ 为 $x(n)$ 的傅里叶变换 $X(e^{j\omega})$在区间 $[0, 2\pi]$上的N点等间隔采样。
（这是离散傅里叶变换的物理意义。）

### 3.1.3 DFT的隐含周期性

任何周期为N的周期序列 $\tilde{x}(n)$ 都可以看做长度为N的有限长序列 $x(n)$ 的周期延拓序列，而 $x(n)$ 则是 $\tilde{x}(n)$ 的一个周期，即

$$
\color{#E45F59}
\tilde{x}(n) = \sum_{m = -\infty}^{\infty} x(n + mN) \\
x(n) = \tilde{x}(n) \cdot R_N(n)
$$

一般称周期序列 $\tilde{x}(n)$ 中从 $n=0$ 到 $N-1$ 的第一个周期为 $\tilde{x}(n)$ 的主值区间，而主值区间上的序列称为 $\tilde{x}(n)$ 的主值序列。

--> $\tilde{x}(n)$ 是 $x(n)$ 的周期延拓序列，$x(n)$ 是 $\tilde{x}(n)$ 的主值序列

---

当N大于等于序列 $x(n)$ 的长度时，将周期序列 $\tilde{x}(n)$ 用如下形式表示：

$$
\color{#E45F59}{\tilde{x}(n) = x((n))_N}
$$

式中 $x((n))_N$ 表示将序列 $x(n)$ 以 $N$ 为周期进行延拓得到的周期序列，$((n))_N$ 表示模 $N$ 对 $n$ 求余，即如果 $n = NM + n_1, 0 \leq n_1 \leq N-1$, M为整数，则有 $x((n))_N = x(n_1)$。

---

如果 $x(n)$ 的长度为M，且 的离散傅里叶级数表示式, 且 $\tilde{x}(n) = x((n))_N, N \geq M$, 则有 $\tilde{x}(n)$ 的离散傅里叶级数表示式

$$
\color{#E45F59}
\tilde{X}(k) = \sum_{n = 0}^{N - 1} \tilde{x}(n) W_N^{kn} = \sum_{n = 0}^{N - 1} x((n))_N W_N^{kn} = \sum_{n = 0}^{N-1} x(n) W_N^{kn} \\
X(k) = \sum_{n = 0}^{N - 1} x(n) W_N^{kn} \\
$$

$$
\color{#E45F59}
\tilde{x}(n) = \frac{1}{N} \sum_{k = 0}^{N - 1} \tilde{X}(k) W_N^{-kn} = \frac{1}{N} \sum_{k = 0}^{N - 1} X(k) W_N^{-kn} \\
x(n) = \frac{1}{N} \sum_{k = 0}^{N - 1} X(k) W_N^{-kn} \\
$$

可以看出 $X(k) = \tilde{X}(k) R_N(k)$ ，即有限长序列 $x(n)$ 的N点离散傅里叶变换 $X(k)$ 为是 $x(n)$ 的周期延拓序列 $x((n))_N$ 的离散傅里叶级数系数 $\tilde{X}(k)$的**主值序列**

---

周期信号的**傅里叶级数对**

$$
\color{#E45F59}
\tilde{X}(k) = \mathrm{DFS}[\tilde{x}(n)] = \sum_{n = 0}^{N - 1} \tilde{x}(n) W_N^{kn} \\
\tilde{x}(n) = \mathrm{IDFS}[\tilde{X}(k)] = \frac{1}{N} \sum_{k = 0}^{N - 1} \tilde{X}(k) W_N^{-kn} \\
$$

离散傅里叶变换

$$
\color{#E45F59}
X(k) = \mathrm{DFT}[x(n)] = \sum_{n = 0}^{N - 1} x(n) W_N^{kn} \\
x(n) = \mathrm{IDFT}[X(k)] = \frac{1}{N} \sum_{k = 0}^{N - 1} X(k) W_N^{-kn} \\
$$

#### 3.1.4 用MATLAB计算序列的DFT

MATLAB提供了用快速傅里叶变换算法FFT(算法见第4章介绍)计算 DFT的函数fft，其调用格式如下:

```matlab
Xk = fft(xn, N);
```

调用参数xn为被变换的时域序列向量，N是DFT变换区间长度.

当N大于xn的长度时，`fft`函数自动在xn后面补零。函数返回xn的 N 点DFT变换结果向量Xk。

当N小于xn的长度时，`fft`函数计算xn的前面N个元素构成的N长序 列的N点DFT，忽略xn后面的元素。

`Ifft`函数计算IDFT，其调用格式与`fft`函数相同。

Example:【例3.1.2】

```matlab
% 第三章例3.1.2程序ep312.m
% DFT的MATLB计算
xn=[1 1 1 1];           %输入时域序列向量xn=R8(n)
Xk16=fft(xn,16);        %计算xn的16点DFT
Xk32=fft(xn,32);        %计算xn的32点DFT
%以下为绘图部分
k=0:15;wk=2*k/16;       %产生16点DFT对应的采样点频率(关于π归一化值)
subplot(2,2,1);stem(wk,abs(Xk16),'.'); %绘制16点DFT的幅频特性图
title('(a)16点DFT的幅频特性图');xlabel('ω/π');ylabel('幅度')
subplot(2,2,3);stem(wk,angle(Xk16),'.'); %绘制16点DFT的相频特性图
line([0,2],[0,0]);title('(b)16点DFT的相频特性图')
xlabel('ω/π');ylabel('相位');axis([0,2,-3.5,3.5])
k=0:31;wk=2*k/32;       %产生32点DFT对应的采样点频率(关于π归一化值)
subplot(2,2,2);stem(wk,abs(Xk32),'.'); %绘制32点DFT的幅频特性图
title('(c)32点DFT的幅频特性图');xlabel('ω/π');ylabel('幅度')
subplot(2,2,4);stem(wk,angle(Xk32),'.'); %绘制32点DFT的相频特性图
line([0,2],[0,0]);title('(d)32点DFT的相频特性图');
xlabel('ω/π');ylabel('相位');axis([0,2,-3.5,3.5])
```

## 3.2 离散傅里叶变换的性质

### 3.2.1 Linearity

线性性质

$$
\mathrm{DFT}[a_1 x_1(n) + a_2 x_2(n)] = a_1 X_1(k) + a_2 X_2(k)
$$

### 3.2.2 循环移位性

#### 3.2.2.1 序列的循环位移

设 $x(n)$ 为有限长序列，长度为$M$, $M \leq N$ ，则 $x(n)$ 的循环移位定义为

$$
y(n)=x((n+m))_N R_N(n)
$$

上式表明，将 $x(n)$ 以N为周期进行周期延拓得到 $\tilde{x}(n) = x((n))_N$ , 再将 $\tilde{x}(n)$ 向左循环移位m个单位得到序列 $\tilde{x}(n+m)$ ，最后取 $\tilde{x}(n+m)$ 的主值序列则得到序列 $y(n)$ 。

---

$x(n) = (2n+1)\left[u(n)-u(n-4)\right]$

Q:
(1) $h_1(n) = x((n-3))_6 R_6(n)$
(2) $h_2(n) = x((-n))_8 R_8(n)$

A:
(1)
$x(n) = \{\underline{1},3,5,7,0,0\}$

$h_1(n) = \{\underline{7},0,0,1,3,5\}$

(2)
$x(n) = \{\underline{1},3,5,7,0,0\}$

$0,0,0,0,7,5,3,\underline{1},0,0,0,0,7,5,3,1$

$h_2(n) = \{\underline{1},0,0,0,0,7,5,3\}$

#### 3.2.2.2 时域循环移位定理

$$
y(n) = x((n+m))_N R_N(n) \Leftrightarrow Y(k) = \mathrm{DFT}[y(n)] = W_N^{-km} X(k)
$$

其中，$X(k) = \mathrm{DFT}[x(n)]$

#### 3.2.2.3 频域循环移位定理

$$
Y(k) = X((k+l))_N R_N(k) \Leftrightarrow y(n) = \mathrm{IDFT}[Y(k)] = W_N^{ln} x(n)
$$

### 3.2.3 Cyclic convolution

循环卷积定理

#### 3.2.3.1 两个有限长序列的循环卷积

Convolution of two finite-duration signals using the DFT

设序列 $h(n)$ 和 $x(n)$ 的长度分别为 $N$ 和 $M$ 。$h(n)$ 与 $x(n)$ 的L点循环卷积定义为

$$
y_c(n) = \left[ \sum_{m=0}^{L-1} h(m) x((n-m))_N \right] R_N(n) \\
= h(n) \otimes_L x(n)
$$

(L 圆圈的符号打不出来)

$L \geq \max[N, M]$

循环卷积矩阵形式为:

$$
\color{#E45F59}
\begin{bmatrix}
    y(0)_c \\ y(1)_c \\ y(2)_c \\ \vdots \\ y(N-1)_c
\end{bmatrix} =
\begin{bmatrix}
    x(0) & x(L-1) & x(L-2) & \dots & x(1) \\
    x(1) & x(0) & x(L-1) & \dots & x(2) \\
    x(2) & x(1) & x(0) & \dots & x(3) \\
    \vdots & \vdots & \vdots & \ddots & \vdots \\
    x(L-1) & x(L-2) & x(L-3) & \dots & x(0) \\
\end{bmatrix}
\begin{bmatrix}
    h(0) \\ h(1) \\ h(2) \\ \vdots \\ h(L-1)
\end{bmatrix}
$$

---

Example: 计算下面给出的两个长度为4的序列h(n)与x(n)的4点和8点循环
卷积。

$h(n) = \{1, 2, 3, 4 \}$

$x(n) = \{1, 1, 1, 1 \}$

$$
\begin{bmatrix}
    y(0)_c \\ y(1)_c \\ y(2)_c \\ y(3)_c
\end{bmatrix} =
\begin{bmatrix}
    1 & 4 & 3 & 2 \\
    2 & 1 & 4 & 3 \\
    3 & 2 & 1 & 4 \\
    4 & 3 & 2 & 1 \\
\end{bmatrix}
\begin{bmatrix}
    1 \\ 1 \\ 1 \\ 1
\end{bmatrix} =
\begin{bmatrix}
    10 \\ 10 \\ 10 \\ 10
\end{bmatrix}
$$

#### 3.2.3.2 循环卷积定理

有限长序列 $x_1(n)$ 和 $x_2(n)$ 的长度分别为 $N_1$ 和 $N_2$ ，$N=\max[N_1, N_2]$ 和 $x_2(n)$ 的 $N$ 点循环卷积为

$$
x(n) = x_1(n) \otimes_N x_2(n) = \sum_{m=0}^{N-1} x_1(m) x_2((n-m))_N R_N(n)
$$

则 $x(n)$ 的 $N$ 点DFT为

$$
X(k) = \mathrm{DFT}[x(n)] = X_1(k) \cdot X_2(k)
$$

频域循环卷积定理

如果 $x(n) = x_1(n) x_2(n)$ ，则有

$$
\begin{split}
   X(k)
   &= \mathrm{DFT}[x(n)]_N \\
   &= \frac{1}{N} X_1(k) \otimes_N X_2(k) \\
   &= \frac{1}{N} \sum_{m=0}^{N-1} X_1(m) X_2((k-m))_N R_N(k) \\
\end{split}
$$

---

Example:

$x(n) = (2n+1)R_4(n)$

Q:
(1) $h_1(n) = x((n-3))_6 R_6(n)$
(2) $x(n)*h(n)$
(3) $x(n) ⑧ h(n)$

A: 看不清（恼）

### 3.2.4 复共轭序列的DFT

#### 3.2.4.1 有限长共轭对称序列和共轭反对称序列

设 $x^*(n)$ 是 $x(n)$ 的复共轭序列，长度为N， $X(k)=\mathrm{DFT}[x(n)]_N$ ，

则DFT[ x * (n)] N = X * ( N − k ) , 且X(N)=X(0)

用同样的方法可以证明

$$
NMSL
$$

### 3.2.5 DFT的共轭对称性

有限长序列共轭对称序列是关于 $n=\frac{N}{2}$ 点对称

---

复共轭序列 $x^*(n)$ 的DFT为

$$
\color{#E45F59}
\mathrm{DFT}[x^*(n)]_N = X^*(N-k) \\
$$

$$
X_1(k) =
\begin{cases}
    x^*(0) & k = 0 \\
    X^*(N-k) k = 1 \dots N-1 \\
\end{cases} \\
? \to X((\frac{N}{2}+k))_N R_N(k) \\
$$

prove:

$$
W_N^* = e^{j\frac{2\pi}{N}k} = W_N^{-1} \\
\mathrm{DFT}[x^*(n)]_N = \sum_{n=0}^{N-1} x^*(n) W_N^{kn} \\
= [\sum_{n=0}^{N-1} x(n) W_N^{-kn}]^* \\
\xcancel{= [X(-k)]^* = X^*(N-k)} \\
$$

---

复共轭序列 $x^*(n)$ 的IDFT为

$$
\color{#E45F59}
\mathrm{IDFT}[x^*(n)]_N = x^*(N-n)
$$

---

#### 3.2.5.2 DFT的共轭对称性

$$
X(k) = X_{ep}(k) + X_{op}(k) \\
X_{ep}(k) = \frac{1}{2} [X(k) + X^*(N-k)] \\
X_{op}(k) = \frac{1}{2} [X(k) - X^*(N-k)] \\
$$

and

$$
\color{#E45F59}
\mathrm{DFT}[x_{ep}(n)] = \frac{1}{2}\mathrm{DFT}[x(n) + x^*(N-n)] \\
= \frac{1}{2} [X(k) + X^*(k)] = \Re[X(k)] \\
\mathrm{DFT}[x_{op}(n)] = \frac{1}{2}\mathrm{DFT}[x(n) - x^*(N-n)] \\
= \frac{1}{2} [X(k) - X^*(k)] = j \Im[X(k)] \\
$$

---

设 $x(n)$ 是长度为N的实序列，且 $X(k)=DFT[x(n)]_N$ ，则 $X(k)$ 满足如下对称性：

(1) X(k)共轭对称，即

$\color{#E45F59}X(k) = X^*(N-k)$

(2) 如果 $x(n)$ 是偶对称序列，即 $x(n)=x(N－n)$，则 $X(k)$ 实偶对称，即

$\color{#E45F59}X(k) = X(N-k)$

(3) 如果是奇对称序列，即 $x(n)=－x(N－n)$，则 $X(k)$ 纯虚奇对称，即

$\color{#E45F59}X(k) = -X(N-k)$

实际中经常需要对实序列进行DFT，利用上述对称性质，可减少DFT的运算量，提高运算效率。

Example:

$$
x(n) \text{8点} \text{为实序列} \\
\because X(0) = 1, X(1) = -1+2j, X(2) = 3-2j, X(3) = 2, X(4)=3 \\
\to X(7) = X^*(8-7) = -1-2j \\
X(6) = X^*(8-6) = 3+2j \\
X(5) = X^*(8-5) = 2 \\
x(n) \text{9点} \text{为实序列} \\
\to X(9) = X^*(9-8) = -1-2j \\
X(8) = \dots
X(5) = X^*(4) = 3
$$

Example:【例3.2.2】 利用DFT的共轭对称性，设计一种高效算法，通过计算一个N点DFT，就可以计算出两个实序列 $x_1(n)$ 和 $x_2(n)$ 的N点DFT。 --> PDF P56

## 3.3 频率域采样

**DFT与Z变换**的关系

表明序列 $x(n)$ 的N点DFT是 $x(n)$ 的Z变换在单位圆上的N点等间隔采样。

**DFT与傅里叶变换**的关系

说明 $X(k)$ 为 $x(n)$ 的傅里叶变换 $X(e^{j\omega})$ 在区间 $[0, 2\pi]$ 上的N点等间隔采样。

$$
\frac{1}{N} \sum_{k=0}^{N-1} W_N^{k(m-n)}
= \begin{cases}
    1 & m = n+iN \\
    0 & m \neq n+iN\\
\end{cases}
$$

---

**频域采样定理**：如果序列 $x(n)$ 的长度为 $M$，则只有当频域采样点数 $\color{#E45F59}N \geq M$ 时，才有

$$
x_N(n)= \text{IDFT}[X(k)] = x(n)
$$

即可由频域采样 $X(k)$ 恢复原序列 $x(n)$，否则产生**时域混叠现象**。

---

内插公式

$$
X(e^{j\omega}) = \sum_{k=0}^{N-1} X(k) \varphi(\omega - \frac{2\pi}{N}k) \\
\varphi(\omega) = \frac{1}{N} \frac{\sin(\frac{\omega N}{2})}{\sin(\frac{\omega}{2})} e^{-j\frac{\omega(N-1)}{2}} \\
$$

Example:【例3.3.1】 长度为26的三角形序列 $x(n)$ 如图3.3.1(a)所示。编写MATLAB程序验证频域采样定理

解题思想：$X(e^{j\omega})$ 在 ... -> HEIF

先计算x(n)的32点DFT，得到其频谱函数$X(e^{j\omega})$在频率区间［0，2π］ 上等间隔32点采样X32 (k)，再对X32 (k)隔点抽取，得到$X(e^{j\omega})$在频率区间［0，2π］ 上等 间隔16点采样X16 (k)。最后分别对X16 (k)和X32 (k)求IDFT, 得到：

MATLAB求解程序ep331.m

```matlab
M=26; N=32; n=1:M;
xa=0:M/2; xb=ceil(M/2)-1:-1:0; xn=[xa, xb]; %产生M长三角波序列x(n)
Xk=fft(xn, 512); %512点FFT［x(n) 
X32k=fft(xn, 32); %32点FFT［x(n) 
x32n=ifft(X32k); %32点IFFT［X32(k)］得到x32(n)
X16k=X32k(1:2:N); %隔点抽取X32k得到X16(k)
x16n=ifft(X16k, N/2); %16点IFFT［X16(k)］得到x16(n)
% 以下绘图部分省略
```

## 3.4 DFT的应用举例

### 3.4.1 用 DFT 计算线性卷积

```matlab
? = ifft[[fft(xn, L) * fft(hn, L)], L]
```

假设h(n)和x(n)都是有限长序列，长度分别是N和M。它们的线性卷积和循环卷积分别表示如下：

$$
y_c(n) = \sum_{m=0}^{L-1} h(m) x((n-m))_L R_L(n) \\
$$

$$
H(k) = \mathrm{DFT}[h(n)]_L \\
X(k) = \mathrm{DFT}[x(n)]_L \\
$$

则由DFT的时域循环卷积定理有

$$
Y_c(k) = \mathrm{DFT}[y_c(n)]_L = H(k) X(k) \\
$$

> 教师：**你们去看智慧树罢**

### 3.4.2 用DFT对信号进行谱分析

#### 3.4.2.1 用 DFT 对连续信号进行谱分析

设 $x_a(t)$ 为连续时间信号，持续时间为 $T_p$, 最高频率为 $f_c$。

$x_a(t)$ 的傅里叶变换为 $X_a(j\Omega)$，对 $x_a(t)$ 进行时域采样得到 $x(n) = x_a(nT)$，$x(n)$ 的傅里叶变换为 $X(e^{j\omega})$。

由假设条件可知 $x(n)$ 的长度为

$$
N = \frac{T_p}{T} = T_p F_s
$$

式中，T为采样间隔，Fs =1/T为采样频率。用X(k)表示x(n)的N点DFT。

---

$$
N = \frac{T_p}{T}
$$

$$
F = \frac{1}{T_p}
$$

$$
f_s \geq 2f_c
$$

$$
T = \frac{1}{f_s}
$$

---

在对连续信号进行谱分析时，主要关心两个问题，这就是谱分析范围和 频率分辨率。

谱分析范围为［0, Fs /2］，直接受采样频率 $F_s$ 的限制。为了不产生频率混叠失真，通常要求信号的最高频率 $f_c < F_s/2$。

频率分辨率用频率采样间隔F描述，F表示谱分析中能够分辨的两个频谱 分量的最小间隔。显然，F越小，谱分析就越接近Xa (jf)，所以F较小时，我们 称频率分辨率较高。

---

tags: [#考试要考]

> 教师：很重要啊

Example: [例 3.4.2] 对实信号进行谱分析，要求谱分辨率F≤10 Hz，信号最高频率fc =2.5 kHz，试确定最小记录时间 $T_{p min}$ ，最大的采样间隔 Tmax ，最少的采样点数Nmin 。如果fc 不变，要求谱分辨率提高1倍，最少的采样点数N和最小记录时间应为多少？

解：

1

$$
T_{pmin} = \frac{1}{F} = 0.1s
$$

2

$$
f_s = 2f_c = 2 \times 2500 = 5000Hz \\
T_{max} = \frac{1}{2f_s} = 2 \times 10^{-4}s
$$

3

$$
N_{min} = \frac{T_p}{T} = \frac{0.1}{2 \times 10^{-4}} = 500
$$

4

$$
F \leq 5Hz \\
T_{pmin} = \frac{1}{F} = 0.2s \\
N = \frac{2f_c}{F} = \frac{2 \times 2500}{5} = 1000
$$

#### 3.4.2.2 用 DFT 对序列进行谱分析

对周期为 $N$ 的周期序列 $\tilde{x}(n)$ 进行DFT，其频谱函数为

$$
X(e^{j\omega}) = X(z)|_{z=e^{j\omega}}
$$

频谱分辨率就是采样间隔 $2\pi/N$。因此序列的傅里叶变换可利用 DFT(即FFT)来计算。

---

如果截取长度M等于 $\tilde{x}(n)$ 的整数个周期，即M=mN，m为正整数，即

$$
x_M(n) = \tilde{x}(n) \cdot R_M(n)
$$

$$
\begin{align*}
    X_M(k)
    &= \mathrm{DFT}[x_M(n)] \\
    &= \xcancel{\sum_{n=0}^{M-1} x_M(n) W_M^{kn}} \\
    &= X(\frac{k}{m}) \sum_{i = 0}^{m-1} \exp(-j \frac{2\pi}{m} ik) \\
    &= \begin{cases}
        mX(\frac{k}{m}) \\
        0 \\
    \end{cases}
\end{align*}
$$

就其实啊，系 $k \to \frac{k}{m}$

---

$$
x(n) = \cos(\frac{\pi}{10}n) + \cos(\frac{2\pi}{5}n) \\
$$

谱线 -》 k = 1,4

$\omega = \frac{2\pi}{20} = \frac{\pi}{10}$

$\omega = \frac{8\pi}{20} = \frac{2\pi}{5}$

指出啊，这个 $\omega = \frac{2\pi}{N}$

#### 3.4.2.3 用DFT进行谱分析的误差问题

(1) 混叠现象

---

(2) 栅栏效应

---

对有限长序列， 可以在原序列尾部补零；

---

(3) 截断效应

$w(n)=R_N(n)$, 称为矩形窗函数。根据傅里叶变换的频域卷积定理

由上述可见，截断后序列的频谱 $Y(e^{j\omega})$ 与原序列频谱 $X(e^{j\omega})$ 必然有差别，这种差别对谱分析的影响主要表现在如下两个方面：

1. **泄露**。原来序列 $x(n)$ 的频谱是离散谱线，经截断后，使原来的离散谱线向附近展宽，通常称这种展宽为泄露。显然，泄露使频谱变模糊，使谱分辦率降低。

2. **谱间干扰**。在主谱线两边形成很多旁瓣，引起不同频率分量间的干扰（简称谱间干扰），特别是强信号谱的旁瓣可能湮没弱信号的主谱线，或者把强信号谱的旁瓣误认为是另一频率的信号的谱线，从而造成假信号，这样就会使谱分析产生较大偏差。
由于上述两种影响是由对信号截断引起的，因此称之截断效应。
增加N可使 $W_g(\omega)$ 的主瓣变窄，减小泄露，提高频率分辨率，但旁瓣的相对幅度并不减小。

#### 3.4.2.4 频率分辨率

分辨率问题是信号处理中的基本问题，包括频率分辨率和时间分辨率。

* 频率分辨率：通过频域窗观察到的频率宽度；
* 时间分辨率：通过时域窗观察到的时间宽度；

目标

* 窗函数的“宽度”越小越好！
* 窗函数的“宽度”能随信号的变化自适应调整
