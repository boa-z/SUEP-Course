# 4 FFT

快速傅里叶变换

[radix-2 fast fourier transform](https://www.phys.uconn.edu/~rozman/Courses/m3511_19s/downloads/radix2fft.pdf)

[第六章 快速傅里叶变换FFT](http://fdjpkc.fudan.edu.cn/_upload/article/83/cb/c12faf5a42dc8826b50ca3629c80/db78a883-3e68-49ac-8852-6df341afd700.pdf)

## 4.2 Radix-2 FFT

基2FFT算法

### 4.2.2 时域抽取法基2FFT基本原理

设序列 $x(n)$ 的长度为 $N$ ，且满足 $N=2^M$ ，$M$ 为自然数。按 $n$ 的奇偶把 $x(n)$ 分解为两个N/2点的子序列

$$
x_1(r) = x(2r), r = 0, 1, \cdots, N/2-1 \\
x_2(r) = x(2r+1), r = 0, 1, \cdots, N/2-1
$$

则x(n)的DFT为

$$
\begin{align*}
X(k)
&= \sum_{n=0}^{N-1} x(n) W_N^{kn} \\
&= \sum_{r=0}^{N/2-1} x_1(r) W_N^{k(2r)} + \sum_{r=0}^{N/2-1} x_2(r) W_N^{k(2r+1)} \\
\end{align*}
$$

$$
\because W_N^{2kr} = \exp\left(-j\frac{2\pi}{N}2kr\right) = W_{N/2}^{kr} \\
\therefore X(k) = X_1(k) + W_N^k X_2(k)
$$

由于 $X_1(k)$ 和 $X_2(k)$ 均以 $N/2$ 为周期，且 $W_N^{k+N/2} = -W_N^k$ ，故

$$
\color{#E45F59}
\begin{align*}
    X(k) = X_1(k) + W_N^k X_2(k) \\
    X(k+N/2) = X_1(k) - W_N^k X_2(k)
\end{align*}
$$

这样，就将N点DFT分解为两个N/2点DFT和上面两个式子的运算。

-> **蝶形运算**

![图4.2.2 8点DFT一次时域抽取分解运算流图](https://img-blog.csdnimg.cn/20190527123145504.png)

这样，经过第二次分解，又将N/2点DFT分解为2个 N 点DFT和N/4个蝶形运算，如此重复下去，直到分解为N个1点DFT和M级蝶形运算为止。用到关系式子 $W_{N/m}^k = W_N^{mk}$ .

![图4.2.3 图4.2.4 DFT点二次时域抽取分解运算流图](https://img-blog.csdnimg.cn/20190527125217466.png)

按图4.2.2计算N点DFT时，总共需要的**复数乘法次数**为

$$
2\left(\frac{N}{2}\right)^2 + \frac{N}{2} \approx \frac{N^2}{2}
$$

**复数加法次数**为

$$
N\left(\frac{N}{2} - 1\right) + \frac{2N}{2} \approx \frac{N^2}{2}
$$

### 4.2.3 DIT-FFT算法与直接计算DFT运算量的比较

请解释下面文本中的公式：

由DIT-FFT算法的分解过程及图4.2.4可见，N=2M 时，其运算流图应有M级蝶形，每一级都由N/2个蝶形运算构成。因此，每一级运算都需要N/2次复数乘和N次复数加(每个蝶形需要两次复数加法)。所以，M级运算总共需要的**复数乘次数**为

$$
C_M = \frac{N}{2} \cdot M = \frac{N}{2} lb N
$$

**复数加次数**为

$$
C_A = N \cdot M = N lb N
$$

lb: log_2 N

![图4.2.5 DIT-FFT算法与直接计算DFT所需复数 乘法次数的比较曲线](https://images0.cnblogs.com/blog/278549/201307/27110416-272bbf03d71a4ae1983779e66c544866.jpg)

### 4.2.4 DIT-FFT的运算规律及编程思想

#### 4.2.4.1 原位运算

DIT-FFT的运算过程很有规律。N=2M 点的FFT共进行M级运算，每级由 N/2个蝶形运算组成。
同一级中，每个蝶形的两个输入数据只对计算本蝶形有用，这就意味着计算完一个蝶形后，所得输出数据可立即存入原输入数据所占用的存储单元 (数组元素)。
经过M级运算后，原来存放输入序列数据的N个存储单元(数组A)中便依次存放X(k)的N个值。
这种利用同一存储单元存储蝶形计算输入、输出数据的方法称为原位(址) 计算。 原位计算可节省大量内存，从而使设备成本降低。

#### 4.2.4.2 旋转因子的变化规律

N点DIT-FFT运算流图中，每级都有N/2个蝶形。

每个蝶形都要乘以因子 $W_N^p$ ，称其为旋转因子，p为旋转因子的指数。但各级的旋转因子和循环方式都有所不同。

为了编写计算程序，应先找出旋转因子 $W_N^p$ 与运算级数的关系。用 L 表示从左到右的运算级数(L=1，2，…，M)。观察图4.2.4不难发现，第 L 级共有 2L-1 个不同的旋转因子。

对 $N=2^M$ 的一般情况，第 L 级的旋转因子为

$$
W_N^p = W_{2^M}^p = W_{2^{M-L}}^{2^{L-1}p} = W_{N/2^L}^{2^{L-1}p}
$$

#### 4.2.4.3 蝶形运算规律

Example: 在DIT-FFT算法推导中，若序列长度为1028，用蝶形运算需要**11**次分解。

#### 4.2.4.4 编程思想及程序框图

![图4.2.6 DIT-FFT运算和程序框图](https://img2023.cnblogs.com/blog/3004506/202302/3004506-20230208191847866-562477502.png)

具有相同的旋转因子的蝶形运算单元间隔为 $2^L$  同一个蝶形运算两个元素间隔为 $2^{L-1}$

### 4.2.5 频域抽取法FFT(DIF-FFT)

$$
X(k) = \sum_{r=0}^{N/2-1} \left[ x(n) + \dots \right] W_N^{kn}
$$

![图4.2.13 DIF-FFT运算流图（N=8）](https://i.loli.net/2020/12/08/YqMEDPbTJ57WjA1.png)

DIT-FFT和DIF-FFT算法的区别。

1. 蝶形运算的组成不同
   * DIT—FFT：旋转因子乘在蝶形运算的输入端
   * DIF—FFT：旋转因子乘在蝶形运算的输出端
2. 输入输出的顺序不同
   * DIT—FFT：输入倒序，输出顺序
   * DIF—FFT：输入顺序，输出倒序

Example: 多选题: 在FFT算法中，以下说法正确的是（）。

A. DIT-FFT输入正序
B. DIT-FFT输入倒序
C. DIF-FFT输入正序
D. DIF-FFT输入倒序

### 4.2.6 IDFT的高效算法

Example: HEIC
