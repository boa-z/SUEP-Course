# 请使用scipy和numpy和matplotlib，编写程序完成已知 $h(n)=\delta(n+2)+3 \delta(n)-\delta(n-1)+2 \delta(n-3)$ 求 $[h((-n))_6 R_6(n)]$ 并画出它的波形。

# 实现周期延拓函数

# 导入numpy和matplotlib库
import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal

# 定义单位脉冲函数delta(n)
def delta(n):
    return np.where(n == 0, 1, 0)

# 定义R(n)的表达式

def R(n):
    return np.where(n >= 0, 1, 0)

# 定义h(n)的表达式
def h(n):
    return (delta(n+2) + 3*delta(n) - delta(n-1) + 2*delta(n-3))

# 生成n的范围，从-10到10
n = np.arange(-3, 4)

# 计算h(-n)的值
hn = h(-n)
print(hn)

# 进行周期延拓

hnn = np.tile(hn, 6)

print(hnn)

n_1 = np.arange(-30, 31)

# 画出h((-n))_6 R_6(n)的波形
plt.figure(figsize=(8, 4))
plt.stem(n, hn, use_line_collection=True)
plt.xlabel('n')
plt.ylabel('h((-n))_6 R_6(n)')
plt.title('h((-n))_6 R_6(n) = h((-n))_6 \cdot R_6(n)')
plt.grid()
plt.show()
