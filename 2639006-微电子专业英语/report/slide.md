---
marp: true
size: 16:9
theme: am_blue
math: katex
paginate: true
headingDivider: [2,3]
footer: \ *上海电力大学* *2023年11月27日*
---

<!-- _class: cover_a
<!-- _header: "" -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

# Hardware implementation of spiking neural networks on FPGA

报告人：
学号：

<!-- "Hello, everyone. Today I am going to present my paper on an FPGA-based SNN hardware implementation with a hybrid updating algorithm." 

“大家好。今天我将介绍我的论文，该论文是关于基于 FPGA 的 SNN 硬件实现和混合更新算法。”
-->

## TOC

<!-- _class: cols2_ol_ci fglass toc_a  -->
<!-- _footer: "" -->
<!-- _header: "CONTENTS" -->
<!-- _paginate: "" -->

- [Introduction](#3)
- [Background](#4)
- [Hybrid updating algorithm](#7)
- [System architecture](#10)
- [Evaluation](#14)
- [Discussion](#19)
- [References](#21)

## Introduction

<!-- SNNs are a type of artificial neural networks that mimic the behavior of biological neurons and synapses. They have many advantages over conventional ANNs, such as low power consumption, high fault tolerance.

However, SNNs also pose many challenges for hardware implementation, such as high memory bandwidth demand, complex computation, and irregular data access. In this paper, we propose a novel FPGA-based SNN hardware module that addresses these challenges with a hybrid updating algorithm and an efficient system architecture. 

SNN 是一种模仿生物神经元和突触行为的人工神经网络。 与传统的人工神经网络相比，它们具有许多优点，例如低功耗、高容错性和高生物学合理性。

然而，SNN 也给硬件实现带来了许多挑战，例如高内存带宽需求、复杂的计算和不规则的数据访问。 在本文中，我们提出了一种新颖的基于 FPGA 的 SNN 硬件模块，该模块通过混合更新算法和高效的系统架构来解决这些挑战。 -->

SNNs are a type of artificial neural networks that mimic the behavior of biological neurons and synapses.

advantages:

- low power consumption
- high fault tolerance

challenges:

- high memory bandwidth demand
- complex computation
- irregular data access

=> A FPGA-based SNN hardware module

## Background

<!-- _class: trans -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

### What is SNN?

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

Spiking neural networks

<div class="ldiv">
SNN 由神经元构建，神经元与加权突触连接以形成层和网络。作为 SNN 的基本构建块，每个尖峰神经元都维护一个代表其当前状态的值。这些神经元的输入是通过突触传输的尖峰。神经元收集这些输入尖峰并整合相应的权重以更新其内部状态。每当状态达到某个阈值时，神经元就会被激活并向其后继神经元输出一个尖峰。经过预先配置的传播延迟后，后继者会收到尖峰并相应地更新其状态。

本文使用的神经元模型 ==> **LIF neuron model**
</div>

<div class="rdiv">

![#center](https://wulixb.iphy.ac.cn/fileWLXB/journal/article/wlxb/2022/14/PIC/14-20220281-4.jpg)

(a) 全连接脉冲神经网络; (b) 基于突触可塑性(脉冲时间依赖可塑性(STDP)和脉冲频率依赖可塑性(SRDP))来训练网络, 修改突触权重; c)卷积脉冲神经网络, 由卷积层、池化层和全连接层组成
</div>

### What is LIF neuron model?

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

The leaky integrate-and-fire neuron model

<div class="ldiv">

<!-- 最常用的神经元模型之一是泄漏积分与激发 (LIF) 模型。LIF 神经元受到生物神经元中泄漏的膜电压的启发，如果不存在输入尖峰，它们的状态会随着时间的推移而降低。 -->

<!-- One of the most commonly used neuron models is the leaky integration and firing (LIF) model. -->
LIF neurons are inspired by the leaky membrane voltage found in biological neurons, whose state decreases over time in the absence of input spikes. It simulates the membrane voltage leaking of biological neurons with an exponential process
</div>

<div class="rdiv">
![#center](https://i2.wp.com/img-blog.csdnimg.cn/20200602101502247.png)
</div>

<!-- ### Literature review and motivation

<!-- _class: fixedtitleA -->

<!-- 文献综述和动机 -->

<!-- "Previous works on hardware implementation of SNNs can be divided into three categories: digital, analog, and mixed-signal designs. Some representative examples are: TrueNorth chip , SpiNNaker system , BlueHive system , and Minituar system ."

"Previous works on network model of SNNs have proposed methods to convert DBNs, FCNs, and CNNs to SNNs with minimal accuracy loss. Some representative examples are: spiking DBN , weight and threshold balancing scheme , and network pruning ."

"The goal of this paper is to design and evaluate an FPGA-based SNN hardware module that can process large-scale SNN models with high performance and low power consumption. We propose a hybrid updating algorithm that combines the advantages of time-stepped and event-driven algorithms, and an efficient system architecture that exploits the parallelism and layered structure of SNNs." -->

<!-- “之前关于 SNN 硬件实现的工作可以分为三类：数字、模拟和混合信号设计。一些代表性的例子有：TrueNorth 芯片、SpiNNaker 系统、BlueHive 系统和 Minituar 系统。”

“之前关于 SNN 网络模型的工作已经提出了将 DBN、FCN 和 CNN 转换为 SNN 的方法，并且精度损失最小。一些代表性的例子包括：尖峰 DBN、权重和阈值平衡方案以及网络剪枝。”

“本文的目标是设计和评估基于 FPGA 的 SNN 硬件模块，该模块能够以高性能和低功耗处理大规模 SNN 模型。我们提出了一种结合了时间步长和事件的优点的混合更新算法 驱动的算法，以及利用 SNN 的并行性和分层结构的高效系统架构。” -->

<!-- Previous works on hardware implementation of SNNs:

- digital
- analog
- mixed-signal designs

convert DBNs, FCNs, and CNNs to SNNs

- spiking DBN
- weight and threshold balancing scheme
- network pruning

=> a hybrid updating algorithm that combines the advantages of **time-stepped** and **event-driven algorithms**, and an efficient system architecture that exploits the **parallelism** and **layered structure** of SNNs. -->

## Hybrid updating algorithm

<!-- _class: trans -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

<!-- 混合更新算法 -->

### principle and steps -- existing

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->
<!-- _class:  bq-purple -->

<!-- 原理及步骤 -->

<!-- 在脉冲神经网络（SNN）中，更新算法的作用是调整神经元之间的连接权重，以便适应特定任务或输入模式。这些算法主要用于训练网络，使其能够学习并提高在给定任务上的性能。

In a spiking neural network (SNN), the role of the update algorithm is to adjust the connection weights between neurons to adapt to a specific task or input pattern. These algorithms are primarily used to train a network so that it can learn and improve its performance on a given task.
-->

<div class=ldiv>

<!-- 根据离散时间步长处理所有神经元。在每个时间步内，每个神经元的状态都会被更新和检查，以确定它是否输出尖峰。有关这些尖峰的信息被存储起来，以便根据它们的传输延迟在未来的时间步中使用。
该算法可能会浪费计算资源，因为它为不接收任何输入尖峰的神经元安排不必要的操作。 -->

> time-stepped algorithm
>
> Processes all of the neurons based on discrete time steps.
> Within each time step, the state of each neuron is updated and checked to decide whether it outputs a spike. Information about these spikes is stored for use in future time steps according to their transmission delay

waste computing resources
</div>

<div class=rdiv>

<!-- 仅处理神经元的激活事件。事件队列用于存储事件，并按事件时间戳排序。每个事件从事件队列中出队后，仅更新连续神经元的状态，从而生成新事件。
尽管事件驱动算法可能很高效，但事件队列的硬件实现很复杂，因为每当有新事件入队时就需要对事件进行排序。 -->

> event-driven algorithm
>
> processes only the activation events of neurons
> An event queue is used as storage for the events, and is sorted by the event timestamps. After each event dequeues from the event queue, only the states of successive neurons are updated, thereby generating new events.

the hardware implementation of the event queue is complicated
</div>

### principle and steps -- Hybrid

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<div class=ldiv>

<!-- 我们使用多个事件队列，每个事件队列都标有时间戳 $Q_n$（其中 n 范围从 $0$ 到 $D-1$，其中 $D $是允许的最大延迟），存储从当前时间开始n个时间步后要处理的事件。 
这样，具有相同时间戳的事件就可以存储在同一个队列中，而无需进行排序操作。 为了管理这些事件队列，需要全局维护时间步长。 
在每个时间步，带有标记 $Q_0$ 的事件队列被设置为活动队列，并处理其事件。 一旦事件队列为空，当前时间步就结束。 
在下一个时间步之前，所有事件队列的标签减一，使得 $Q_1 - Q_{D-1}$ 变为 $Q_0 - Q_{D-2}$ 并且 $Q_0$ 以循环方式重用： $Q_{D-1}$ 。 
这种混合更新算法避免了排序操作，从而减少了系统的运行时延迟。

combine the time-stepped and eventdriven algorithm -->

We use multiple event queues, each of which is tagged with timestamp $Q_n$ (where n ranges from $0$ to $D-1$ where $D$ is the maximum delay allowed), to store the events to be processed after n time steps from the current time.
<!-- In this way, events with the same timestamp can be stored in the same queue with no sorting operation required.
To manage these event queues, time steps are maintained globally. -->
At each time step, the event queue with tag $Q_0$ is set to be the active queue and its events are processed.
Once an event queue is empty, the current time step finishes.
Before the next time step, the tags of all event queues decrease by one, such that $Q_1 - Q_{D-1}$ becomes $Q_0 - Q_{D-2}$ and $Q_0$ is reused in a circular manner as $Q_{D-1}$ .
<!-- Sorting operations are avoided in this hybrid updating algorithm, which reduces the system’s run-time latency. -->

</div>

<div class=rdiv>

![#center](http://report-temp.test.upcdn.net/Algorithm1.png)
</div>

## System architecture

<!-- _class: trans -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

### The architecture of the proposed module

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<!-- 内存组件 -->

<!-- 您可以介绍系统的四个内存组件：事件队列、权重内存、状态内存和延迟内存，以及它们的作用和功能。 您可以解释他们如何存储和访问混合更新算法和 SNN 模型的数据。
- 您可以使用一些图表或表格来显示您的内存组件的结构和数据格式，例如： -->

<div class=ldiv>

four main memory components:

- the event queues submodule <!-- the hardware implementation of the multiple event queues described above in Section 4.1 -->
- The event controller submodule <!-- in charge of managing these event queues by enqueuing generated events and dequeuing events for processing.-->
- The weight memory and state memory submodules <!-- used to store weight and state data, respectively. The weight memory submodule is read-only, while the state controller also controls the writing back of updated states from the state updater. -->
- the Delay memory submodule <!-- read-only and stores the delay values of different events. -->

</div>

<div class=rdiv>

![#center](http://report-temp.test.upcdn.net/Fig1.jpg)

The architecture of the proposed module
</div>

### state updater

<!-- _class: fixedtitleA -->

<!-- 状态更新器 -->

<!-- 状态更新器执行计算的主体。
它首先衰减神经元状态，然后对输入权重求和以更新神经元状态。
然后执行神经元激活检查以确定是否生成新事件。
如果任何神经元被激活，其神经元状态将重置为预定常数。
状态更新器可以通过同时更新多个神经元状态来利用 SNN 的并行性。
SNN的分层结构保证了神经元的后继者彼此独立，这使得同步更新成为可能。 -->

The state updater carries out the main body of computation.
It first decays the neuron states and then sums the incoming weights to update the neuron states.
Checks for neuron activation are then carried out to decide whether a new event is generated.
If any neuron is activated, its neuron state is reset to a predetermined constant.
The state updater can exploit the parallelism of SNN by updating multiple neuron states at the same time.
The layered structure of SNN ensures that the successors of a neuron are independent of each other, which makes simultaneous updating possible.

### The execution flow of the system

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<!-- 系统的执行流程 -->

<div class=ldiv>

![#center](http://report-temp.test.upcdn.net/Fig1.jpg)
</div>

<div class=rdiv>

<!-- 事件控制器从系统控制器（为了清楚起见，在图1中省略了）接收控制信号和当前时间步长的值。
然后，它将当前事件队列设置为活动状态，并依次从中读取事件。
事件数据被发送到权重控制器和状态控制器。
他们使用事件数据访问权重和状态存储器，然后将它们发送到状态更新器。 -->

The event controller receives controlling signals and values of the current time step from the system controller.
It then sets the current event queue to be active and sequentially reads events from it.
The event data is sent to the weight controller and the state controller.
They access the weight and state memory with the event data and then send them to the state updater.
</div>

## Evaluation

<!-- _class: trans -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

### Benchmark

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<div class=ldiv>

![#center](http://report-temp.test.upcdn.net/Fig2.jpg)

Topology of the benchmark SNN model
</div>

<div class=rdiv>

a feed-forward SNN with two hidden layers

task --> MNIST handwritten digit dataset

<!-- 我们将具有两个隐藏层的前馈 SNN 应用于 MNIST 手写数字数据集的分类任务，以评估所提出的模块。
They apply a feedforward SNN with two hidden layers to the classification task of the MNIST handwritten digits dataset to evaluate the proposed module. -->

input layer: 784 neurons --> 28$\times$28 pixel digit figure
2* hidden layers: 1024 neurons
output layer: 10 neurons --> 10 classes

<!-- The layers are fully connected, which means the connections are all-to-all between two adjacent layers. 

输入层包括 784 个神经元，用于处理从 28$\times$28 像素数字转换而来的输入尖峰。
两个隐藏层都有1024个神经元，而输出层有10个神经元，对应数字0-9的分类结果。
这些层是完全连接的，这意味着两个相邻层之间的连接是全对全的。

本文重点讨论SNN的硬件实现，并使用基准测试来衡量系统性能。
尽管模型的深度（即层数）有限，但它尽可能地占用了每层的扇入/扇出。
所提出的模块根据事件更新神经元状态，每个事件的更新操作和内存访问取决于扇入/扇出。
因此，正如下面5.4节分析的那样，用这个基准测试测得的系统性能接近理论上限。
下面第 5.3 节中报告的分类精度也证明了所提出模块的功能正确性。-->
</div>

### Test platform

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<div class=ldiv>

Xilinx ZC706 evaluation board with a XC7Z045 SoC
1 GB DDR3 memory and two ARM Cortex-A9 MPCore
runs at 200 MHz
<!-- One of the ARM processors is employed to configure the internal registers of the proposed module and manage the data movement. The weight data are stored in the DDR3 memory as described above. -->
These three parts are connected through an on-chip Advanced eXtensible Interface (AXI) bus
</div>

<div class=rdiv>

![#center](http://report-temp.test.upcdn.net/Fig1.jpg)
</div>

### accuracy

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<div class=ldiv>

<!-- The classification accuracy is  -->
Tested on the MNIST test dataset.
The model is trained with the weight and threshold balancing scheme with MATLAB, using 32-bit ﬂoating-point numbers.

training results: 98.48%.
<!-- The trained weights are turned into 16-bit fixed-point numbers and deployed on the proposed module. -->
on-board test: 97.06%.
accuracy loss: 1.42%
<!-- caused by the conversion from ﬂoating-point to 16-bit fixed-point numbers -->
</div>

<div class=rdiv>

![#center](https://pic2.zhimg.com/80/v2-cce911bfc07122933346535e97d341ad_1440w.webp)
</div>

### performance and comparison

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<!-- 性能与比较 -->

<!--
- 您可以介绍您的性能评估和结果，以及如何在 MNIST 数据集上测量系统的吞吐量和功耗。 您还可以将您的性能结果与理论上限和其他基于 FPGA 的 SNN 系统进行比较。
- 您可以使用一些图表或图片来展示您的表现结果和比较，例如： -->

<div class=ldiv>

![#center](http://report-temp.test.upcdn.net/Fig4.png)

Power consumption breakdown. (功耗细分)
</div>

<div class=rdiv>

the maximum performance of the system is $8 \times 10^5$ events per second
</div>

### comparison with GPU and analysis

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<!-- 与GPU的比较与分析 -->

<div class=ldiv>

<!-- 
For comparison, the same SNN model is implemented with the PyTorch [18] framework to run on an NVIDIA Tesla P100 GPU [19] .
Note that GPUs are not suitable for event-driven updating, so we implement the timestepped updating algorithm instead.
Again, we measure the execution time of the 10 000 frames of the MNIST test dataset.
The runtime power during GPU execution is measured with the NVIDIA System Management Interface [20] .

The processing time on a GPU is 7.96 s and the average power consumption is 29.6 W.
Therefore, although the proposed module demands more execution time, it consumes much less power than a GPU.
This equates to much greater power efficiency: 337.6 frames per second per watt compared to 42.2 frames per second per watt on a GPU.
These results imply that the proposed design is suitable for application scenarios that have strict constraints on power consumption and a tolerance for execution latency.

为了进行比较，相同的 SNN 模型是使用 PyTorch [18] 框架实现的，并在 NVIDIA Tesla P100 GPU [19] 上运行。
请注意，GPU 不适合事件驱动的更新，因此我们改为实现时间步进更新算法。 
我们再次测量 MNIST 测试数据集 10000 帧的执行时间。 
GPU 执行期间的运行时功率通过 NVIDIA 系统管理接口 [20] 进行测量。

GPU 上的处理时间为 7.96 秒，平均功耗为 29.6 W。
因此，虽然所提出的模块需要更多的执行时间，但它的功耗比 GPU 少得多。 
这相当于更高的能效：每瓦每秒 337.6 帧，而 GPU 上每瓦每秒 42.2 帧。 
这些结果意味着所提出的设计适用于对功耗和执行延迟有严格限制的应用场景。 -->

This shows the runtime and power consumption of the system and GPU on the same SNN model and dataset, and highlights the trade-off between speed and power efficiency.

The processing time on a GPU is 7.96 s and the average power consumption is 29.6 W.

=> much greater power efficiency: 337.6 frames per second per watt compared to 42.2 frames per second per watt on a GPU.
</div>

<div class=rdiv>

![#center](http://report-temp.test.upcdn.net/compare_with_gpu.png)
</div>

<!-- ## Discussion

<!-- _class: trans -->
<!-- _footer: "" -->
<!-- _paginate: "" -->

<!-- ### optimization opportunities and techniques -->

<!-- _class: fixedtitleA -->
<!-- _class: cols-2 -->

<!-- - You can discuss the further optimization opportunities and techniques for your SNN implementation, such as lowering the weight bit-widths and pruning network connections. You can explain the impact of these techniques on the accuracy and performance of your system, and the design space exploration for future work.
- You can use some charts or pictures to show the optimization opportunities and techniques, such as:

- 您可以讨论 SNN 实现的进一步优化机会和技术，例如降低权重位宽和修剪网络连接。 您可以解释这些技术对系统准确性和性能的影响，以及未来工作的设计空间探索。
- 您可以使用一些图表或图片来展示优化机会和技巧，例如： -->

<!-- <-- <div class=ldiv>

the classification accuracy with lower bit-widths

![#center](http://report-temp.test.upcdn.net/Fig5.png)

Classification accuracy vs. bit-widths on MNIST.
</div>

<div class=rdiv>

the impact of network pruning

![#center](http://report-temp.test.upcdn.net/Fig6.png)

Classiﬁcation accuracy vs. sparsity on MNIST.
</div> -->

## Questions

<!-- _class: fixedtitleA -->

<!-- 问题，请安排内鬼 -->

SNN 的基本构建块是什么？
What are the basic building blocks of SNN?

<!-- SNN 的基本构建块是 神经元 和 连接。 -->

![#center](https://wulixb.iphy.ac.cn/fileWLXB/journal/article/wlxb/2022/14/PIC/14-20220281-4.jpg)

## References

[Hardware implementation of spiking neural networks on FPGA](http://ieeexplore.ieee.org.shiep.vpn358.com/document/8954866) 用于 FPGA 上脉冲神经网络的硬件实现 8页 Tsinghua Science and Technology

[Spiking Neural Network on FPGA - FPGA Implementation](https://www.youtube.com/watch?v=1YnyNAxaJIg)

[如何看待第三代神经网络 SNN？详解脉冲神经网络的架构原理、数据集和训练方法](https://www.cvmart.net/community/detail/6210)

[脉冲神经网络 (Spiking Neural Network) 解读 (一)](https://zhuanlan.zhihu.com/p/416187474)

[脉冲神经网络（SNN）](https://zhuanlan.zhihu.com/p/144683881)

[Bio-inspired sensory systems with integrated capabilities of sensing, data storage, and processing](https://wulixb.iphy.ac.cn/en/article/doi/10.7498/aps.71.20220281?utm_source=TrendMD&utm_medium=cpc)

[白话脉冲神经网络（3）：LIF（Leaky Integrate and Fire）神经元](https://zhuanlan.zhihu.com/p/589157902)

本PPT基于[Awesome-Marp](https://github.com/favourhong/Awesome-Marp)制作
