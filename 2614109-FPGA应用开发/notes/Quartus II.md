# Quartus II

实验指导书还是太驹，稍微做一点补充

## 一些功能的使用

引脚分配

assignments -> pin planner

七段数码管显示的Verilog简单设计 - [看看这个](https://cloud.tencent.com/developer/article/1651661)
七段数码管是共阳极的，即各管段输入低电平时，数码管亮；否则数码管暗。

改变Quartus II编译的文件 -> `Set as Top-Level Entity`

但是! 这个方法现在显示已经更换了编译的文件，但实际没换过来

### 为.v文件创建一个符号

右键要生成符号的.v文件 -> 点击`Create Symbol Files for Current File`

### 元件实例化语句(元件调用)

[Quartus II的实例化的操作](https://blog.csdn.net/Aysek/article/details/122071782)

[模块例化是怎么进行的？——FPGA学习笔记（四）](https://blog.csdn.net/sy243772901/article/details/84892644)

## 一些报错的处理

高血压合集（确信

> Editing location assignment is not successful. The pin is already assigned.

不知道该咋解决...

> Error (10839): Verilog HDL error at char_4to1_7segv.v(1): declaring global objects is a SystemVerilog feature

不知道该咋解决...+1

---

> Error: Width mismatch in port "clk" of instance "inst5" and type counter_24 -- source is ""cout[3..0]" (ID counter_6:inst11)"

这个错误信息表明在实例化 `counter_24` 类型的模块时，端口 `clk` 的宽度与源信号 cout[3..0] 的宽度不匹配。通常情况下，时钟信号 clk 应该是一个单比特信号，而不是一个多比特的总线。你可以检查一下你的代码，确保在实例化 counter_24 模块时，为 clk 端口提供了正确的单比特信号。

> Error: Can't elaborate top-level user hierarchy

This error message is typically encountered when Quartus II is unable to elaborate the top-level user hierarchy of a design. This can occur for a variety of reasons, including syntax errors in the design files, missing or incorrect settings in the project configuration, or issues with the design hierarchy.

Here are some possible solutions to try:

Check for syntax errors: Review your design files, including any Verilog or VHDL source files and any instantiated sub-modules, to make sure that there are no syntax errors. Even a small syntax error can cause the elaboration process to fail. Pay special attention to syntax errors in port declarations, parameter settings, and instantiation statements.
Check for missing files: Make sure that all necessary design files are present in the project directory and have been added to the Quartus II project. Verify that any sub-modules have been correctly instantiated and that all required parameters have been specified.
Check the project settings: Verify that the project settings are correctly configured, including the target device and any required IP cores or libraries. Make sure that the top-level design file is specified correctly in the project settings.
Check the design hierarchy: Verify that the design hierarchy is correctly defined, with all sub-modules correctly instantiated and connected to the top-level module. Use the "Hierarchy Viewer" tool in Quartus II to visualize the design hierarchy and ensure that all signals are connected correctly.
Try a clean build: Sometimes a clean build can help to resolve errors that are not immediately obvious. Try deleting any intermediate files and rebuilding the project from scratch.
If none of these solutions solve the problem, you may need to seek additional help, such as from the Quartus II support team or online forums.
