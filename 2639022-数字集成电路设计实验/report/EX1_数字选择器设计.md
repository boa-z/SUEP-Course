# 实验一 数字选择器设计

## 1 实验目的

2、完成二选一功能块的行为和结构描述，以及测试程序的编写
3、熟练掌握VI编辑器，并用VCS调试验证设计程序的正确性

## 2 实验要求

用VI编辑器完成二选一的源程序、测试程序的编写，并用VCS仿真验证设计的正确性

## 3 实验内容和步骤

1. 实验的源代码
2. 实验的测试代码
3. VCS仿真结果（用截图的方法把VCS仿真结果拷贝下来）

---

> prompt:

使用verilog编写一个二选一功能块，下面是代码的模版。

```verilog
module DUT_tb ()  ; 
reg ...                 // 主要输入寄存器
wire  ...               // 主要输出声明
DUT u_DUT(...);       // 待测设计例化
initial $monitor (...);         // 以文本形式监测并显示信号描述
initial #time_out  $finish   // 确保模拟终端停止观测
initial              // 设计一个或多个激励信号发生器
begin
              // 仿真激励的施加
end
endmodule
```

> output:

这里是使用Verilog编写一个二选一功能块的代码:

```verilog
module mux_2to1(
  input wire sel,
  input wire a,
  input wire b,
  output wire out
);

assign out = sel ? a : b;

endmodule

module mux_2to1_tb();

reg sel;
reg a;
reg b;
wire out;

mux_2to1 dut(
  .sel(sel),
  .a(a),
  .b(b),
  .out(out)
);

initial begin
  $monitor("sel = %b, a = %b, b = %b, out = %b", sel, a, b, out);
  
  sel = 0; a = 0; b = 1; #10;
  sel = 0; a = 1; b = 0; #10;
  sel = 1; a = 0; b = 1; #10;
  sel = 1; a = 1; b = 0; #10;
  
  $finish;
end

endmodule
```

这个测试平台对二选一模块进行了简单的验证,通过改变sel, a, b的不同组合,监测out的输出是否正确。可以根据需求修改测试用例。

output:

```text
<u14220201912-~/Desktop/2021xxxx> $./simv
Chronologic VCS simulator copyright 1991-2018
Contains Synopsys proprietary information.
Compiler version 0-2018.09-SP2-8 Full64; Runtime version 0-2018.09-SP2-8 Full64; Sep 27 23:30 2023
sel = 0, a = 0, b = 1, out = 1
sel = 0, a = 1, b = 0, out = 0
sel = 1, a = 0, b = 1, out = 0
sel = 1, a = 1, b = 0, out = 1
$finish called from file "mux 2tol.v", line 34.
$finish at simulation time
40
ves Simulation Report
Time: 40
CPU Time:
0.170 seconds;
Wed Sep 27 23:30:04 2023
Data structure size: 0.0Mb
```

## 4 实验总结

见readme。
