# 实验二 实现全加器功能代码、测试代码

## 1 实验目的

1、 完成一位全加器功能块的行为和结构描述，以及测试代码的编写
2、 熟练掌握VI编辑器，并用VCS调试验证设计程序的正确性

## 2 实验要求

用VI编辑器完成全加器的源程序、测试程序的编写，并用VCS仿真验证设计的正确性

## 3 实验内容和步骤

> FROM PPT

full_adder.v

```verilog
//-----------------------------------------------------------
// FileName: full_adder.v
// Creator : klin
// E-mail  : klin@eecourse.com
// Function: one bit full adder
// Update  :
// Coryright: www.eecourse.com //基本的模块开发信息
//-----------------------------------------------------------

module full_adder (       
  // module head: verillog-2001 format
  input  wire a_in,
  input  wire b_in,
  input  wire c_in,     // carry in
  output wire sum_out,
  output wire c_out     // carry out
);

  // method 1 Gate Level describe方法1
  assign sum_out = a_in ^ b_in ^ c_in;//得到和
  assign c_out   = (a_in & b_in) | (b_in & c_in) | (a_in & c_in);//得到进位

  // method 2 RTL design for Adder with the keyword "assign"方法2
  // behavior of the adder can be synthesizable
  // "assign" means connectivity, which is used to describe a combinational circuit
  //assign {c_out, sum_out} = a_in + b_in + c_in;//使用拼接，一块得到

  // method 3 RTL design for Adder with the keyword "always“方法3
  // reg c_o, sum_o;
  //always @ (a_in, b_in, c_in) begin
  //  {c_o, sum_o} = a_in + b_in + c_in;  // the reg type variable is required in the always blocks
  //end
  // assign {c_out, sum_out} = {c_o, sum_o};
endmodule
```

full_adder_tb.v -- PPT

```verilog
//-----------------------------------------------------------
// File header
//-----------------------------------------------------------

module full_adder_tb;
  // drive the input port with the reg type
  reg ain, bin, cin; 
  // sample the output port with the wire type
  wire sumout, cout; 

//例化DUT
  full_adder u_full_adder(
    // task 1. how to create an instance
    // module head: verillog-2001 format
    /*input  wire */ .a_in   (ain),
    /*input  wire */ .b_in   (bin),
    /*input  wire */ .c_in   (cin),     // carry in
    /*output wire */ .sum_out(sumout),
    /*output wire */ .c_out  (cout)   // carry out
  );

  // behavior of the adder can be synthesizable
  // "assign" means connectivity
  // assign {c_out, sum_out} = a_in + b_in + c_in;

  //task 2. clock and reset generator
  parameter CLK_PERIOD = 20;
  reg clk, reset_n; // reset_n : active low

  initial begin  //initial块，时钟激励波形生成
    clk = 0;
    forever begin
      #(CLK_PERIOD/2) clk = ~clk;
    end
  end

  initial begin //initial块 ，复位激励波形生成
    reset_n = 0;
    #100 
    reset_n = 1;
  end

 //task 3. drive the stimulus and capture the response
  //here is a testcase
  initial begin  //过程块2，顺序给其余输入激励（非 clock、reset）加上信号数值
    #110 ain = 0; bin = 0;  cin = 0;  // 00
    #20   ain = 0; bin = 1;  cin = 0;  // 01
    #20   ain = 1; bin = 0;  cin = 0;  // 01
    #20   ain = 1; bin = 1;  cin = 0;  // 10
    #20   ain = 0; bin = 0;  cin = 1;  // 01
    #20   ain = 0; bin = 1;  cin = 1;  // 10
    #20   ain = 1; bin = 0;  cin = 1;  // 10
    #20   ain = 1; bin = 1;  cin = 1;  // 11
    //#20  ain = 1; bin = 1;  cin = 0;  // 10
    #50  $finish;  // here is a system task which can stop the simulation 
  end

  // task 4. check the result    //检查结果
  always @ (posedge clk) begin  //always过程块
    if (!reset_n) begin
      $display("%t:%m: resetting ...",$time); // counter 5 clock
    end
    else begin
      $display("%t:%m: resetting finish!", $time); // the 6th clock
    end
  end
  initial begin   //initial 过程块2，顺序检查，如果结果不正确，则利用display系统函数打印出ERROR
    #115 if ({cout,sumout} != 2'b00) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b01) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b01) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b10) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b01) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b10) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b10) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b11) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
    #20  if ({cout,sumout} != 2'b10) $display("Error: {cout,sumout}=%b,ain=%b, bin=%b, cin=%b",{cout,sumout}, ain, bin, cin);
  end

  // task 5. dump waveform with the compile option -debug_all  //转储波形文件
  initial begin
    $vcdpluson;  // vcdplus.vpd格式的波形文件
  end
endmodule
```

full_adder_tb.v -- SD

```verilog
module full_adder_tb
...
```

运行

```sh
vcs -debug_all full_adder.v full_adder_tb.v -l com.log
./simv -l sim.log
dve -vpd vcdplus.vpd &vd
```
