# 导入numpy和matplotlib库
import numpy as np
import matplotlib.pyplot as plt

# 定义单位阶跃函数u(n)
def u(n):
    return np.heaviside(n, 1)

# 定义x(n) = (2n+1)[u(n+2) - u(n-3)]
def x(n):
    return (2*n+1)*(u(n+2) - u(n-3))

# 定义y(n) = x((n))_4
def y(n):
    return x(n % 4)

# 生成n的范围，从-5到10
n = np.arange(-5, 11)

# 计算x(n)和y(n)的值
xn = x(n)
yn = y(n)

# 画出x(n)和y(n)的波形
plt.figure(figsize=(8, 6))
plt.subplot(2, 1, 1)
plt.stem(n, xn, use_line_collection=True)
plt.xlabel('n')
plt.ylabel('x(n)')
plt.title('x(n) = (2n+1)[u(n+2) - u(n-3)]')
plt.grid()
plt.subplot(2, 1, 2)
plt.stem(n, yn, use_line_collection=True)
plt.xlabel('n')
plt.ylabel('y(n)')
plt.title('y(n) = x((n))_4')
plt.grid()
plt.tight_layout()
plt.show()
