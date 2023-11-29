# VCS图形化仿真调试模式实验

VCS graphical simulation debugging mode

（2个课时）

实验目的：

1. 熟悉使用 VCS 工具的使用方法，包括 GUI 界面
2. 熟悉使用 Makefile 脚本使用 VCS 工具进行编译和仿真
3. 熟悉 Verdi 与逻辑仿真工具 VCS 的联合仿真的方法：Dump FSDB 波形文件
4. 熟悉 Verdi 的各种基本操作

实验准备：

```sh
cd /qixin/public/verdi_lab
```

包含如下文件：

```text
adder32.v
adder_tb_random.v
Makefile
rtl.f
tb.f
```

将verdi_lab拷贝到自己的目录中，完成下述实验。

实验步骤：

1. 打开pdf文件：019-Debug工具Verdi01 - Dump FSDB波形文件
按照要求修改对应文件中 TODO task （有四处）
修改完后截图写入实验报告中。
2. 打开pdf文件：020-Debug工具Verdi02 - Verdi基本操作
按照步骤完成该PDF文件中的任务，运行结果截图写入报告中。

## 019-Debug工具Verdi01

寻找 Verdi 提供的库文件

```sh
which verdi
###
which vcs
```

编辑目录下的Makefile

```makefile
# TODO task 1:
# NOVAS_INST_DIR=/qixin/eda/synopsys/verdi/2018.09
# In new version of verdi,
NOVAS_INST_DIR=/qixin/eda/synopsys_2021/verdi/S-2021.09
PLATFORM=LINUX64
TOOL=VCS
# ...
# TODO task 2:
compile:
    vcs -timescale=1ns/1ps -debug_all $(DUT) $(TB) -l com_$(SEED).log \
    -P ${NOVAS_INST_DIR}/share/PLI/${TOOL}/${PLATFORM}/novas.tab \
    ${NOVAS_INST_DIR}/share/PLI/${TOOL}/${PLATFORM}/pli.a
# ...
# TODO task 4:s
verdi_fsdb:
    cat rtl.f > all.f
    cat tb.f >> all.f
    verdi -f all.f -ssf adder32.fsdb
```

adder32_tb_random.v

```verilog
// TODO task 3: dump FSDB
initial begin
    $fsdbDumpfile("adder32.fsdb") ;
    $fsdbDumpvars(0, adder32_tb_random, "+all");
end
```

先执行命令 `make` 编译

启动 verdi 执行命令 `make verdi_fsdb`

## 020-Debug工具Verdi02

详见`课件/020-Debug工具Verdi02 - Verdi基本操作.pdf`
