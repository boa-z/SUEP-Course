# 实验三 差动放大器特性仿真

## 一、实验目的

1. 理解 MOSFET 差动放大器的基本工作原理。
2. 学会使用 LTSPICE 软件进行电路仿真。
3. 观察和分析差动放大器的输入输出特性和增益。

## 二、实验内容

### 1. 电路设计

设计一个基本的 MOSFET 差动放大器电路，主要包括以下组件：

（1）两个匹配的 NMOS 或 PMOS 管作为差动放大器的输入级。
（2）源极共用电流源（ $I_{\text{SS}}$ ）以提高共模抑制比。
（3）负载电阻（ $R_{\text{D1}}$ 和 $R_{\text{D2}}$ ）用于输出。
（4）偏置电路以确保 MOSFET 工作在正确的区域。

### 2. 电路仿真

在 LTSPICE 中绘制上述差动放大器电路图，进行以下仿真：

1. 直流分析（DC Analysis）：确定工作点（Q 点）。
2. 交流分析（AC Analysis）：测量增益。
3. 瞬态分析（Transient Analysis）：观察输入信号和输出信号的波形。

### 3. 数据收集与分析

（1）记录输入电压、输出电压、增益值、以及共模和差模输入下的输出响应。
（2）绘制增益特性曲线。

## 三、实验步骤

(1) 启动 LTSPICE 软件，创建新的电路图。

(2) 根据设计要求添加两个 MOSFET，源极共用电流源，负载电阻及其他必要元件。

![1](images/1-1.png)

(3) 设置元件参数，此处将 NMOS 的型号选择为 `BSB013NE2LXI`，其 Max Vds = 25, Rds = 1.3, Gate Charge = 30

(4) 连接电源，设置输入信号源。

(5) 进行直流扫描分析，选择合适工作点。

通过配置 `.dc` 语句，随后运行仿真，测量 `Id(M1)` 得到以下图表。

```spice
.dc Vin 0 20 2 VDD 0 20 2
;.tran Vin1
```

对于绘制的图像，将图表的横坐标设置为 `Vin1 - V(VGS)`。可以看到 `Id(M1)` 的值最终稳定在 $5 \text{A}$，即为 `Iss` 的一半。

![2](images/1-2.png)

(6) 进行交流分析，测量增益。

```text
SPICE Output Log: C:\Users\Administrator\Documents\LTspice\lab03\Draft1.log
LIspice 24.0.12 for Windows
Circuit: * C: \Users\Administrator\Documents \LTspice\1ab03\Draftl.asc
Start Time: Fri Nov 1 16:23:25 2024
solver = Normal
Maximum thread count: 16
tnom = 27
temp = 27
method = modified trap
Direct Newton iteration for .op point succeeded.
vi: PP(v(n004, n005)) = 0.0457916 FROM 0 TO 1
vo: PP(v(n002, n003)) = 0.148394 FROM 0 TO 1

Total elapsed time: 0.255 seconds.
```

![2](images/2.png)

根据输出日志的信息，测量了输入和输出信号的峰峰值（Peak-to-Peak）电压。增益可以通过输出电压与输入电压的比值来计算。

1. **定义峰峰值电压**：
   - 输入电压峰峰值 $V_{in_{pp}}$ = 0.0457916 V
   - 输出电压峰峰值 $V_{out_{pp}}$ = 0.148394 V

2. **增益公式**：
   交流电压增益 $A_v$ 可以通过以下公式计算：$A_v = \frac{V_{out_{pp}}}{V_{in_{pp}}}$

3. **增益计算**：
   将数值代入公式：$A_v = \frac{0.148394}{0.0457916} \approx 3.24$

交流增益 $A_v \approx 3.24$。这意味着输出电压大约是输入电压的3.24倍，表明该电路具有放大作用。

(7) 进行瞬态分析，观察输入输出波形。

按图连接电路，将 `Vin1` 设置为 `SINE(5 30m 50)`, `Vin2` 设置为 `SINE(5 30m 50 0 0 45)`, `VDD` 设置为 `10V`。

通过配置 `.meas` 语句，测量输入输出波形。

```spice
.meas vi pp V(n004,n005)
.meas vo pp V(n002,n003)
```

测量命令 .meas：

`.meas vi pp V(n004,n005)` 用于测量输入的峰峰值电压。
`.meas vo pp V(n002,n003)` 用于测量输出的峰峰值电压。

![3](images/3.png)

从波形图中可以观察到，输出波形的幅度比输入波形要大，这表明该电路具有一定的放大作用。

(8) 完成数据记录与计算。

## 四、实验注意事项

1. 确保 MOSFET 的型号和参数正确，以模拟实际电路的行为。
2. 仔细检查电路连接，避免因接线错误导致的仿真失败。
3. 在进行交流分析前，先进行直流分析，确保电路处于正常工作状态。

## 五、实验报告

请将实验过程、仿真结果、图表及分析总结整理成实验报告，报告应包含：

（一）实验目的与内容
（二）电路设计图及元件参数
（三）仿真结果与分析
（四）CMRR 计算结果
（五）结论与心得体会
（六）参考文献

## 六、实验时间

1. 实验设计：1 课时
2. LTSpice 模拟：3 课时
3. 数据分析与报告撰写：2 课时
