go athena

# 网格定义
line x loc=0.00 spac=0.2
line x loc=1 spac=0.1
line x loc=1.1 spac=0.02
line x loc=2 spac=0.25

#
line y loc=0.00 spac=0.02
line y loc=0.2 spac=0.1
line y loc=0.4 spac=0.02
line y loc=2 spac=0.5

# 衬底定义

init silicon c.phos=5.0e18 orientation=100

# 形成氧化层
deposit oxide thick=0.50 divisions=5
etch oxide left p1.x=1

# 离子注入与退火
implant boron dose=1.0e15 energy=50 pearson tilt=7 rotation=0 amorph
method fermi compress
diffus time=30 temp=1000 nitro press=1.00

# 提取结深和方块电阻

extract name="xj" xj material="Silicon" mat.occno=1 x.val=0 junc.occno=1

extract name="rho" sheet.res material="Silicon" mat.occno=1 x.val=0 region.occno=1

# 氧化层刻蚀
etch oxide all

# 形成 Al 接触
deposit alum thickness=0.2 div=3

etch alum right p1.x=1.0

# 电极定义
electrode name=anode x=0.0
electrode name=cathode backside

# 结构保存&绘画
structure outf=diodeex05_0.str
tonyplot diodeex05_0.str -set diodeex05_0.set

go atlas
# 模型定义

# print 是指将模型参数打印出来
models bipolar bbt.std print
# 用于击穿分析的 Selberherr 碰撞电离模型.
impact selb

# 数值方法定义
method newton trap maxtrap=10 climit=1e-4
# 初值
solve init 

# 保存&绘画 IV 图
log outf=diodeex05.log
solve vanode=-0.25 vstep=-0.25 vfinal=-10 name=anode
tonyplot diodeex05.log -set diodeex05_log.set

# 从 IV 图中提取器件参数

extract init infile="diodeex05.log"

extract name="bv" min(v."anode")

extract name="leakage" x.val from curve(v."anode",abs(i."anode")) where y.val=1e-10

# 退出模拟
quit