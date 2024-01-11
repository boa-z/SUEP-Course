import numpy as np

# 定义序列
seq1 = np.array([1, 2, 3, 4])
seq2 = np.array([2, 0, 1, 0])

# 计算4点循环卷积
circular_convolution = np.fft.ifft(np.fft.fft(seq1) * np.fft.fft(seq2))
a = circular_convolution.real.round().astype(int)  # 取实部并四舍五入至整数

print(a)

