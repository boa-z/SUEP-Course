# Final Exam

## 绪论

集成电路的发展阶段：小规模/中规模/大规模/超大规模集成电路/...

## 第1章

题型：填空/判断

---

基于分层分级的思想，一般采用自顶向下（top-down）的设计过程
主要分以下阶段：

1. 功能设计：根据设计要求进行功能划分，进行RTL级描述
2. RTL级模拟与验证：检验功能的正确性
3. 逻辑综合：生成逻辑网表
4. 逻辑模拟与验证：检验综合的结果
5. 版图生成、检查与验证：用综合的结果根据逻辑与电路及工艺要求，生成光刻用的掩膜版图
6. 提交版图数据，流片

简化设计过程

1. 验证电路逻辑（Verifying the Circuitry Logic）
2. 编译网表（Compiling a Netlist）
3. 版图设计过程（ Layout Process ）
   1. 平面布局（ FloorPlanning ）
   2. 布置 （ Placement ）
   3. 布线 （ Routing ）
   4. 验证（ Verification）

GDSII 文件：布线数据+单元布置数据+晶体管级版图

## 第2章

双极型 ...

自对准工艺 ...

---

将两次MASK步骤合为一次。让D，S和G三个区域一次成形。这种方法被称为**自对准技术**。
**自对准** 是一种在圆晶片上 **用单个掩模形成不同区域的多层结构的技术**，它 **消除了用多片掩模所引起的对准误差**。在电路尺寸缩小时，这种有利的方法用得越来越多。

IMAGE @PPT P30

上图中可见形成了图形的多晶硅条用作离子注入工序中的掩模，用自己的“身体”挡住离子向栅极下结构（氧化层和半导体）的注入，同时使离子对半导体的注入正好发生在它的两侧，从而实现了自对准。
而且原来呈绝缘的多晶硅本身在大量注入后变成 **低电阻率的导电体**。用作栅电极和栅电极引线
可见多晶硅的应用实现“**一箭三雕**”之功效。

## 第3章

本章后进入重点内容

关注 PPT 中红字标注内容

---

阱是**CMOS集成电路制造过程中制备的第一层**。
**衬底或阱**有时也被称为**MOS管的“体”**，在“体”上制作MOS管的CMOS工艺通常被称为“**体CMOS工艺**”。

通常在晶片上会生长外延层，如图所示。注意到，图中N阱和P衬底构成了一个二极管。在CMOS电路中，**衬底**通常与**电路中的电压最低点相连（接地）**，N阱通常与电路中电压最高点相连（电源）以避免该二极管正偏。**在理想情况下，我们认为从衬底中流过的电流为零**。

**N阱的最小尺寸**一般是**由光刻胶进行图形制作的水平**来决定的，而**间距尺寸**由**寄生NPN晶体管**来决定。

N阱分布式RC延迟

到B节点的延迟时间为到A节点的延迟时间和通过2Rsquare的电阻对B节点处电容进行充电带来的延迟时间之和，即：

$t_{dB} = 0.7 (R_{square}C_{square} + 2R_{square}C_{square})$

## 第4章

采用铜互连工艺而非铝互连工艺？

连接焊盘

计算 ... ?

---

铜的电阻率比铝小，Cu:1.7微欧姆/厘米；Al：3微欧姆/厘米，在相同的线长下，铜互联的寄生电阻小，在相同的输运电流下，铜线可以更细，寄生电容更小。 因此铜互联线的延迟小（RC），适合高速应用；铜互连的串扰小（耦合小）
铜的抗电迁移率比铝小，其电迁移阀值电流为铝的10倍，相同线宽能承受更大的电流。

焊盘的尺寸是版图设计中唯一不随工艺尺寸的缩小而按比例缩小的单元。

管芯的最顶端的绝缘层又被称为钝化层。

---

试估算一个10×10方块的metal1和同样大小的metal2之间的电容，其中metal2恰好放置在metal1的正上方，比例因子为50nm。当metal2的电位从0变化到1V，计算metal1上的电压变化。

由前表可知，metal1 和 metal2 之间的平板电容的典型值为 35aF/um2,边缘电容的典型值为 100aF/um2，则

$$
C_{12} = 100 \times (0.05)^2 * 35 + 40 \times 0.05 \times 100 = 209 aF
$$

而 metal1 到衬底的电容值为

$$
C_{1sub} = 100 \times (0.05)^2 \times 23 + 40 \times 0.05 \times 79 = 164 aF
$$

则 $C_{1sub}$ 上的电压为

$$
\Delta V_{metal1} = \Delta V_{metal2} \times \frac{\frac{1}{j w C_{1 sub}}}{\frac{1}{j w C_{1 sub}} + \frac{1}{j w C_{12}}} \\
= 2 \times \frac{C_{12}}{C_{1sub} + C_{12}} = \frac{209}{209 + 164} = 0.56 V
$$

---

直流电流通过导体时，金属中产生的质量输运现象称为**金属化电迁移**，即金属中的离子迁移。
所谓金属电迁移失效，通常是指金属层因金属离子的迁移在局部区域由质量堆积而出现小丘，或由质量亏损出现空洞而造成的器件或互连性能退化或失效。

* 通常在高温、强电场下引起。
* 电流密度能够保持低于金属迁移阈值电流密度J，电迁移就不会发生。

## 第5章

有源区 / 场区 的概念

...

静电保护原理图

天线效应

---

场区，即生长场氧化（field oxide,FOX）的区域。

有源层（active）定义的是覆盖在衬底上场氧的开口。

图i中的n-select是一个导出掩模。它通过将N+层尺寸放大出来。考虑到误对准的存在，n-select掩模必须比active掩模要大。

通过**接触层（contact）**将金属与有源层或多晶硅相连。

5.3 ESD 静电保护

上图中，如果加在焊盘的信号位于地和VDD之间，两个二极管都不会导通。但是，如果焊盘上的电压开始增加到VDD+0.5V，或者减小到-0.5V以下，那么其中的一个二极管就会导通，并提供一个低阻抗的“钳子”，使得栅氧上的电压不至于太高。

---

暴露的金属线或者多晶硅(polysilicon)等导体，就象是一根根天线，会收集电荷（如等离子刻蚀产生的带电粒子）导致电位升高。天线越长，收集的电荷也就越多，电压就越高。若这片导体碰巧只接了 MOS 的栅，那么高电压就可能把薄栅氧化层击穿，使电路失效，这种现象称之为“**天线效应**”。

---

由前面分析的天线效应的产生机理可以得到

天线效应的**消除**机理：**减小暴露的导体面积或加入其它电荷泄放回路**。一般在集成电路版图设计中，消除天线效应的方法有两种：**跳线法、添加反偏二极管**。

* 跳线法通过改变金属布线的层次来解决天线效应，但是同时增加了通孔，由于通孔的电阻很大，会直接影响到芯片的时序和串扰问题，所以在使用此方法时要严格控制布线层次变化和通孔的数量。
* 添加天线器件，给“天线”**加上反偏二极管**。如图所示，通过给直接连接到栅的存在天线效应的金属层接上反偏二极管，形成一个电荷泄放回路，累积电荷就对栅氧构不成威胁，从而消除了天线效应。

## 第6章

### 6.3 设计高精度电阻方法

简化版

* 单位电阻：如果要在较大的温度范围内精确设计电路，常用到比例电路。通常须绘制具有归一化阻值的单位电阻。
* 保护环：在相邻电路间减小衬底噪声的最简单的方法就是在两部分电路之间P+注入(对于P衬底晶圆而言)。形成的衬底接触将去除注入载流子，并能理想的使衬底电位保持在固定的值(地电位)。下图展示了一个电阻的基本画法，由于P+注入画成环形，通常称为保护环(Guard Ring)
* 叉指版图：改善两个不同电阻之间的匹配。工艺上的差异(不同位置处N阱、N+、P+掺杂不同)在这两个电阻中的分配更均匀。
* 共质心版图：具有相同中心的版图，即共质心版图能改善电阻之间的匹配特性
* 陪元件：在两个或多个元件之间改善匹配性能。陪元件没有任何电学意义，它只是为了保证匹配电阻的单位电阻两侧具有相同的结构。通常将它们接地或接电源，而非悬空。

### 6.4 电阻值公式推导

$$
R = \frac{L_b + \delta L_b}{W_b + \delta W_b} \rho_b + 2 \frac{L_h + \delta L_h}{W_h + \delta W_h} \rho_h + 2 \frac{R_c}{W_c + \delta W_c} + 2 r_s
$$

$R = r_b + 2r_h + 2r_c + 2r_s$

* $R$ = 总电阻
* $r_b$ = 体区部分电阻
* $r_h$ = 头区部分电阻
* $r_c$ = 接触区部分电阻
* $r_s$ = 扩展区部分电阻
* $L$: 长度
* $W$: 宽度
* $\rho$: 薄层电阻率
* $R_c$: 接触电阻因子

注意：所有的德耳塔项对于所使用的工艺都是唯一的，在方程中需要的 $\delta$ 值要查阅制造商的工艺手册。

## 第7章

电容值计算 $C_{total} = C_{area} + C_{periphery}$

什么是横向扩散，什么是氧化入侵（氧化物侵蚀）？

长MOS管和宽MOS管的基本版图形式？

---

电容值计算

边缘电容

$C_{\text{periphery}} = [ 2(l + \delta l) + 2(w + \delta w) ] \times C_2$

总电容 = 平板电容 + 边缘电容
$C_{\text{total}} = C_{\text{area}} + C_{\text{periphery}}$

**横向扩散**
对于源区和漏区进行注入时，注入原子会横向扩散到栅poly下方，则栅的有效长度为：

$$
L_{effective} = L_{draw} - 2 L_{diff}
$$

其中Ldiff为横向扩散的长度,Ldraw 为绘制宽度。为了使横向扩散最小化，通常采用轻掺杂漏（LDD，lighted Doped Drain）

**氧化物侵蚀**
当定义有源区时，active掩模层不能精确绘出场氧FOX的图形，**使氧化层可能侵入有源区，减小有源区开口面积。**
有效的有源区宽度为：Weffective=Wdraw-2Wenc
其中Wdraw为绘制宽度，Wenc为氧化物侵蚀宽度

## 第8章

栅电容随栅源电压(VGS)变化，画图并解释（详见第8章 PPT P7）

MOS管的 IV 特性，公式（详见第8章 PPT P15）

---

（1）堆积
$V_{GS} < 0$，衬底的空穴被吸附至栅氧化层的下方
栅电极与衬底电极之间电容（氧化层电容）：...
栅与源/漏之间的电容（交叠电容）：...
栅与地之间的总电容：$C_{ox} = C_{gs} + C_{gb} + C_{gd} = C_{ox}^{'} L_{drawn} W_{drawn}$

（2）耗尽

下图为 $V_{GS}$ 增大，不能吸引大量空穴到达栅氧下方，同时也不能吸引大量电子的情况。此时栅氧下方的硅表面是耗尽。栅极和衬底之间的电容由氧化层电容和耗尽电容串联而成。

（3）反型

$V_{GS}$ 足够大（$> V_{thn}$），大量的电子被吸引到栅极下方。

---

对于工作在线性区的PMOS管，

$$
I_D = K P_p \frac{W}{L} \left[(V_{SG} - V_{THP})V_{SD} - \frac{V_{SD}^2}{2}\right]
$$

（当 $V_{SG} \leq V_{THP}$ 且 $V_{SD} \leq V_{SG} - V_{THP}$ 时）

工作于饱和区的MOS管

将 $I_D = \frac{K P_n}{2} \frac{W}{L_{elec}} (V_{GS} - V_{th})^2$ 对 $V_{DS}$ 做偏微分，即

$$
\frac{dI_D}{dV_{DS}} = - \frac{K P_n}{2} \frac{W}{L_{elec}^2} (V_{GS} - V_{THN})^2 \frac{d L_{elec}}{d V_{DS}} = I_D \left(\frac{1}{L_{elec}} \frac{d X_{dl}}{d V_{DS}}\right)
$$

通常定义：$\lambda = \frac{1}{L_{elec}} \frac{d X_{dl}}{d V_{DS}}$

$\lambda$ 被称为沟道长度调制系数。考虑到沟道长度调制效应后，对于工作在饱和区的MOS管，其 $I_D$ 的表达式为

$$
I_D = \frac{K P_n}{2} \frac{W}{L_{elec}} (V_{GS} - V_{th})^2 (1 + \lambda (V_{DS} - V_{DS, sat}))
$$

当 $V_{GS} \geq V_{THN}$ 并且 $V_{DS} \geq V_{GS} - V_{THN}$ 时，MOS管工作在饱和区。

---

当VSB增加时，阈值电压随之增加，这一效应被称为 **体效应**。

一般将施加在接近最小沟道长度的MOS管源漏之间的最大电压定义为“**穿通电压**”

耗尽层宽度随着VDS的增大而增大，漏电流也随之增大，此效应被称为**沟道调制（CLM）效应**。

## 第9章

NMOS 饱和区电流方程（详见第9章 PPT P3）

沟道调制参数，图中曲线往上翘的原因？

---

$V_{\text{DS, sat}}$ 称为 **栅过驱动电压**

在饱和区时，MOS管就像一个与电阻并联的电流源，该电阻的阻值为 $r_D = \frac{1}{\lambda I_{\text{DS, sat}}}$

图中曲线往上翘的原因？

在饱和区，MOS管看起来一个与电阻并联的电流源

## 关联实验

绘制棒状图。

---

设计规则 -> DRC 规则文件

[解释报错：drc(GT TO(enc<2) "Poly Overhang out of Active into Field < 2.0")](https://chatgpt.com/share/f87c6fd2-e7be-4ffe-b483-6bc8c8724e08)
