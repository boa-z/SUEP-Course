# EX4 1bit_signal_edge_detection

1bit信号边沿检测设计与仿真

一、实验目的：

1、掌握常规时序逻辑电路的设计与仿真
2、熟练掌握VI编辑器，并用VCS调试验证设计程序的正确性

二、实验要求：

用VI编辑器完成实现1bit信号正边和负边沿检测功能，并输出一个周期宽度的脉冲信号电路的源程序、测试程序的编写，并用VCS仿真验证设计的正确性

---

编写一段verilog程序，实现输入1bit信号sign_in的正边和负边沿检测功能，当检测到时输出固定长度为时钟周期宽度的脉冲信号.
输入信号sign_in,输出信号pulse,时钟信号clk。
程序和其测试代码分别命名为edge_detection.v和edge_detection_tb.v
注意：一个周期结束后再检测

请修改输出信号pulse的产生逻辑，使其长度固定为clk时钟周期宽度

组合逻辑电路/时序逻辑电路 区别？

三、实验内容和步骤

1、实验的源代码
2、实验的测试代码
3、VCS仿真结果
（用截图的方法把VCS仿真结果拷贝下来）

四、实验总结

edge_detection.v

```verilog
module edge_detection(
    input clk,
    input rst,
    input data,
    output pos_edge,
    output neg_edge,
    output data_edge
);

reg[1:0] data_n;
always @(posedge clk or negedge rst)
begin
    if(rst==1'b1)
        begin
        data_n<=2'b00;
        end
    else
    begin
        data_n<={data_n[0],data};
    end
end
assign pos_edge=(~data_n[1]) && data_n[0];
assign neg_edge=data_n[1] && (~data_n[0]);
assign data_edge=pos_edge | neg_edge;
endmodule
```

edge_detection_tb.v

```verilog
module edge_detection_tb();
reg clk, rst, data;
wire pos_edge , neg_edge , data_edge;

edge_detection uut(
    .clk(clk),
    .rst(rst),
    .data(data),
    .pos_edge(pos_edge),
    .neg_edge(neg_edge),
    .data_edge(data_edge));
    
always #2 clk = ~clk;

initial begin
    $monitor($stime,,"clk=%b rst=%b data=%b pos_edge=%b neg_edge=%b data_edge=%b" , clk, rst , data, pos_edge , neg_edge , data_edge);
    clk=0; rst=0; data=1;
    #10 data=0;
    #10 data=1;
    #10 data=0;
    #10 data=1;
    #10 rst=1;
    #40 $finish;
end

initial begin
    $vcdpluson; // vcdplus.vpd格式的波形文件
end
endmodule
```
