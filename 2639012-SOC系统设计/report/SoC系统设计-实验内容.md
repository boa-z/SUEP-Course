# soclib

## 课程大作业

### 课程设计任务一（15.1.4）

[第十五章-课程设计_(2)——实验1_电子工业出版社_魏老师](https://www.hxedu.com.cn/hxedu/w/inputVideo.do?qid=5a79a0187fd903cc01801cd94a793367)

---

实现该平台的顶层文件`top.cpp`位于`/projet_soc/TP/TP0/HW`。
要仔细阅读该顶层文件`top.cpp`，了解如何通过该文件利用SoCLib所提供的各种ESL模型组件搭建SoC验证平台，如何定义声明各种设备模块以及各设备模块之间如何连接。

实验步骤2：构建目标SoC平台

基于SoCLib添加各个设备模块时，应重点检查以下几个方面：
    1. 设备模块与各种信号的声明是否正确？
    2. 设备模块的初始化及各种参数的设置是否正确？
    3. 各设备模块与互连网络及模块间信号的连接是否正确？
    4. 各设备模块的内存映射（Memory Mapping）地址的设置是否正确？
    5. 与互连网络连接的主设备、从设备数目设置是否正确？

实验步骤3：
编写简单的C语言程序，控制所添加的各种设备模块的功能，以验证SoC系统各设备工作的正确性。

实验步骤 4：
对位于 `/projet_soc/TP/TP0/SW/mjpeg_seq` 文件夹下的 MJPEG 串行程序使用 MIPS 交叉编译器进行编译，移植到所构建的单核 SoCLib 平台之上。

实验步骤5：
熟悉MJEPG的算法流程，思考该算法任务的并行性，通过仿真统计各子程序所用的时间，考虑如何进行系统结构改进及软硬件划分。建议利用TIMER模块，统计MJPEG串行程序每部分在MIPS3000上运行所需要的时间。

#### 2.1

对照 `/projet_soc/TP/TP0` 和 `/projet_soc/TP/TP0_CORRECTION` 里面的如下个文件，并将`/projet_soc/TP/TP0`中的这6个文件中与`/projet_soc/TP/TP0_CORRECTION`中的这个6个文件不同的地方改成跟 `/projet_soc/TP/TP0_CORRECTION中` 的这6个文件相同的形式：
  
`/projet_soc/TP/TP0/HW/` 里面的个文件：

#### 2.2 top.cpp

以下仅描述添加或修改的部分代码

```cpp
#include "vci_locks.h"
#include "vci_timer.h"
#include "vci_fd_access.h"
#include "vci_framebuffer.h"

// ...

#define FBUFFER_WIDTH 256
#define FBUFFER_HEIGHT 144

// ...

// Caches must be first, because of the cache coherency communications 
// with the memory 
maptab.add(Segment("cache0", CACHE0_BASE , CACHE0_SIZE , IntTab(0), false));
maptab.add(Segment("reset", RESET_BASE, RESET_SIZE, IntTab(1), true));
maptab.add(Segment("excep", EXCEP_BASE, EXCEP_SIZE, IntTab(1), true));
maptab.add(Segment("text" , TEXT_BASE , TEXT_SIZE , IntTab(1), true));
maptab.add(Segment("data" , DATA_BASE , DATA_SIZE , IntTab(1), true));
maptab.add(Segment("tty"  , TTY_BASE  , TTY_SIZE  , IntTab(2), false));
maptab.add(Segment("semlocks_seg", SEMLOCKS_BASE, SEMLOCKS_SIZE, IntTab(3), false));
maptab.add(Segment("timer", TIMER_BASE, TIMER_SIZE, IntTab(4), false));
maptab.add(Segment("fd_access", FD_ACCESS_BASE, FD_ACCESS_SIZE, IntTab(5), false));
maptab.add(Segment("frame_buffer", FBUFFER_BASE, FBUFFER_SIZE, IntTab(6), false));

// ...

// VCI Interconnect
soclib::caba::VciVgmn<vci_param> vgmn("vgmn",maptab, 3, 7, 2, 8);

// ...

// Peripherals
soclib::caba::VciMultiTty<vci_param> vcitty("vcitty",IntTab(2), maptab, "vcitty0", NULL);
soclib::caba::VciLocks<vci_param> semlocks("semlocks", IntTab(3), maptab);
soclib::caba::VciTimer<vci_param> timer("timer", IntTab(4), maptab, 1);
soclib::caba::VciFdAccess<vci_param> fd_access("fdaccess", maptab, IntTab(2), IntTab(5));
soclib::caba::VciFrameBuffer<vci_param> fbuffer("fbuffer", IntTab(6), maptab, FBUFFER_WIDTH, FBUFFER_HEIGHT);

// ...
soclib::caba::VciSignals<vci_param> signal_vci_fd_access("signal_vci_fd_access");
soclib::caba::VciSignals<vci_param> signal_vci_inv_fd_access("signal_vci_inv_fd_access");
sc_signal<bool> signal_fd_access_it("signal_fd_access_it");
```

#### 2.3 segmentation.h

```cpp
#define DATA_BASE 0x20000000
#define DATA_SIZE 0x01000000

// ...

#define SEMLOCKS_BASE 0xC1000000
#define SEMLOCKS_SIZE 0x00000400 // 256 locks

#define TIMER_BASE 0xC2000000
#define TIMER_SIZE 0x00000100  // 1 seul timer

#define FD_ACCESS_BASE 0xC3000000 
#define FD_ACCESS_SIZE 0x00001000


#define FBUFFER_BASE 0xC4000000
#define FBUFFER_SIZE 0x01000000
```

#### 2.4 platform_desc

添加如下内容：

```text
Uses('vci_timer'),
Uses('vci_fd_access'),
Uses('vci_framebuffer'),
Uses('vci_locks'),
```

#### ex15_1_4 SW

`/projet_soc/TP/TP0/SW/mjpeg_seq/headers/` 里面的文件：

1. `fetch.h` 改目录：

```cpp
movie=fopen("/fd/home/vlsi/Programfiles/projet_soc/TP/TP0/SW/mjpeg_seq/images/ice_age256x144_144.mjpeg","r")
```

---

`/projet_soc/TP/TP0/SW/mjpeg_seq/sources/` 里面的个文件：

1. dispatch.c

```cpp
volatile unsigned long int * timer = (unsigned long int *)0xC2000000;

// ...

if (LB_X == 0) {
  LB_Y = (LB_Y + YV) % NB_MCU_Y;
  if (LB_Y == 0) memcpy ((void *) 0xC4000000, picture, SOF_section . width * SOF_section . height * 2);
}
```

---

`/projet_soc/TP/TP0/SW/mjpeg_seq/ldscripts/` 里面的文件：

1. mips

修改以下内容：

```text
.semram 0xC1000000 : { }

// ...

PLATFORM_CLOCK_BASE = .; LONG(0xC2000000)

// ...
__BRIDGEFS_DEVICES = .; LONG(0XC3000000)
```

---

编译仿真：268页（3）编译仿真步骤1-5.

实验文件结构示意如下：

```text
T0
|-----HW
|     |----all.mk
|     |----Makefile
|     |----platform_desc
|     |----segmentation.h
|     |----top.cpp
|
|-----SW---mjpeg_seq
               |
```

（1）top.cpp:

（2）segmentation.h
（3）platform_desc
（4）dispatch.c
（5）mips

P263:

#### ex15_1_4 Debug

邪恶报错

```text
/home/vlsi/Programfiles/projet soc/PLATFORM/HW PLATFORM/SoCLib/soclib/module/internal_component/vci_coherent_xcache/caba/source/src/vci_coherent_xcache.cpp: 1081: void soclib::caba::VciCoherentxCacheDirWt<vci param:: transition() [with vci_param = soclib:: caba: :VciParams<4, 1, 32, 1, 1, 1, 8, 1, 1, 1>]: As sertion `m_segment.contains (dr_inv_address)' failed.
```

#### ex15_1_4.sh

简化版

```sh
cd /home/vlsi/Programfiles/projet_soc/TP/TP0_CORRECTION/SW/mjpeg_seq
source install.sh configurations/mips
make
cd /home/vlsi/Programfiles/projet_soc/TP/TP0_CORRECTION/HW
make
ln -s ../SW/mjpeg_seq/APP.x
./simulation.x -1
```

完整版

```sh
#!/bin/bash

# 编译仿真
echo "编译仿真，是否继续？ [y/N]"

# 设置环境变量
cd /home/vlsi/Programfiles/projet_soc/TP
echo "设置环境变量，是否继续？ [y/N]"
read -p "" env_confirm
if [ "$env_confirm" = "y" ]; then
  source install_env.sh
else
  echo "设置环境变量操作中止。"
  exit 1
fi

# 编译软件
cd /home/vlsi/Programfiles/projet_soc/TP/TP0/SW/mjpeg_seq
echo "编译软件，是否继续？ [y/N]"
read -p "" compile_sw_confirm
if [ "$compile_sw_confirm" = "y" ]; then
  source install.sh configurations/mips
  make
else
  echo "编译软件操作中止。"
  exit 1
fi

# 编译硬件
cd /home/vlsi/Programfiles/projet_soc/TP/TP0/HW
echo "编译硬件，是否继续？ [y/N]"
read -p "" compile_hw_confirm
if [ "$compile_hw_confirm" = "y" ]; then
  make
else
  echo "编译硬件操作中止。"
  exit 1
fi

# 创建软链接
ln -s ../SW/mjpeg_seq/APP.x APP.x
echo "创建软链接完成。"

# 运行仿真
./simulation.x -1
echo "仿真完成。"
```

### 课程设计任务二（15.1.5）

[第十五章-课程设计_(3)——实验2_电子工业出版社_魏继增](https://www.hxedu.com.cn/hxedu/w/inputVideo.do?qid=5a79a0187fd903cc01801cd94aa03368)

15.1.5 顺利完成编译仿真的办法：

1. 将`projet_soc/TP/TP0_CORRECTION`里面的HW文件夹复制到`projet_soc/TP/TP1`中。
2. 复制好后，删去`projet_soc/TP/TP1/HW/`里面的`soclib_build`这个文件夹。
3. 认真观看上面这个视频（在我前面发给大家的10G左右的obsidian包里面，也可以通过扫描书上269页的二维码观看），按照视频中的要求进行 `projet_soc/TP/TP1` 里面的代码的更新。
4. 打开Terminal，进入 `projet_soc/TP` 文件夹，输入 `source install_env.h` 设置系统环境变量。
5. 进入 `projet_soc/TP/TP1/SW/mjpeg_mpro` 文件夹，输入 `source install.sh configurations/mips` 运行脚本，然后输入 `make` 对软件部分进行编译。
6. 进入 `projet_soc/TP/TP1/HW/` 文件夹，输入 `make` 对硬件部分进行编译。
7. 在 `projet_soc/TP/TP1/HW/` 文件夹下，输入 `ln -s ../SW/mjpeg_mpro/APP.x` ，回车，接着输入`./simulation.x -1`，会在几分钟内显示测试图片。
编译仿真：268页（3）编译仿真步骤1-5。

#### ex15_1_5 HW

top.cpp

```cpp
// NMSL
```

#### ex15_1_5 SW

修改 `SW/mjpeg_mpro/ldsripts/mips`

```text
.semram -- TODO : addr of the vcilock component -- : { } // Before
.semram 0xC1000000 : { }

; PLATFORM_N_MIPSR3000 = .; LONG(-- TODO : number of processors --) // Before
PLATFORM_N_MIPSR3000 = .; LONG(0x2)
; PLATFORM_CLOCK_BASE = .; LONG(-- TODO : addr of the timer --) // Before
PLATFORM_CLOCK_BASE = .; LONG(0xC2000000)

SOCLIB_TTY_NDEV = .; LONG(-- TODO : number of TTY, MUST be in accordance with the parameters of the vcitty in top.cpp --) // Before
SOCLIB_TTY_NDEV = .; LONG(0x1)
SOCLIB_TTY_DEVICES = .; LONG(-- TODO : Addresses must be incremented by 16 , ex : 0XC0200000) LONG(0XC0200010) // Before
SOCLIB_TTY_DEVICES = .; LONG(0xC0200000)

__BRIDGEFS_DEVICES = .; LONG(-- TODO : addr --) // Before
__BRIDGEFS_DEVICES = .; LONG(0xC3000000)
```

#### ex15_1_5.sh

将以上步骤中设置系统环境变量和编译部分整理为脚本

```sh
#!/bin/bash

# 复制文件夹，如果文件夹存在则删除
echo "复制文件夹，是否继续？ [y/N]"
read -p "" copy_confirm
if [ "$copy_confirm" = "y" ]; then
  if [ -d /home/vlsi/Programfiles/projet_soc/TP/TP1/HW ]; then
    rm -rf /home/vlsi/Programfiles/projet_soc/TP/TP1/HW
  fi
  cp -r /home/vlsi/Programfiles/projet_soc/TP/TP0_CORRECTION/HW /home/vlsi/Programfiles/projet_soc/TP/TP1
else
  echo "复制文件夹操作中止。"
  exit 1
fi

# 设置环境变量
cd /home/vlsi/Programfiles/projet_soc/TP
echo "设置环境变量，是否继续？ [y/N]"
read -p "" env_confirm
if [ "$env_confirm" = "y" ]; then
  source install_env.sh
else
  echo "设置环境变量操作中止。"
  exit 1
fi

# 编译软件
cd /home/vlsi/Programfiles/projet_soc/TP/TP1/SW/mjpeg_mpro
echo "编译软件，是否继续？ [y/N]"
read -p "" compile_sw_confirm
if [ "$compile_sw_confirm" = "y" ]; then
  source install.sh configurations/mips
  make
else
  echo "编译软件操作中止。"
  exit 1
fi

# 编译硬件
cd /home/vlsi/Programfiles/projet_soc/TP/TP1/HW
echo "编译硬件，是否继续？ [y/N]"
read -p "" compile_hw_confirm
if [ "$compile_hw_confirm" = "y" ]; then
  make
else
  echo "编译硬件操作中止。"
  exit 1
fi

# 创建软链接
ln -s ../SW/mjpeg_mpro/APP.x APP.x
echo "创建软链接完成。"

# 运行仿真
./simulation.x -1
echo "仿真完成。"
```
