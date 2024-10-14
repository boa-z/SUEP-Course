# final task 03

## requirement

任务三 频率计仿真和综合

1、按下列功能要求，使用 verilog 语言编写 RTL 代码及对应测试代码

用状态机设计一个自动转换量程的频率计的控制部分，用case语句描述。流程图如下

| State | Action                                               |
| ----- | ---------------------------------------------------- |
| Start |                                                      |
| A     | Enter 100K range: `reset=1; std_f_set=00; cntlow=1`  |
| C     | Enter 10K range: `reset=1; std_f_set=01; cntlow=1`   |
| E     | Enter 1K range: `reset=1; std_f_set=11; cntover=1`   |
| B     | Enter 100K range: `reset=0; std_f_set=00; cntover=1` |
| D     | Enter 10K range: `reset=0; std_f_set=01; cntover=1`  |
| F     | Enter 1K range: `reset=0; std_f_set=11;`             |

信号定义：

| 信号名    | 作用                           |
| --------- | ------------------------------ |
| Clk       | 输入信号                       |
| Clear     | 为整个频率计的异步复位信号     |
| Reset     | 用来在量程转换开始时复位计数器 |
| Std_f_sel | 用来选择标准时基               |
| Cntover   | 代表超量程                     |
| cntlow    | 代表欠量程                     |

According to the following functional requirements, use Verilog language to write RTL code and corresponding test code

Use state machine to design the control part of a frequency meter that automatically switches the range, and describe it with case statements. The flow chart is as follows

| State | Action                                               |
| ----- | ---------------------------------------------------- |
| Start |                                                      |
| A     | Enter 100K range: `reset=1; std_f_set=00; cntlow=1`  |
| C     | Enter 10K range: `reset=1; std_f_set=01; cntlow=1`   |
| E     | Enter 1K range: `reset=1; std_f_set=11; cntover=1`   |
| B     | Enter 100K range: `reset=0; std_f_set=00; cntover=1` |
| D     | Enter 10K range: `reset=0; std_f_set=01; cntover=1`  |
| F     | Enter 1K range: `reset=0; std_f_set=11;`             |

Signal definition:

| Signal name | Function                                                       |
| ----------- | -------------------------------------------------------------- |
| Clk         | Input signal                                                   |
| Clear       | Asynchronous reset signal for the entire frequency counter     |
| Reset       | Used to reset the counter at the beginning of range conversion |
| Std_f_sel   | Used to select the standard time base                          |
| Cntover     | Represents overrange                                           |
| cntlow      | Represents underrange                                          |

2、仿真调试完成后，按下列要求综合，最后版图设计

按下列要求完成约束文件的编写：

（1）建立名为my_clk的250Mhz的时钟；
（2）设置时钟漂移为0.25ns；
（3）时钟寄存器不与时钟网络连接；
（4）设置除时钟外输入端口的表达式，类似宏定义；
（5）设置除时钟外输入端口最大延时为1ns；
（6）设置输出端口延时为3ns。

综合后生成timing.rpt文件，检查确保slack>0，生成.sdf文件，用于后仿真，

其中：
clk: 为同步时钟信号；
Clr: 为异步复位信号。
