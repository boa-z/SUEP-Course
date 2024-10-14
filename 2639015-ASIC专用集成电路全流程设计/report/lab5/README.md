# ALU设计实验手册  

STA实验手册

---

**文档版本**: Ver3.0  
**最后修改日期**: 2023-07-18  
**修改人**: pdzjl  

---

## 实验简介

通过这次实验，熟悉抽取QRC寄生参数，使用Tempus工具导入时序文件，创建时序路径，设置分析模式和参数，产生时序报告，保存时序数据库，时序修复和产生SDF，掌握STA分析的整个流程。

### 实验目的

1. 掌握QRC寄生参数提取。
2. 掌握数字后端Tempus的使用。

### 实验准备

- 登录实训服务器
- 登录实训服务器需要管理员提供用户名和密码。
- 根据不同的服务器系统，学员可能通过以下途径其中之一来登录实训服务器：
  - 通过VNC Viewer来登录。
  - 通过教学管理平台来登录。
- 具体登录实训服务器的方法，需参照对应的《实训服务器使用手册》。

### 实验目录和数据

使用VNC登录服务器，进入`rc`目录：

- `qrc.cmd`: 运行脚本文件
- `qrc.log`: 日志文件
- `qrc_tech_dir`: RC corner文件
- `qrc_test`: SPEF文件输出路径
- `route.def`: 绕线后输出的物理设计文件
- `techlib.defs`: 对RC techfile宏定义

进入`sta`路径：

- `step.tcl`: 运行Tempus流程的脚本

---

### 实验步骤

#### Lab1 QRC参数提取

1. 在`rc`目录下创建`qrc_tech_dir`目录，准备`corner.defs`文件，内容如下：

    ```sh
    mkdir qrc_tech_dir
    cd qrc_tech_dir
    gvim corner.defs
    ```

2. 在`qrc`目录下创建`techlib.defs`文件，用来定义RC techfile路径:

    ```sh
    vi techlib.defs
    ```

    输入内容如下：

    ```sh
    DEFINE qrc_tech_dir qrc_tech_dir
    ```

3. 在`qrc`目录下创建`qrc.cmd`文件，内容如下：

    \```plaintext
    command content here
    \```

    - 取RC时考虑耦合电容
    - 读取的LEF和DEF文件
    - 指定log文件和输出文件类型
    - 指定layer mapping内容，把Innovus里的层和QRC TechFile里的层对应起来
    - 定义所采用的corner和输出路径

4. 输入命令 `qrc -cmd qrc.cmd` 后即可得到抽取的SPEF文件

    进入`qrc_test`目录查看结果：

#### Lab2 Tempus流程

1. 抽取QRC参数之后，启动Tempus。
2. 在`sta`目录下进行，启动方式: 在terminal键入`tempus -eco`
3. 导入时序文件：
   - 读入时序信息

    ```sh
    read_view_definition ../../lab05/pr/viewDefinition.tcl
    ```

   - 读入网表

    ```sh
    read_verilog ../../lab05/pr/route.v
    ```

   - 指定当前设计

    ```sh
    set_top_module top -ignore_unconnected_cells
    ```

   - 读入RC寄生参数信息

    ```sh
    read_spef -rc_corner typ_25 ../../lab05/qrc_test/ALU.spef
    ```

   - 检查Annotated coverage

    ```sh
    report_annotated_parasitics -list_not_annotated
    ```

   Real nets中的complete nets需要保证 100% coverage

4. 创建时序路径。
5. 设置时序分析模式和参数:
   - CPPR共同路径悲观去除，算delay需要把SI模式打开，设置报告显示几项重要数据。

6. 产生时序报告：
   - 产生时序报告前，先运行`update_timing -full`
   - 产生整体的时序报告，结果存入到`all_summary.rpt`

   打开报告：

   - Setup无违例报告，Hold有两条违例，但只看reg2reg的违例，故该两条可以忽略。

   - 产生Setup的时序报告，结果存入到`late_gba_summary.rpt`

     (无违例)

   - 产生Hold的时序报告，结果存入到`early_gba_summary.rpt`

     (无违例)

   - 产生PBA模式下的时序报告：

     (无违例)

   - 产生DRV违例报告

     (无违例)

   - 产生Noise违例报告

     (无违例)

   - 产生Pulse Width违例报告

     (无违例)

7. 保存Tempus时序数据库。
8. 产生SDF文件，SDF包含了Cell和Net的真实延迟数据。

---

感到手打指令有点难蚌，速搓个脚本，适用于 Tempus 2021.1 版本：

```sh
# step.tcl
# Tempus 2021.1

# 读入时序信息
read_view_definition ../../lab05/pr/viewDefinition.tcl

# 读入网表
read_verilog ../../lab05/pr/route.v

# 指定当前设计
set_top_module top -ignore_unconnected_cells

# 读入RC寄生参数信息
read_spef -rc_corner typ_25 ../../lab05/qrc_test/ALU.spef

# 检查Annotated coverage
report_annotated_parasitics -list_not_annotated
```

内置的脚本： `tempus -eco -f step.tcl`

```sh
read_view_definition ../../lab06/pr/viewDefinition.tcl
read_verilog ../../lab06/pr/route.v
set_top_module top -ignore_undefined_cell
read_spef -rc_corner typ_25 ../../lab07/rc/qrc_test/ALU.spef
report_annotated_parasitics -list_not_annotated

createBasicPathGroups -expand
set_analysis_mode -cppr both
set_analysis_view -setup [all_analysis_views] -hold [all_analysis_views]
set_interactive_constraint_modes [all_constraint_modes -active]
set_propagated_clock [all_clocks]
set_interactive_constraint_modes {}
set_delay_cal_mode -SIAware true
set_global report_timing_format [list delay incr_delay arrival slew load fanout cell pin_location hpin net]a
set_delay_cal_mode -SIAware true

update_timing -full
#report
report_analysis_summary > all_summary.rpt
report_analysis_summary -late -merged_groups > late_gba_summary.rpt
report_analysis_summary -early -merged_groups > early_gba_summary.rpt
#pba
#set_global report_timing_format {delay retime_delay incr_delay retime_incr_delay arrival retime_slew load fanout edge cell pin_location hpin net}
report_timing -late -net -max_slack 0 -max_path 100 -path_group reg2reg -nworst 1 -path_type full_clock -retime_mode exhaustive -retime path_slew_propagation -analysis_summary_file late_gba_summary.rpt > late_pba.rpt
report_timing -early -net -max_slack 0 -max_path 100 -path_group reg2reg -nworst 1 -path_type full_clock -retime_mode exhaustive -retime path_slew_propagation -analysis_summary_file early_gba_summary.rpt > early_pba.rpt
#drv
report_constraint -drv_violation_type {max_capacitance max_transition} -all_violators > slew_cap.rpt
#noise
set_si_mode -enable_delay_report true
set_si_mode -enable_glitch_report true
update_timing -full
report_noise -failure -format {peak level victim_total_cap victim_total_area victim_width victim_vdd victim_net receiver_input_failure_threshold receiver_output_peak receiver_output_failure_threshold receiver_input_pin receiver_cell attacker_source attacker_peak attacker_offset attacker_slew attacker_xcap attacker_vdd attacker_edge attacker_status attacker_net stage_info} -sort_by noise -style extended -txtfile noise.rpt
#min_pulse_width
report_min_pulse_width -path_type summary -violation_only > min_pulse_width.rpt
```
