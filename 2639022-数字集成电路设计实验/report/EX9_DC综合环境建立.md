# DC综合环境建立

```sh
cd /qixin/public/edu/labs/backend/dc
```

实验指导书在dc/lab_guide/DC逻辑综合实验手册pdf

## 一、实验目的

1. 掌握setup文件的编写
2. 了解DC的图形化界面
3. 熟悉基本的综合流程

## 二、实验步骤

（对应DC逻辑综合实验手册pdf中的实验1）

检查并修改common_setup.tcl和dc_setup.tcl
启动Design Vision并验证setup文件
读取rtl/TOP.v，并打开schematic views
读取约束脚本scripts/TOP.con
综合设计compile_ultra
产生输出报告并分析QoR
输出文件并保存 mapped/TOP.ddc

## 任务1

1 进入lab1 目录并打开 setup文件

```sh
cd lab1
ls -al .synopsys*
ls -al *setup*
```

然后需要修改文件

DC 工具会默认读取`.synopsys_dc.setup`，该文件 source 了其他两个 setup 文件：
common_setup.tcl #1 dc_setup.tcl.
common_setup.tcl 定义了许多变量，这些变量在`dc_setup.tcl`中被使用，`dc_setup.tcl`定义了综合需要的几个固有变量。

2 根据下面信息，完成`common_setup.tcl`中的空格部分

## 任务2: 设计和库

1 启动软件

```sh
design_vision -topo
```

参考上图，熟悉图形化界面的基本使用

2 通过 File setup 验证 setup 文件是否设置正确，包括 link library, target li
library, search path #

3 验证 setup 文件是否设置正确：

```sh
printvar target_library
printvar link_library
printvar search_path
```

4 输入以下命令，检验物理设计和逻辑设计的一致性

```sh
check_library
```

5 检验 TLUPus 和 Technology 文件的一致性

```sh
check_tlu_plus_files
```

## 任务3: 读取设计

1. 点击 File>Read，在弹出的对话框中，双击rtl 目录，选择Top.v
在`Logical Hierarchy`窗口中，可以看到一个`Top`的顶层和三个子模块：`I_FSM`, `L_DECODE`和`L_COUNT`
2. 选择`Top`，这时可以看到`GUI`的右下角显示`Design: TOP`，这是确保 current_design 为`Top`
3. 选择 File-Link Design OK 以 link design 来解析所有的reference，确保没有任何 Warning 和 Errors.
4. 输入以下命令以保存目前的 design 为ddc 格式: `write -hier -f ddc -out unmapped/TOP.ddc`
5. 点击工具栏的`schematic view`，出现一个电路图窗口，其中显示了`Top`模块和对应的输入输出端口，双击`Top`模块，可以进入下一个层数，看到三个子模块，再双击任意一个子模块，显示了详细的门级电路图。可以通过`zoom in/out`和`Fit`来调整电路图大小。

## 任务4: 设计约束文件输入

1 在终端或者 GUI 的命令窗口输入以下命令：

```sh
source TOP.con
```

确保该命令没有任何 Error 信息。这里的`TOP.con`并没有附带路径信息，是因为`setup`文件中已经将路径附加在 search_path 变量的值列表中，当然也可以带上路径`./scripts/TOP.con`

2 约束脚本将会被导入，但此时在窗口当中看不到约束文件。执行 compile 命令会用到约束文件。

## 任务 5：编译或者映射到供应商指定的门级器件

1 输入以下命令进行编译

```sh
compile_ultra
```

观察 compile 进度的log，可以看到多个优化阶段生成的表格。AREA 列表显示设计尺寸，WORST NEG SLACK 显示违规的临界或最坏的路径数量，TOTAL NEG SLACK 显示所有违约路径的总和。
当优化达到一定程度，或者 slack 总数接近于 0，意味着已经不存在违约路径，compile_ultra 运行结束。

2 参照任务3步骤5，查看综合后的原理图，模块被展开。

## 任务6 生成时序报告并分析时序

1． 输入以下命令生成时序报告

```sh
rc
```

`rc`在`.synopsys_dc.setup`文件当中定义的别名，执行`rc`命令等同于执行`report_constraint -all_violators`命令。该报告简要列出了违反的约束。
也可以通过输入`rt`命令（`rt`是在`.synopsys_dc.setup`文件当中定义的别名，等同于执行`report_timing`命令），得到更详细的时序信息。

2． 输入以下命令生成面积报告

```sh
ra
```

`ra`在`.synopsys_dc.setup`文件当中定义的别名，ra 命令等同于执行`report_area`命令。

3 点击如下按钮，查看各种路径统计直方图

## 任务9保存优化后的设计

1 返回`TOP`的`Schematic`视图，选择file -> Save As，双击 mapped 文件夹，file name 栏输入 TOP.ddc，确保 Save all designsin hierarchy 勾选。最后点 save， Log 窗口出现`write -hierarchy -format ddc -output /home/eda/DC1_2012.06/ab1/mapped/TOP.ddc`表明`.ddc`文件写入成功。

2 点击`History`标签页，点击`Save Contents As`，指定路径并输入`dc.tcl`。

## 任务10 删除所有设计，并退出

1 输入以下命令

```sh
fr
list_designs
```

fr 是在 synopsys_dc.setup 文件中定义的重命名，等同于执行remove_design -designs命令。该命令被执行后，所有设计被删除。
list_designs命令用于列出所有设计。

2 输入以下命令

```sh
h
```

该命令用于将已经执行的 dc_shell 命令自动写入到 command.log。一旦不小心退出
Design Vision，可以复制 command.log 并重命名 command_copy.log，编辑command_copy.log 文件，去除文件当中的“exit"或者"quit”。然后在 unix 终端下执行design_vision -topo -f-command_copylog 恢复到之前的工作状态。
当然也可以通过执行任务9当中保存的 dc.tcl脚本文件恢复工作状态，执行脚本文件需要在 unix 终端中输入 design_vision -topo -f scripts/dc.tcl

3 通过点击 file -> Exit -> OK，或者在命令行输入`exit`退出 Design Vision。

4 尝试`dc_shell`调用GUI，输入如下命令

```sh
dc_shell -topo
start_gui(or gui_start)
```

退出 GUI，输入

```sh
stop_gui(or gui_stop)
```

在 dc_shell 输入 exit 退出 DC

## 任务12 使用 analyze 和 elaborate 读取 HDL文件

1 调用`DC Shell`，并使其工作在`topo`模式。输入如下命令：

```sh
de_shell -topo
```

2 在 dc_shell 环境下读取 verilog 文件

```sh
read_verilog rtl/TOP.v
current_design TOP
link
```

3 使用`analyze/elaborate`读取 HDL 文件，输入以下命令：

```sh
file mkdir work
define_design_lib WORK -path work
analyze -format verilog -library WORK rtl/TOP.v
elaborate TOP
```

4 使用 analyze/elaborate 附加`-vcs`选项读取 HDL 文件，输入以下命令：

```sh
fr ;# Remove all the designs from DC memory
analyze -vcs " -verilog -y ./rtl +libextt.v " \
./rtl/TOP.v
elaborate TOP
```

通过附带`-vcs`命令，DC 可以自动加载指定目录下的子模块文件

## 记录几个逆天报错

Error: Can't communicate with the license server. (SEC-12)

Fatal: Design Compiler is not enabled. (DCSH-1)
