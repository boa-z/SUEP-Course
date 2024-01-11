# VLSI设计基础_作业

## 第1章作业

### 解释NMOS管的工作原理

Q: 解释NMOS管的工作原理，画出其特性曲线。$V_{DS}$ 变化时各种状态的变化？

A: @bing + 人工

* 截止区：当$V_{GS}$小于阈值电压$V_{TN}$时，NMOS管处于截止状态，沟道区不存在可移动的电子，漏源电流$I_D$为零，输出电压$V_{out}$等于电源电压$V_{DD}$。
* 线性区：当$V_{GS}$大于$V_{TN}$且$V_{DS}$小于$V_{GS}-V_{TN}$时，NMOS管处于线性区，沟道区形成一个近似平行于衬底表面的长方体，其电阻随着$V_{DS}$的增加而减小，漏源电流$I_D$与$V_{DS}$成正比，输出电压$V_{out}$随着$I_D$的增加而减小。
* 饱和区：当$V_{GS}$大于$V_{TN}$且$V_{DS}$大于等于$V_{GS}-V_{TN}$时，NMOS管处于饱和区，沟道区形成一个楔形体，其最薄处位于漏端，称为沟道夹断点。此时，漏源电流$I_D$与$V_{DS}$无关，只取决于$V_{GS}$和器件参数，输出电压$V_{out}$保持在一个较低的恒定值。

## 第2章作业

### 教材P65 Q7

Q: 7 根据逻辑 $f=\overline{A+B[C \cdot D+E(F+G)]}$ 设计CMOS组合逻辑门。如果等效倒相器的NMOS管长宽比为1，PMOS管长宽比为2，试计算组合逻辑门的各MOS管长宽比。

A: 评价是还得看India小教程

## 第4章作业

### 第四章作业1

2023-11-29

Q: 例题：设计一个实现四种逻辑操作的电路， 其中控制信号为K_1 K_0, 逻辑输入为AB.

当K_1 K_0 = 00时，实现A、B的AND操作；
当K_1 K_0 = 01时，实现A、B的OR操作；
当K_1 K_0 = 10时，实现A、B的XOR操作；
当K_1 K_0 = 11时，实现B的倒相操作；

A:

写出电路实现的逻辑函数

#### 方案1 MUX+ROM

利用MUX+ROM设计一个实现四种逻辑操作的电路， 其中控制信号为K_1 K_0, 逻辑输入为AB.

当K_1 K_0 = 00时，实现A、B的AND操作；
当K_1 K_0 = 01时，实现A、B的OR操作；
当K_1 K_0 = 10时，实现A、B的XOR操作；
当K_1 K_0 = 11时，实现B的倒相操作；

C_3-0 表示的是AB的四种逻辑操作

K_1 K_0 = 00, C_3 C_2 C_1 C_0 = 1000, A AND B
K_1 K_0 = 01, C_3 C_2 C_1 C_0 = 1110, A OR B
K_1 K_0 = 10, C_3 C_2 C_1 C_0 = 0110, A XOR B
K_1 K_0 = 11, C_3 C_2 C_1 C_0 = 0011, B

#### 方案2 NOR-NOR PLA

$$
\begin{align*}
    Z
    &= \overline{K_1} \overline{K_0} AB + \overline{K_1} K_0 (A + B) + K_1 \overline{K_0} (A \oplus B) + K_1 K_0 \overline{B} \\
    &= \overline{K_1} \overline{K_0} AB + \overline{K_1} K_0 (A + B) + K_1 \overline{K_0} (A \overline{B} + \overline{A} B) + K_1 K_0 \overline{B} \\
    &= \overline{K_1} \overline{K_0} AB + \overline{K_1} K_0 (A + B) + K_1 \overline{K_0} A \overline{B} + K_1 \overline{K_0} \overline{A} B + K_1 K_0 \overline{B} \\
    &= \overline{K_1} \overline{K_0} AB \\
    &+ \overline{K_1} K_0 A \\
    &+ \overline{K_1} K_0 B \\
    &+ K_1 \overline{K_0} \overline{A} B \\
    &+ K_1 \overline{K_0} A \overline{B} \\
    &+ K_1 K_0 \overline{B} \\
\end{align*}
$$

### 第四章作业2

用**与非－与非**结构的 PLA 实现逻辑 $Z = \overline{a} \cdot b \cdot d + \overline{b} \cdot c \cdot \overline{d} + a \cdot \overline{c} \cdot d$

NAND-NAND PLA

### 第四章作业3

用**或非－或非**结构的 PLA 实现逻辑 $Z = \overline{a} \cdot b \cdot d + \overline{b} \cdot c \cdot \overline{d} + a \cdot \overline{c} \cdot d$

NOR-NOR PLA

### 第四章作业4

用P62图4－19的门阵列单元实现一个与非门加一个倒相器形成的与门
