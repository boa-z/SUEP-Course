# VCS仿真调试基础实验

VCS_simulation_debugging_basic

把`/qixin/public/EDA/vcs_lab`拷贝到自己的目录下

实验目的：

通过使用VCS编译一个已存在的verilog设计进行VCS可执行仿真
通过执行由VCS产生的二进制可执行仿真对Verilog设计的operation进行仿真
通过阅读由Verilog源代码中的Verilog系统任务调用产生的控制台信息决定Verilog设计是否通过了验证了
使用Verilog系统任务调用调试一个已存在的Verilog设计
VCS CLI调试器调试

实验步骤：

1、使用Verilog系统任务调用进行调试（根据实验结果截图来说明）

内容：VCS实验指导书 实验1、实验2 A和B部分

## 实验1

### A部分：两步骤仿真过程

任务1  编译并产生可执行仿真文件

```sh
ls
vcs addertb.v fa.v add4.v add8.v
```

任务2  运行仿真
运行测试台文件并执行simv对设计进行仿真。

```sh
simv
```

任务4  使用不同的名称创建可执行仿真

```sh
vcs addertb.v fa.v add4.v add8.v –o addertest
ls
addertest
```

### B部分 使用库目录

任务1  使用设计库目录进行编译和仿真

```sh
cd ../partb
ls
vcs addertb.v add8.v –y ../../lib +libext+.v -R
```

任务2  使用-f参数进行编译

## 实验2 VCS调试基础

在本实验中将使用以下的8位carry-select加法器 -- IMG SKIPPED --

在实验文件中我们嵌入了一些错误。我们的目标是使用在讲义中提到的调试技术去定位并修正错误。你将会看见一个方框图用以表示Verilog代码打算执行的操作。

### A部分：使用Verilog系统任务调用进行调试

任务1  有用的VCS参数

```sh
cd ../../lab2/parta
vcs -h
```

任务2  编译并运行第一遍验证
对carry select加法器进行编译并仿真。

```sh
vcs –f adder.f -R
```

一个错误被报告出来：

```text
*** ERROR at time = 25750 ***
a = 01, b = 01, sum = 00, cin = 0, cout = 0
```

任务3  调试错误

```sh
more addertb.v
```

output:

```verilog
module addertb.v;
    reg [7:0] a_test,b_test;
    wire [7:0] sum_test;
    reg cin_test;
    wire cout_test;
    reg [17:0] test;

add8 u1(a_test,b_test,cin_test,sum_test,cout_test);

initial
    if (!$test$plusargs("monitoroff"))
        $monitor ($time, " %h+%h=%h;cin=%h,cout=%h",
        a_test,b_test,sum_test,cin_test,cout_test);
initial
    begin
    for (test=0,test<=18'h1ffff; test=test+1) begin
            cin_test=test[16];
            a_test=test[15:8];
            b_test=test[7:0];
            #100;
            if ({cout_test,sum_test}!= =(a_test+b_test+cin_test)) begin
                $display("***ERROR at time = %0d ***",$time);
                $display("a=%h,b=%h,sum=%h,cin=%h,cout=%h",
                        a_test,b_test,sum_test,cin_test,cout_test);
              $finish;
            end
    end
    $display("***Testbench Successfully completed!***");
    $finish;
end
endmodule
```

在addertb.v中加入以下三行：

```verilog
$display("\nIn add8(u1)");
$display("a=%b,b=%b,sum=%b,cin=%b,cout=%b",
    u1.a,u1.b,u1.sum,u1.cin,u1.cout);
```

随后运行

```sh
vcs –f adder.f –R
```

此处似乎不太对，先skip

在addertb.v中加入下列内容：

```verilog
$display("\nIn add4(u1)");
$display("a=%b,b=%b,sum=%b,cin=%b,c=%b,cout=%b",
    u1.u1.a,u1.u1.b,u1.u1.sum,u1.u1.cin,u1.u1.c,u1.u1.cout);
```

通过将`$finish`系统任务调用改为`$stop`，创建一个断点。

需要注意的是，教程给出的旧版指令已经不能运行，故暂时跳过

---

下面是经过修改后的代码：（未验证）

```verilog
module addertb.v;
    reg [7:0] a_test,b_test;
    wire [7:0] sum_test;
    reg cin_test;
    wire cout_test;
    reg [17:0] test;

add8 u1(a_test,b_test,cin_test,sum_test,cout_test);

initial
    if (!$test$plusargs("monitoroff"))
        $monitor ($time, " %h+%h=%h;cin=%h,cout=%h",
        a_test,b_test,sum_test,cin_test,cout_test);
initial
    begin
    for (test=0,test<=18'h1ffff; test=test+1) begin
            cin_test=test[16];
            a_test=test[15:8];
            b_test=test[7:0];
            #100;
            if ({cout_test,sum_test}!= =(a_test+b_test+cin_test)) begin
                $display("***ERROR at time = %0d ***",$time);
                $display("a=%h,b=%h,sum=%h,cin=%h,cout=%h",
                        a_test,b_test,sum_test,cin_test,cout_test);
                $display("\nIn add4(u1)");
                $display("a=%b,b=%b,sum=%b,cin=%b,c=%b,cout=%b",
                    u1.u1.a,u1.u1.b,u1.u1.sum,u1.u1.cin,u1.u1.c,u1.u1.cout);
                $display("\nIn add8(u1)");
                $display("a=%b,b=%b,sum=%b,cin=%b,cout=%b",
                    u1.a,u1.b,u1.sum,u1.cin,u1.cout);
              $finish;
            end
    end
    $display("***Testbench Successfully completed!***");
    $finish;
end
endmodule
```

### B部分 使用VCS CLI调试器进行调试

任务1  编译并运行第一遍验证

```sh
cd ../partb
vcs –f adder.f -R
```

任务2  使能CLI调试器参数进行编译

修改`$finish`为`$stop`，并运行

```sh
vcs –f adder.f -debug_access+all -ucli -R
```

任务3  使用CLI调试器进行调试

查看信号的值，使用`show 信号 -value -radix hex/bin/dec`命令,显示信号的值，以特定的进制显示。

```ucli
run
###
show -value # 等价于 show a_test b_test cin_test cout_test sum_test -value
scope u1
show
```

在调试过程中，你常需要多次输出变量相同设置的值。为这个经常被执行的任务创建一个别名会让工作变得简单一些。一旦创建了别名，执行时只需要输入别名就可以了。

```ucli
alias prvars show a b sum sum_0 sum_1 cin c4 -value
prvars
```

在这里你可以看见错误的细节。2:1选择器应该sum_0为0的值但是却选择了sum_1为1的值。这就是问题所在。

Create a new terminal and input:

```sh
more add8.v
```

查看选择器代码。选择器的输入反了。实际上，sum和carry mux存在同样的错误。

```verilog
assign sum[7:4] = c4?sum_0:sum_1;
assign cout = c4?c8_0:c8_1;
```

先不要纠正错误。转到CLI调试器窗口。
很幸运，你可以在不离开CLI环境的情况下仿效一个正确的。如果你将sum_0加法器的carry-in改变为“1”并将sum_1加法器的carry-in改变为“0”，问题就得到有效的改正了。
注意zero_add_cin和one_add_cin信号的当前值为多少。

```ucli
show zero_zdd_cin  one_add_cin -value
```

将zero_add_cin信号的值改为“1”并将one_add_cin信号的值改为“0”，请注意，此处不需要“=”号，原教程有错。

```ucli
force zero_add_cin 1
force one_add_cin 0
```

查看所有的值，使用你创建的别名“prvars”。在创建别名的时候你没有包含zero_add_cin和one_add_cin。由于你查看所有的值时需要把它们加入命令行。

```ucli
show zero_add_cin one_add_cin -value
###
run
show -value
```

现在所有的值都应该是正确的。返回测试台级别并验证加法器能正常工作。

```ucli
upscope
show a_test b_test cin_test cout_test sum_test -value
###
stop -posedge u1.c4
run
```

提示 invalid command name "upscope"
