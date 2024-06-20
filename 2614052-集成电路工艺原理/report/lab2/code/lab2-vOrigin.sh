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

# 栅氧化，干氧11分钟,温度950.
diffus time=11 temp=950 dryo2 press=1.00 hcl.pc=3

# 提取栅氧化层厚度
extract name="Gateoxide" thickness \
   material="Sio-2" mat.occno=1 x.val=0.3

# 阈值电压调整
implant boron dose=9.5e11 energy=10 crystal

# 提取表面浓度
# 淀积多晶硅；
depo poly thick=0.2 divi=10
# 定义多晶硅栅
etch poly left p1.x=0.35
# 多晶硅氧化，湿氧,900度，3分钟;
method fermi compress
diffuse time=3 temp=900 weto2 press=1.0
# 多晶硅掺杂
implant phosphor dose=3.0e13 energy=20 crystal

# 侧墙的形成
# 淀积氧化层：
depo oxide thick=0.12 divisions=10
# 干法刻蚀：
etch oxide dry thick=0.12
# 源漏砷注入,快速退火
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
extract name="ldd sheet rho" sheet.res material="Silicon" \
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

#(每一道工艺定义后，都需要输出/画出结构图)
# 启动器件仿真器
go atlas
# 设置模型
models cvt srh print 
# 设置界面电荷
contact name=gate n.poly
interface qf=3e10
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
#  画出转移特性曲线
tonyplot  mos1ex01_1.log -set mos1ex01_1_log.set
#  提取器件参数
extract name="nvt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
    - abs(ave(v."drain"))/2.0)
extract name="nbeta" slope(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
    * (1.0/abs(ave(v."drain")))
extract name="ntheta" ((max(abs(v."drain")) ＊ ＄"nbeta")/max(abs(i."drain"))) \
    — (1.0 / (max(abs(v."gate")) — (＄"nvt")))
# 对不同的Vg，求Id与Vds的关系曲线
solve init
solve vgate=1.1 outf=solve_tmp1
solve vgate=2.2 outf=solve_tmp2
solve vgate=3.3 outf=solve_tmp3
solve vgate=5  outf=solve_tmp4
load infile=solve_tmp1
log outf=mos_1.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp2
log outf=mos_2.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp3
log outf=mos_3.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
load infile=solve_tmp4
log outf=mos_4.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
# 画出转移特性曲线
tonyplot —overlay —st mos_4.log mos_3.log mos_2.log mos_1.log 
# 退出
quit
