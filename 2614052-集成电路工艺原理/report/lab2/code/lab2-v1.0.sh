# 版本说明
# 在 Origin 版本的基础上，添加 LWZ 版本的部分代码
# 本版本运行过程中会出现报错

# 启动Athena
go athena

# 器件结构网格划分；
line x loc=0.0 spac=0.1
line x loc=0.2 spac=0.006
line x loc=0.4 spac=0.006
line x loc=0.6 spac=0.01
line y loc=0.0 spac=0.002
line y loc=0.2 spac=0.005
line y loc=0.5 spac=0.05
line y loc=0.8 spac=0.15
# (建议定义左边一半)
# 初始化；

#定义初始硅：100 晶向，作为P 型衬底，用硼掺杂，掺杂浓度为1e14，
init silicon c.boron=1e14 orientation=100 space.mul=2 two.d

# 栅氧化，干氧11分钟,温度950.
diffus time=11 temp=950 dryo2 press=1.00 hcl.pc=3

# 提取栅氧化层厚度
extract name="gateox" thickness \
    oxide mat.occno=1 x.val=0.3

# 阈值电压调整
implant boron dose=2e12 energy=10 pearson

# 提取表面浓度
# 淀积多晶硅；
depo poly thick=0.2 divi=10
# 定义多晶硅栅
etch poly left p1.x=0.35
# 多晶硅氧化，湿氧, 900度，3分钟;
method fermi compress
diffuse time=3 temp=900 weto2 press=1.0
# 多晶硅掺杂
implant phosphor dose=3.0e13 energy=20 crystal

# 侧墙的形成
# 淀积氧化层：
depo oxide thick=0.12 divisions=10
# 干法刻蚀：
etch oxide dry thick=0.12
# 源漏砷注入, 快速退火
implant arsenic dose=5.0e15 energy=50 crystal
method fermi 
diffuse time=1 temp=900 nitro press=1.0
# 金属化
etch oxide left p1.x=0.2
deposit alumin thick=0.03 divi=2
etch alumin right p1.x=0.18

# 提取器件参数：结深，源漏方块电阻，侧墙下的方块电阻，阈值电压
# extract final S/D Xj
extract name="nxj" xj silicon mat.occno=1 x.val=0.1 junc.occno=1
# extract the N++ regions sheet resistance
extract name="n++ sheet rho" sheet.res material="Silicon" mat.occno=1 x.val=0.05 region.occno=1
# extract the sheet rho under the spacer, of the LDD region
extract name="ldd sheet rho" sheet.res material="Silicon"
mat.occno=1 x.val=0.3 region.occno=1
# extract the surface conc under the channel.
extract name="chan surf conc" surf.conc impurity="Net Doping" \
material="Silicon" mat.occno=1 x.val=0.45
# extract a curve of conductance versus bias.
extract start material="Polysilicon" mat.occno=1 \
    bias=0.0 bias.step=0.2 bias.stop=2 x.val=0.45
extract done name="sheet cond v bias" \
    curve(bias, 1dn.conduct material="Silicon" mat.occno=1  region.occno=1)\
    outfile="extract.dat"
# extract the long chan Vt
extract name="n1dvt" 1dvt ntype vb=0.0 qss=1e10 x.val=0.49
# 右边结构生成
structure mirror right
# 设置电极
electrode name=gate x=0.5 y=0.1
electrode name=source x=0.1
electrode name=drain x=1.1
electrode name=substrate backside
# 输出结构图
structure outfile=mos1ex01_0.str
tonyplot mos1ex01_0.str

# 接下来进行器件物理特性分析，先求栅压为1.1V,2.2V,3.3V时，漏电流与漏电压的关系，即进行CVT分析

go atlas

contact name=gate n.poly
interface qf=3e10
models cvt srh print numcarr=2

# # 对不同的Vg，求Id与Vds的关系曲线
# # 提取器件参数 -- 新版本，旧版丢底下去了
# extract name="nvt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
#     - abs(ave(v."drain"))/2.0)
# extract name="nbeta" slope(maxslope(curve(abs(v."gate"),abs(i."drain"))))* (1.0/abs(ave(v."drain")))
# extract name="nsubvt" 1.0/slope(maxslope(curve(abs(v."gate"),log10(abs(i."drain")))))
# # # 提取器件参数
# # extract name="nvt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
# #     - abs(ave(v."drain"))/2.0)
# # extract name="nbeta" slope(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
# #     * (1.0 / abs(ave(v."drain")))
# # extract name="ntheta" ((max(abs(v."drain")) * $"nbeta")/max(abs(i."drain"))) \
# #     — (1.0 / (max(abs(v."gate")) — ($"nvt")))

solve init
solve vgate=1.1 outf=solve_tmp1
solve vgate=2.2 outf=solve_tmp2
solve vgate=3.3 outf=solve_tmp3
solve vgate=5  outf=solve_tmp4

# 加载文件和步进Vd

load infile=solve_tmp1
log outf=nmos_1.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp2
log outf=nmos_2.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp3
log outf=nmos_3.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp4
log outf=nmos_4.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3

# 提取最大漏极电流和β值（斜率）-- 此处需要添加，不然运行完没 plot
 
extract name="nidsmax" max(i."drain")
extract name="sat_slope" slope(minslope(curve(v."drain",i."drain")))

# 画出转移特性曲线
tonyplot —overlay —st nmos_4.log nmos_3.log nmos_2.log nmos_1.log

# (每一道工艺定义后，都需要输出/画出结构图)
# 此处应该是 Vt 测试
# 启动器件仿真器
go atlas
# 设置模型
models cvt srh print

# 设置界面电荷
# 定义栅极功能，N型接触
contact name=gate n.poly
# 定义栅氧化层正电荷为3e10
interface qf=3e10

# 使用CVT模型分析 MOS
models cvt srh print numcarr=2
# 设置迭代模型
method newton

# 解初始化
solve init

# 设置漏极电压0.1V
solve vdrain=0.1

# Ramp the gate
log outf=mos1ex01_1.log master
# 对栅极电压扫描
solve vgate=0 vstep=0.25 vfinal=3.0 name=gate
save outf=mos1ex01_1.str

# 画出转移特性曲线
tonyplot mos1ex01_1.log -set mos1ex01_1_log.set

# 提取器件参数
extract name="nvt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
    - abs(ave(v."drain"))/2.0)
extract name="nbeta" slope(maxslope(curve(abs(v."gate"),abs(i."drain"))))* (1.0/abs(ave(v."drain"))) 
extract name="nsubvt" 1.0/slope(maxslope(curve(abs(v."gate"),log10(abs(i."drain")))))


# 退出
quit
