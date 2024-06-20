# 大作业

> 请大家自选电路，准备大作业。大作业要求会尽快告诉大家。
注意：被同学A选中的电路，不可被同学B选。
后面几周，每周的课上，我会用部分时间，以LTC7890为例带大家做。

[LTspice演示电路所在链接](https://www.analog.com/cn/design-center/design-tools-and-calculators/ltspice-simulator/lt-spice-demo-circuits.html)

选择 [LT8631](https://www.analog.com/en/products/lt8631.html)

---

要求：阅读datasheet，复现模块性能测试。

选做内容：可以给代码加点注释，只能多多bing了。

一些相关代码

## ~~开秒~~ 寄了

[DC-DC Buck Converter Circuit LTSpice Simulation Complete Tutorial](https://www.youtube.com/watch?v=Iq7swlRXccU)

---

请将下面的文本翻译成中文，然后按照中文进行润色。

The LT8631 is a current mode PWM step-down DC/DC converter with internal synchronous switches that provide current for output loads up to 1A. The wide input range of 3V to 100V makes the LT8631 suitable for regulating power from a wide variety of sources, including automotive and industrial systems and 36V to 72V telecom supplies. Low ripple Burst Mode operation enables high efficiency operation down to very low output currents while keeping the output ripple below 10mV P-P . Resistor programmable 100kHz to 1MHz frequency range and synchronization capability enable optimization between efficiency and external component size. The soft-start feature controls the ramp rate of the output voltage, eliminating input current surge during start-up, while also providing output tracking. A power good flag signals when the output voltage is within ±7.5% of the regulated output. Undervoltage lockout can be programmed using the EN/ UV pin. Shutdown mode reduces the total quiescent current to < 5µA. The LT8631 is available in a 20-lead TSSOP package with exposed pad for low thermal resistance and high voltage lead spacing.

### Efficiency at VOUT = 5V

* [x] 助记号：1

[LTspice: Using .MEAS and .STEP Commands to Calculate Efficiency](https://www.analog.com/cn/technical-articles/ltspice-using-meas-and-step-commands-to-calculate-efficiency.html)

```LTspice
.step param X list 12 24 48
.step param Iload .2 1.0 .1

.tran 0 2.1m 2m startup

.meas Pin AVG -V(IN)*I(V1)
.meas Pout AVG V(OUT)*I(I1)
.meas Eff param Pout/Pin
```

按照此教程更换电流源 -> [活学活用 LTspice 进行电路设计 — 评估输出瞬态响应](https://www.cytech.com/technical-articles/learning-ltspice-circuit-design-confirm-output-transient-response)

看速度疑似有点慢了，建议试试 [用 .ic .save 命令加速模拟](https://www.cytech.com/technical-articles/learning-ltspice-circuit-design-speed-simulation-ic-save-command)

### Efficiency at VOUT = 3.3V

* [x] 助记号：2

就和上面差不多，但是应该怎么修改 Vout 呢？

通过阅读datasheet可知，需要将 R2 从 191kΩ 修改为 324kΩ

### Efficiency at VOUT = 5V 2

* [ ] 助记号：3

LTspice 电流负载 Iload 从 0.0001A 到 1.0A，如何仿真?
要求Iload实现如下变换过程
从 0.0001A 到 0.001A，步进 0.0001A
从 0.001A 到 0.01A，步进 0.001A
从 0.01A 到 0.1A，步进 0.01A
从 0.1A 到 1.0A，步进 0.1A

LTSpice中仿真结果采用非等间距的坐标轴进行显示应该怎么做？

~~可以使用.log或.dec模式来定义非等间距的步进~~

```LTspice
// .step param Iload 0.0001 1 10 log
// .step param Iload 0.0001 1 10 dec

.step dec param Iload 0.0001 1 10
```

这两种模式都会在0.0001A到1A之间分别取10个点，但是.log模式会取对数等间距的点，而.dec模式会取十进制等间距的点。您可以根据您的需要选择合适的模式。

Nature of sweep

* Linear
* Octave
* Decade
* List

### Efficiency

* [ ] 助记号：5

SWITCHING FREQUENCY (kHz)

Table 1. SW Frequency vs R T Value

| Frequency (kHz) | $R_{RT} (kΩ)$ |
| --------------- | ------------- |
| 100             | 187           |
| 200             | 60.4          |
| 300             | 35.7          |
| 400             | 25.5          |
| 500             | 19.6          |
| 600             | 15.8          |
| 700             | 13.3          |
| 800             | 11.5          |
| 900             | 10            |
| 1000            | 8.66          |

```LTspice
.step param Rt list 187k, 60.4k, 35.7k, 25.5k, 19.6k, 15.8k, 13.3k, 11.5k, 10k, 8.66k

.tran 0 2.1m 2m startup

.meas Pin AVG -V(IN)*I(V1)
.meas Pout AVG V(OUT)*I(I1)
.meas Eff param Pout/Pin
```

这边现在有2个「小问题」

* [ ] 横坐标是 Rt 的值，而不是频率
* [ ] 曲线和 datasheet 上的不一样

### Shutdown Supply Current

助记号：6

如何用 LTspice 仿真 LT8631 的 "Shutdown Supply Current"?

第一个问题，这是啥？-> [DC/DC Converter Datasheets - Quiescent Current Demystified: Part One](https://www.ti.com/document-viewer/lit/html/SSZTBG3)

找半天，**没找到测这玩意的教程**。

### EN/UV Thresholds

* [ ] 助记号：7

什么是LT8631 的 "EN/UV Thresholds"?

如何用 LTspice 仿真 LT8631 的 "EN/UV Thresholds",画出其随温度变化的曲线？

LT8631 的 "EN/UV Thresholds" 是指使能/欠压阈值，它是用于控制 LT8631 是否工作的电压水平。当 EN/UV 引脚的电压高于 1.22V 时，LT8631 开始工作；当 EN/UV 引脚的电压低于 1.15V 时，LT8631 关闭²。您可以通过外接一个分压电阻网络来调节 EN/UV 引脚的电压，从而实现对输入电压的欠压锁定功能¹。

> EN/UV (Pin 3): The EN/UV pin is used to enable the LT8631 or to program the undervoltage lockout threshold with external resistors. The LT8631 is in shutdown mode( I Q < 5µA) when the EN/UV pin voltage is below 1.19V and active mode when the voltage exceeds 1.19V. Tie EN/UV to the V IN pin if the EN/UV feature isn’t required.
> ...
> The LT8631 is a monolithic, constant frequency, current mode step-down DC/DC converter. When the voltage on the EN/UV pin is below its 1.19V threshold, the LT8631 is shutdown and draws less than 5µA from the input supply. When the EN/UV pin is driven above 1.19V, the internal bias circuits turn on generating an internal regulated voltage, 0.808V feedback reference, a 4.5µA soft-start current reference, and a power on reset (POR) signal.
> ...
> The EN/UV threshold prevents the regulator from operating at source voltages where the problems might occur. This threshold can be adjusted by setting the values R3 and R4 such that they satisfy the following equation:

$$
V_{EN \space THRESHOLD} = (\frac{R_3}{R_4} + 1) \times 1.19V
$$

> where the LT8631 will remain off until V IN is above the EN/UV threshold. Due to the comparator’s hysteresis, switching will not stop until the input falls slightly below the threshold voltage.
> When operating in Burst Mode operation for light load currents, the current through the EN/UV resistor network can easily be greater than the supply current consumed by the LT8631. Therefore, the EN/UV resistors should be large to minimize their effect on efficiency at low loads.

~~找半天，**没找到测这玩意的教程**。~~

首先需要改连接

我的想法是连接一个可调电压源，变化范围是 1.155V ~ 1.195V，步进 0.005V

温度仿真

```LTspice
.temp -50 -25 0 25 50 75 100 125 150
```

### Switching Frequency

* [ ] 助记号：10

$R_{RT} = 19.6K$

LTspice 如何仿真并画出 LT8631 的 "Frequency" 曲线，横坐标是 Temperature，纵坐标是 Frequency？
