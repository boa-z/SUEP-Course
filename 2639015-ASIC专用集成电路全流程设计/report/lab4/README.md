# 4

## Requirements

lab04的问题：

1. 什么是形式验证？
2. lab4的实验中两个脚本文件用的都是sv文件，自己全部修改成v文件
3. run_G2G.tcl 与 run_R2G.tcl 这两文件有何不同，目的是什么？

## Guide

```sh
cd lab04/fm/

fm_shell
```

在fm_shell中：

```sh
source run_R2G.tcl
exit
```

退出fm_shell后，查看几个文件的内容：

```sh
fm_shell
source run_G2G.tcl
```

## Q&A

### 形式验证

什么是形式验证？

形式验证（Formal Verification）是一种用于验证硬件设计或软件系统是否符合其规格说明的技术，它基于数学证明的方式，确保设计在所有可能的输入情况下都满足预期的行为。与传统的仿真验证不同，形式验证不依赖测试向量或具体输入，而是对设计进行系统性和彻底的检查。

### sv文件

### run_G2G.tcl 与 run_R2G.tcl

run_G2G.tcl 与run_R2G.tcl这两文件有何不同，目的是什么？

run_G2G.tcl

```sh
read_db /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/liberty/1.8v/scc018ug_hd_rvt_ss_v1p62_125c_basic.db
read_verilog -r ../syn/dc/alu.v
set_top top
read_verilog -i ../../lab06/pr/route.v
set_top top
match
verify
```

run_R2G.tcl

```sh
set_svf ../syn/dc/default.svf 
read_db /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/liberty/1.8v/scc018ug_hd_rvt_ss_v1p62_125c_basic.db
read_sverilog -r \
  { ../rtl/sverilog/data_defs.sv \
    ../rtl/sverilog/top.sv \
    ../rtl/sverilog/alu.sv \
    ../rtl/sverilog/arith_alu.sv \
    ../rtl/sverilog/ex_preproc.sv \
    ../rtl/sverilog/shift_alu.sv  }
set_top top
read_verilog -i ../syn/dc/alu.v
set_top top
match
verify
```

`run_G2G.tcl` 和 `run_R2G.tcl` 是两种不同的脚本文件，主要用于不同阶段的验证和设计流程，具体区别如下：

### 1. `run_G2G.tcl` 文件分析

```sh
read_db /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/liberty/1.8v/scc018ug_hd_rvt_ss_v1p62_125c_basic.db
read_verilog -r ../syn/dc/alu.v
set_top top
read_verilog -i ../../lab06/pr/route.v
set_top top
match
verify
```

- **目的**：`run_G2G.tcl` 脚本主要用于**门级网表验证**（Gate-to-Gate，简称 G2G），即在综合后对门级网表与布线信息进行验证。该脚本读取门级网表和布线文件，并通过匹配和验证来确保综合后的门级设计与布线设计一致。

- **详细步骤**：
  - `read_db`: 读取指定库文件（工艺库），包括标准单元信息，时序约束等。
  - `read_verilog -r ../syn/dc/alu.v`: 读取综合后的 Verilog 文件（`alu.v`），这应该是门级网表文件。
  - `set_top top`: 设置顶层模块 `top`。
  - `read_verilog -i ../../lab06/pr/route.v`: 读取布线后的网表，可能是包含物理设计信息的文件。
  - `match`: 在门级网表和布线网表之间进行匹配。
  - `verify`: 验证门级设计和布线设计的一致性。

### 2. `run_R2G.tcl` 文件分析

```sh
set_svf ../syn/dc/default.svf 
read_db /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/liberty/1.8v/scc018ug_hd_rvt_ss_v1p62_125c_basic.db
read_sverilog -r \
  { ../rtl/sverilog/data_defs.sv \
    ../rtl/sverilog/top.sv \
    ../rtl/sverilog/alu.sv \
    ../rtl/sverilog/arith_alu.sv \
    ../rtl/sverilog/ex_preproc.sv \
    ../rtl/sverilog/shift_alu.sv  }
set_top top
read_verilog -i ../syn/dc/alu.v
set_top top
match
verify
```

- **目的**：`run_R2G.tcl` 脚本用于**RTL-to-Gate**（R2G）验证，即在综合前后的 RTL 代码与门级网表之间进行验证，确保 RTL 代码与综合后的门级网表行为一致。这是设计验证流程中的关键步骤，保证综合前后的功能没有发生变化。

- **详细步骤**：
  - `set_svf`: 设置 Scan Verification File (SVF) 文件路径，用于时序扫描测试相关信息。
  - `read_db`: 读取库文件（与 `run_G2G.tcl` 相同）。
  - `read_sverilog`: 读取多个 RTL 代码文件（用 SystemVerilog 编写的模块，包括 `alu.sv`、`arith_alu.sv` 等），这表示正在验证综合前的 RTL 代码。
  - `set_top top`: 设置顶层模块 `top`。
  - `read_verilog -i ../syn/dc/alu.v`: 读取综合后的门级网表文件（`alu.v`）。
  - `match`: 对 RTL 代码和门级网表进行功能和结构匹配。
  - `verify`: 验证 RTL 和综合后的门级网表是否功能一致。

### 主要区别

1. **验证目的不同**：
   - **`run_G2G.tcl`**：用于综合后的门级网表与布线设计的验证，目的是确保门级网表和布线网表在时序和功能上的一致性。
   - **`run_R2G.tcl`**：用于 RTL 代码与综合后的门级网表之间的验证，目的是确保 RTL 代码在综合后功能不发生变化。

2. **读取文件的类型不同**：
   - **`run_G2G.tcl`**：读取的是门级网表和布线网表。
   - **`run_R2G.tcl`**：读取的是 RTL 代码和门级网表。

3. **验证的阶段不同**：
   - **`run_G2G.tcl`**：属于后端验证，通常在布线和物理设计完成后进行。
   - **`run_R2G.tcl`**：属于前端验证，确保综合前后的逻辑一致性。

### 总结

- `run_G2G.tcl` 用于在综合后的门级设计和布线设计之间进行验证，确保它们在物理实现阶段的准确性。
- `run_R2G.tcl` 用于在综合前的 RTL 设计和综合后的门级网表之间进行验证，确保逻辑行为的一致性。

这两个脚本是验证流程中重要的不同阶段，用于保证设计的功能正确性和物理实现的准确性。
