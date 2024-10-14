# 3

## Requirements

Lab03:

DC（综合）的概念，什么是目标库，什么是链接库，实验中用的目标库和链接库是什么？
(要求写在实验报告中，)

1. run_da.tcl中 三个综合命令是什么意思？

    ```sh
    compile_ ultra
    compile_ultra -incremental
    optimize_netlist -area
    ```

2. alu.sdc文件中每条命令是什么意思
3. slack指标代表什么意思
4. 如何导入设计文件

## Guide

```sh
cd lab03/syn/dc/

dc_shell
```

in dc_shell:

```sh
source run_dc.tcl
report_timing
```

## Q&A

### run_da.tcl

run_da.tcl中 三个 DC 综合命令是什么意思？

```sh
compile_ ultra
compile_ultra -incremental
optimize_netlist -area
```

解释：

1. `compile_ ultra`：综合，使用目标库中的最高级别的综合选项。
2. `compile_ultra -incremental`：综合，使用目标库中的最高级别的综合选项，并增量综合。
3. `optimize_netlist -area`：优化综合后的电路，以面积为目标。

### alu.sdc

alu.sdc文件中每条命令是什么意思

```tcl
#create clock
create_clock -name clk -period 10 -waveform {0 5} [get_ports clock]

#create vclock
create_clock -name vclk -period 10 -waveform {0 5}

#uncertainly
set_clock_uncertainty -setup 0.3 [all_clocks]
set_clock_uncertainty -hold 0.2 [all_clocks]

#clock group
#set_clock_groups -logically_exclusive -group {clk vclk}

#input/output delay 50% 50%
set_input_delay  -add_delay 0.5 -clock vclk [all_inputs]
set_output_delay -add_delay 0.5 -clock vclk [all_outputs]
set_input_delay  -add_delay 0.5 -clock clk [all_inputs]
set_output_delay -add_delay 0.5 -clock clk [all_outputs]

#set_max_transition 0.3 [current_design]
#set_max_transition -clock_path 0.2 [all_clocks]

set_clock_latency 3 [get_clocks vclk]
```

解释：

1. `create_clock -name clk -period 10 -waveform {0 5} [get_ports clock]`：创建时钟，时钟名为`clk`，周期为10ns，波形为`0 5`，时钟源为`clock`端口。
2. `create_clock -name vclk -period 10 -waveform {0 5}`：创建时钟，时钟名为`vclk`，周期为10ns，波形为`0 5`。
3. `set_clock_uncertainty -setup 0.3 [all_clocks]`：设置时钟不确定性，setup为0.3ns。
4. `set_clock_uncertainty -hold 0.2 [all_clocks]`：设置时钟不确定性，hold为0.2ns。
5. `set_input_delay  -add_delay 0.5 -clock vclk [all_inputs]`：设置输入延迟，增加延迟0.5ns，时钟为`vclk`，所有输入。
6. `set_output_delay -add_delay 0.5 -clock vclk [all_outputs]`：设置输出延迟，增加延迟0.5ns，时钟为`vclk`，所有输出。
7. `set_input_delay  -add_delay 0.5 -clock clk [all_inputs]`：设置输入延迟，增加延迟0.5ns，时钟为`clk`，所有输入。
8. `set_output_delay -add_delay 0.5 -clock clk [all_outputs]`：设置输出延迟，增加延迟0.5ns，时钟为`clk`，所有输出。
9. `set_clock_latency 3 [get_clocks vclk]`：设置时钟延迟，时钟为`vclk`，延迟为3ns。

### slack

slack指标代表什么意思

```text
clock clk (rise edge)                                  10.00      10.00
  clock network delay (ideal)                             0.00      10.00
  clock uncertainty                                      -0.30       9.70
  u0_alu/u0_arith_alu/aluout_reg[31]/CK (DQHDV2)          0.00       9.70 r
  library setup time                                     -0.14       9.56
  data required time                                                 9.56
  --------------------------------------------------------------------------
  data required time                                                 9.56
  data arrival time                                                 -9.54
  --------------------------------------------------------------------------
  slack (MET)                                                        0.02


  Startpoint: control_in[1]
              (input port clocked by vclk)
  Endpoint: mem_write_en
            (output port clocked by vclk)
  Path Group: vclk
  Path Type: max

  Point                                    Incr       Path
  -----------------------------------------------------------
  clock vclk (rise edge)                   0.00       0.00
  clock network delay (ideal)              3.00       3.00
  input external delay                     0.50       3.50 f
  control_in[1] (in)                       0.00       3.50 f
  U1487/ZN (INHDVL)                        0.13       3.63 r
  U1674/ZN (NAND4HDVL)                     0.15       3.79 f
  mem_write_en (out)                       0.00       3.79 f
  data arrival time                                   3.79

  clock vclk (rise edge)                  10.00      10.00
  clock network delay (ideal)              3.00      13.00
  clock uncertainty                       -0.30      12.70
  output external delay                   -0.50      12.20
  data required time                                 12.20
  -----------------------------------------------------------
  data required time                                 12.20
  data arrival time                                  -3.79
  -----------------------------------------------------------
  slack (MET)                                         8.41


1
dc_shell>   
```

解释：

在时序分析中，slack 是一个关键指标，用来衡量设计中时序路径的时序裕量。它表示信号在特定路径上是否按时到达或者是否存在时序违反。如果 slack 值为正数，则表明设计满足时序要求；如果 slack 值为负数，则表示存在时序违例。

1. `slack (MET) 0.02`：slack指标为0.02ns，MET表示满足时序要求。
2. `slack (MET) 8.41`：slack指标为8.41ns，MET表示满足时序要求。
