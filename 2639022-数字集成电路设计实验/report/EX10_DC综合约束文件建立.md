# DC综合约束文件实验（2个课时）

约束文件建立

## 一、实验目的

1.基于给定的原理图创建约束文件
2.验证约束文件的语法
3.将约束应用于设计
4.验证约束的有效性和完整性

## 二、实验步骤

（对应DC逻辑综合实验手册pdf中的实验3（任务一不做））

生成的单元使用的约束库
基于给定的原理图和说明创建约束文件
验证约束的有效性和完整性
（提示进入DC的时候，要注意读入设计文件，参考实验一）

## 约束条件说明

Clock Definition

1. Clock c1k has a frequency of 333.33 Mhz.
2. The maximum external clock generator delay to the clock port is 700ps. (HINT: source latency)
3. The maximum insertion delay from the clock port to all the register clock pins is 300ps +/- 30ps. (HINT: Treat the 300ps as network latency and the +/-30ps as clock skew)
4. The clock period can fluctuate +/- 40ps due to jitter.
5. Apply 50ps of "setup margin" to the clock period.
6. The worst case rise/fall transition time of any clock pin is 120 ps.

时钟定义

1. 时钟 clk频率 333.333Mhz
2. 最大外部时钟延时为700ps
3. 内部时钟延时 300ps，抖动+/-30ps
4. 建立时间余量 50ps
5. 时钟管脚的最坏上升沿下降沿转换时间为120ps

---

Register Setup Time

Assume a maximum setup time of 0.2ns for any register in MY_DESIGN

寄存器建立时间

对于任何寄存器，最大建立时间 0.2ns

---

Input Ports (sequential logic)

1. The maximum delay from ports datal and data2 through the internal input logic S is 2.2ns.
2. The latest F3 data arrival time at the sel port is 1.4ns absolute time. (HINT: Input delay is specified as relative time - relative to the launching clock edge)

输入端口（组合逻辑）

1. 从Data1, data2输入的数据经过S组合逻辑后，最大延迟为2.2ns
2. 从F3 寄存器输出到达 sel端口的绝对时间为 1.4ns。（输入延时定义为相对时间，以寄存器的锁存时钟沿为参考）

---

Output Ports (sequential logic)

1. The maximum delay of the external combo logic at port out1 is 420ps; F6 has a setup time of 80ps.
2. The maximum internal delay to out2 is 810ps
3. The out3 port has a 400ps setup time requirement with respect to its capturing register clock pin.

输出端口（时序逻辑）

1. 经由 out1 端口输出的组合逻辑最大延时为420ps，寄存器F6的建立时间为80ps。
2. 经由 out2 输出的组合逻辑最大延时为 810ps.
3. Out3 驱动的寄存器有 400ps 的建立时间要求。

---

Combinational Logic

The maximum delay from Cin1 and Cin2 to Cout is 2.45ns. (HINT: Use appropriate input and output delay constraints with respect to clock clk)

组合逻辑

从 cin1, cin2到 cout 的最大延时为 2.45ns

## 任务1 提取目标库的时间单位

1 进入到 Lab3 目录下， 用 vim 打开`common_setup.tcl`文档，确认`TARGET_LIBRARY_FILES`变量。

2 输入以下命令，调用 Design Compile Topographical

```sh
dc_shell  -topo | tee -l lab3.log
```

3 输入以下命令，提取目标库的时间单位

```sh
redirect -file lib.rpt {report_lib cb13fs120_tsmc_max}
```

## 任务2 创建时序约束文件

1 创建`scrips`目录，创建`MY_DESIGN.con`约束文件。

2 参照`.solutions/MY_DESIGN.con`文件输入约束内容。

```text
# Remove any existing constraints and attributes
reset_design

######################
#                    #
#  CLOCK DEFINITION  #
#                    #
######################

# A 333Mhz clock is a 3.Ons period:
#
create_clock -period 3.0 [get_ports clk]

# External clock source latency is 700ps or 0.7ns
#
set_clock_latency -source -max 0.7 [get_clocks clk]

# The maximum internal clock network insertion delay or latency is 300ps or 0.3 ns:
#
set_clock_latency -max 0.3 [get_clocks clk]

# The +/-30ps internal clock delay variation to register clock pins results in a 60ps worst case skew or uncertainty, if you launch
# late (+30ps) and capture early (-30ps)r; Add 40ps due to jitter and 50ps for setup margin;
# This equals 150ps or 0.15 ns of total uncertainty.
#
set_clock_uncertainty -setup 0.15 [get_clocks clk]
```

3 在 LINUX命令窗口输入以下命令，检查约束文件语法。

```sh
dcprocheck scripts/MY_DESIGN.con
```

## 任务3 使用约束并验证约束

1 在 lab3 目录下，使用`ls`查看是否存在`MY_DESIGN_LIB`文件夹。
`MY_DESIGN_LIB`文件夹是`Milkyway design library`，任务1当中首次启动`DC`创建。

2 读取，链接，检查`rtl/MY_DESIGN.v`文件。

```sh
read_verilog rtl/MY_DESIGN.v
link
check_design
```

3 输入以下命令，调用约束文件。

```sh
source scripts/MY_DESIGN.con
```

4 输入以下命令，检验关键约束是否存在缺失或冲突

```sh
check_timing
```

5 输入以下命令，验证时钟和端口约束

```sh
report_clock
report_clock -skew
report_port -verbose
```

6 输入以下命令，以展开形式将约束导出

```sh
write_script -out scripts/MY_DESIGN.wscr
```

7 在LUNIX命令窗口输入以下命令，比对展开后约束文件同原始文件区别

```sh
tkdiff scripts/MY_DESIGN.wscr .solutions/MY_DESIGN.wscr
# or
diff scripts/MY_DESIGN.wscr .solutions/MY_DESIGN.wscr
```

8 输入以下命令，保存 ddc 文件

```sh
write -format ddc -hier -out unmapped/MY_DESIGN.ddc
```

9 退出DC
