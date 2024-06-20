import numpy as np
import matplotlib.pyplot as plt

f = 400  # 信号频率
Ts = 0.001  # 采样间隔
t = np.arange(0, 40 * Ts, Ts)  # 采样时间范围，绘制4个采样周期

xa = 2 * np.cos(2 * np.pi * f * t + 2 * np.pi)  # 原始信号

plt.plot(t, xa, marker='o')
plt.title('sampled signal $\hat{x}_a(t)$')
plt.xlabel('time (s)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.show()