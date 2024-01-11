# matplotlib绘制系统频率响应
# https://juejin.cn/post/6874126596664623118

# 对于如下系统函数，请修改代码，画出其系统频率响应 H(z) = 0.64 \frac{z-1}{z^2 - 1.6z\cos(\frac{\pi}{4}) + 0.64}

import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
from matplotlib.ticker import FuncFormatter
mpl.rcParams['font.sans-serif'] = ['SimHei']#显示中文必须要改变字体，否则会报错并且不能显示
# 改变坐标轴格式的函数
# ----------------------
def func(x,pos):    
    if not x:        
        return "0"    
    if x%np.pi:        
        if x:            
            m=x/np.pi            
            return "%.1fπ"%m        
        else: return "0"    
    return ""
# -----------------------
# 必要的数据
w=np.linspace(0,2*np.pi,100)

# 这段代码是用来计算系统函数的幅度的公式，根据系统函数的极点和零点的对称性，可以简化为：
# $$|H(e^{jw})| = \frac{0.64}{|e^{jw}-0.8e^{j\frac{\pi}{4}}||e^{jw}-0.8e^{-j\frac{\pi}{4}}|}$$
H=0.64/(np.sqrt((np.cos(w)-0.8*np.cos(np.pi/4))**2+(np.sin(w)-0.8*np.sin(np.pi/4))**2)*np.sqrt((np.cos(w)-0.8*np.cos(np.pi/4))**2+(np.sin(w)+0.8*np.sin(np.pi/4))**2))

# 这段代码是用来计算系统函数的相位的公式，根据系统函数的极点和零点的对称性，可以简化为：
# $$\phi(w) = -\angle (e^{jw}-0.8e^{j\frac{\pi}{4}}) - \angle (e^{jw}-0.8e^{-j\frac{\pi}{4}})$$
fai=-np.arctan((np.sin(w)-0.8*np.sin(np.pi/4))/(np.cos(w)-0.8*np.cos(np.pi/4)))-np.arctan((np.sin(w)+0.8*np.sin(np.pi/4))/(np.cos(w)-0.8*np.cos(np.pi/4)))
# -------------------------
# 找到峰值
H_list=H.tolist()
max_index = H_list.index(max(H_list))+1
max=max(H_list)
# ---------------------------
# 画峰值的虚线
g=np.linspace(0,max,100)
x1=np.zeros(100)
x2=np.zeros(100)
x1=x1+max_index/100*2*np.pi
x2=x2+(100-max_index)/100*2*np.pi
# -----------------------------
fig,ax=plt.subplots(2,1)
# -----------------------------
# 设置坐标轴格式
ax[0].xaxis.set_major_formatter(FuncFormatter(func))
ax[1].xaxis.set_major_formatter(FuncFormatter(func))
ax[0].set_xlabel("ω")
ax[0].set_ylabel('|H(e^jw)|')
ax[1].set_xlabel('ω')
ax[1].set_ylabel('φ(ω)')
ax[0].set_title('幅频特性')
ax[1].set_title('相频特性')
# --------------------------------
ax[0].plot(w,H)
ax[0].plot(x1,g,'--')
ax[0].plot(x2,g,'--')
y=max_index/100*2
ax[0].annotate("({:.2f}π,{:.2f})".format(y,max), xy=(y*np.pi, max), xycoords='data', xytext=(+30, -30),             textcoords='offset points', arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))
y=(100-max_index)/100*2
ax[0].annotate("({:.2f}π,{:.2f})".format(y,max), xy=(y*np.pi, max), xycoords='data', xytext=(+30, -30),             textcoords='offset points', arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))
ax[0].scatter(max_index/100*2*np.pi,max,color='b')
ax[0].scatter((100-max_index)/100*2*np.pi,max,color='b')
ax[1].plot(w,fai)
plt.show()
