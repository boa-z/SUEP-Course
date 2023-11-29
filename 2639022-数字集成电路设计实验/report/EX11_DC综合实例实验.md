# DC综合实例实验

## 一、实验目的

基于给定的原理图及其说明定义 DC 环境属性
将属性应用于设计
验证应用的属性

## 二、流程

从 Lab3/ib.rpt 文件当中查看负载电容单位
复制`lab3/scripts/MY_DESIGN.con`到`lab4/scripts/MY_DESIGN.con`
将 4-4 表格定义的说明添加到 `MY_DESIGN.con` 当中
验证并修改约束文件语法

* 调用DC

读取`rtl/MY_DESIGN.v`文件
写出约束文件，并与 `solutions/MY_DESIGN.wscr` 对比
退出 DC

## 约束要求

![Figure39](../assets/Figure39%20设计原理图.png)

输入端口

1. 除了`clk`和`cin*`端口外，约束所有的驱动端为库当中的`bufbd1`寄存器
2. `Cin*`端口作为片外输入信号端口，最大转换时间为120ps

输出端口

1. 除了 `cout` 外的所有端口，等同于2倍的`bufbd7` "l"端口的电容值
2. `Cout` 端口的最大驱动电容为25fF

## 细说约束条件

基于`.solution/MY_DESIGN.con`文件

### UNITS

The unit of time in this library is 1ns.
这个库中的时间单位是1ns。

The unit of capacitance in this library is 1pF.
该库中电容的单位是1pF。

### CLEAN UP

```text
reset_design
```

Remove any existing constraints and attributes
删除任何现有的约束和属性

### CLOCK DEFINITION

```text
create_clock -period 3.0 [get_ports clk]
```

A 333Mhz clock is a 3.0ns period.
333Mhz 时钟是 3.0ns 周期。

```text
set_clock_latency -source -max 0.7 [get_clocks clk]
```

External clock source latency is 700ps or 0.7ns
外部时钟源延迟为 700ps 或 0.7ns

latency n. 潜伏；潜在因素

```text
set_clock_uncertainty -setup 0.15 [get_clocks clk]
```

The +/-30ps internal clock delay variation to register clock pins results in a 60ps worst case skew or uncertainty, if you launch late (+30ps) and capture early (-30ps)r; Add 40ps due to jitter and 50ps for setup margin;
This equals 150ps or 0.15 ns of total uncertainty.

如果您延迟启动 (+30ps) 并提前捕获 (-30ps)，则寄存器时钟引脚的 +/-30ps 内部时钟延迟变化会导致 60ps 最坏情况的偏差或不确定性； 添加 40ps 由于抖动和 50ps 用于设置余量；
这相当于 150ps 或 0.15 ns 的总不确定度。

skew n. 斜角，倾斜；（对特定人或对象的）偏见；

```text
set_input_transition 0.12 [get_ports Cin*]
```

Port Cin is a chip level input and has an input transition of 120ps or 0.12 ns
端口 Cin 是芯片级输入，输入转换为 120ps 或 0.12 ns

### INPUT TIMING

```text
set_input_delay -max 0.45 -clock clk [get_ports data*]
```

The maximum "input delay"(External) on ports detal and data2 is:
端口 detal 和 data2 上的最大“输入延迟”（外部）为：
clock period - clock uncertainty - delay of S - register setup time =
3.0 - 0.15 - 2.2 - 0.2 = 0.45 ns

```text
set_input_delay max 0.4 -clock clk [get_ports sel]
```

The latest arrival time at port sel is 1.4ns (absolute time). The total clock insertion delay or latency to the external registers is 700ps + 300ps or 1.0ns. Therefore, the relative input delay on the port is 1.4 -1.0 = 0.4ns
最晚到达sel端口的时间是1.4ns（绝对时间）。 总时钟插入延迟或外部寄存器的延迟为 700ps + 300ps 或 1.0ns。 因此，端口上的相对输入延迟为 1.4 -1.0 = 0.4ns

### OUTPUT TIMING

```text
set_output_delay -max 0.5 -clock clk [get_ports out1]
```

The output delay at port out1 is 420ps + 80ps = 500ps or 0.5ns

```text
set_output_delay -max 2.04 -clock clk [get_ports out2]
```

The internal delay to out2 is 0.81ns. The external capturing clock edge happens 3ns after the launch edge, minus the uncertainty of 0.15ns, or 2.85ns after launch. To constrain the internal delay to 0.81ns the output delay must therefore be constrained to 2.85ns - 0.81ns = 2.04ns.
out2 的内部延迟为 0.81ns。 外部捕获时钟沿发生在启动沿后 3ns，减去 0.15ns 的不确定性，即启动后 2.85ns。 为了将内部延迟限制为 0.81ns，输出延迟必须限制为 2.85ns - 0.81ns = 2.04ns。

```text
set_output_delay max 0.4 -clock clk [get_ports out3]
```

The setup time requirement on port3 is 400ps or 0.4ns with respect to the capturing register's clock.
This is, by definition, the "set_output_delay" value.
相对于捕获寄存器的时钟，端口 3 上的建立时间要求为 400ps 或 0.4ns。
根据定义，这是“set_output_delay”值。

### COMBINATIONAL LOGIC TIMING

```text
set_output_delay -max 0.1 -clock clk [get_ports Cout]
set_input_delay -max 0.3 -clock clk [get_ports Cin*]
```

The maximum delay through the combinational logic is 2.45ns. This can be constrained by pretending that there are launching registers on the input ports Cin1 and Cin2 and capturing registers on the output port Cout, and applying corresponding input and output delays. The sum of the external input and output delay values must be equal to the clock period minus the clock uncertainty minus the maximum combo delay = 3ns - 0.15ns - 2.45ns = 0.4ns.
组合逻辑的最大延迟为 2.45ns。 这可以通过假装输入端口 Cin1 和 Cin2 上有启动寄存器并在输出端口 Cout 上有捕获寄存器并应用相应的输入和输出延迟来限制。 外部输入和输出延迟值之和必须等于时钟周期减去时钟不确定性再减去最大组合延迟 = 3ns - 0.15ns - 2.45ns = 0.4ns。

This means that the input and output delay values can be 0.4 and 0.0, or 0.2 and 0.2, or 0.1 and 0.3, etc., respectively.
这意味着输入和输出延迟值可以分别为0.4和0.0、或0.2和0.2、或0.1和0.3等。

### ENVIRONMENTAL ATTRIBUTES

```text
set_driving_cell -lib_cell bufbd1 -library cb13fs120_tsmc_max \
[remove_from_collection [all_inputs] [get_ports "clk Cin*"]]
```

All input ports, except clk and Cin, are driven by bufbd1 buffers
除了 clk 和 Cin 之外，所有输入端口都由 bufbd1 缓冲器驱动

```text
set_load -max [expr {2 * [load_of cb13fs120_tsmc_max/bufbd7/I]}] [get_ports out*]
```

All outputs, except Cout, drive 2x bufbd7 loads.
所有输出，除了 Cout，驱动 2x bufbd7 负载。

```text
set_load 0.025 [get_ports Cout*]
```

Cout drives 25fF, or .025 pF
Cout 驱动 25fF，或 .025 pF

```text

## ERROR

Error: Value for list '-clock' must have 1 elements. (CMD-036)
