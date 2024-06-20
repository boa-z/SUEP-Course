# 版本说明
# 在 WEB 版本的基础上，添加 Origin 版本的部分代码

#启动Athena

go athena
 
#定义X网格
 
line x loc=0 spac=0.1
line x loc=0.2 spac=0.006
line x loc=0.65 spac=0.006
 
#定义Y网格
 
line y loc=0.00 spac=0.002
line y loc=0.2 spac=0.005
line y loc=0.5 spac=0.05
line y loc=1.0 spac=0.15
 
#定义初始硅：100 晶向，作为P 型衬底，用硼掺杂，掺杂浓度为1e14，
 
init silicon c.boron=1e14 orientation=100 space.mul=2 two.d
 
#制作栅氧化层：把硅片放在950摄氏度，干氧，一个大气压下掺氯（氯化氢）氧化10分钟
 
diffus time=10 temp=950 dryo2 press=1.00 hcl.pc=3
 
#抽取栅氧化层厚度
 
extract name="gateox" thickness \
    oxide mat.occno=1 x.val=0.3
 
#调整阈值电压，离子注入，注入硼离子
 
implant boron dose=2e12 energy=10 pearson
 
#淀积Poly层
 
depo poly thick=0.25 divi=10
 
#栅刻蚀:刻蚀掉x=0.35左面的多晶硅
 
etch poly left p1.x=0.35
 
#湿氧氧化为轻掺杂做准备
 
diffuse time=3 temp=900 weto2
 
#轻掺杂离子注入，注入磷离子，形成轻掺杂层，剂量为3e13，能量为20kev
 
implant phosphor dose=3e13 energy=20 tilt=0 rotation=0
 
#沉积氧化层再进行干刻蚀，以进行下一步的源漏区注入
 
depo oxide thick=0.120 divisions=8
 
etch oxide dry thick=0.120
 
#进行源漏砷离子的注入，剂量为4e15，能量为40kev
 
implant arsenic dose=5.0e15 energy=40 tilt=0 rotation=0
 
#快速退火
 
method fermi
 
diffus time=1 temp=900 nitro press=1.00
 
#下面处理漏源极
 
#刻蚀掉x=0.1以左的氧化层
 
etch oxide left p1.x=0.1
 
#刻蚀掉一个矩形,把栅极多晶硅上面的氧化层刻蚀掉，我写的下面四句蚀刻掉了（0.357,-0.15）->(0.6,-0.15)->(0.6,-0.3)->(0.357,-0.3)区域内的氧化层
 
etch oxide start x=0.357 y=-0.15
 
etch cont x=0.65 y=-0.15
 
etch cont x=0.65 y=-0.3
 
etch done x=0.357 y=-0.3
 
#沉积铝
 
deposit alumin thick=0.1 div=20
 
#刻蚀掉一个矩形区域的铝，我写的下面四句蚀刻掉了（0.35,0.1）->(0.1,0.1)->(0.1,-0.4)->(0.35,0.4)区域内的铝
 
etch alumin start x=0.35 y=0.1
 
etch cont x=0.1 y=0.1
 
etch cont x=0.1 y=-0.4
 
etch done x=0.35 y=-0.4
 
#接下来进行结果分析的提取，查看器件特性
 
#Extract design parameters
 
#extract final S/D Xj
 
extract name="nxj" xj silicon mat.occno=1 x.val=0.1 junc.occno=1
 
#extract the N++ regions sheet resistance
 
extract name="n++ sheet rho" sheet.res material="Silicon" mat.occno=1 x.val=0.05 region.occno=1
 
#extract the sheet rho under the spacer,of the LDD region
 
extract name="ldd sheet rho" sheet.res material="Silicon"
 
mat.occno=1 x.val=0.3 region.occno=1
 
#extract the surface conc under the channel.
 
extract name="chan surf conc" surf.conc impurity="Net Doping"
 
material="Silicon" mat.occno=1 x.val=0.45
 
#extract a curve of conductance versus bias.
 
extract start material="Polysilicon" mat.occno=1
 
bias=0.0 bias.step=0.2 bias.stop=2 x.val=0.45
 
extract done name="sheet cond v bias"
 
curve(bias,1dn.conduct material="Silicon" mat.occno=1 region.occno=1)
 
outfile="extraction.dat"
 
#extract the long chan Vt
 
extract name="n1dvt" 1dvt ntype vb=0.0 qss=1e10 x.val=0.49
 
#接下来进行镜像和电极定义
 
#镜像对称

structure mirror right
 
#保存镜像结构，完整的nMOS
 
structure outfile=mirror.str

electrode name=gate x=0.5 y=-0.2
 
electrode name=source x=0.05 y=0
 
electrode name=drain x=1.30 y=0

electrode name=substrate backside
 
#工艺仿真器件制作完成，保存到我的Test2-NMOS1_athena.str文件中
 
structure outfile=Test2-NMOS1_athena.str
 
tonyplot Test2-NMOS1_athena.str
 
#接下来进行器件物理特性分析，先求栅压为1.1V,2.2V,3.3V时，漏电流与漏电压的关系，即进行CVT分析
 
go atlas
 
# 定义栅极功能，N型接触
 
contact name=gate n.poly
 
# 定义栅氧化层正电荷为3e10
 
interface qf=3e10
 
# 使用CVT模型分析 MOS
 
models cvt srh print numcarr=2
 
# 设置栅极偏置，同时设置Vds=0V
 
solve init
 
solve vgate=0.5 outf=solve_tmp0_Test2
 
solve vgate=1.1 outf=solve_tmp1_Test2
 
solve vgate=2.2 outf=solve_tmp2_Test2
 
solve vgate=3.3 outf=solve_tmp3_Test2
 
#加载文件和步进Vd
 
load infile=solve_tmp0_Test2
 
log outf=Test2_MOSLEX_0.log
 
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
 
load infile=solve_tmp1_Test2
 
log outf=Test2_MOSLEX_1.log
 
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
 
load infile=solve_tmp2_Test2
 
log outf=Test2_MOSLEX_2.log
 
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
 
load infile=solve_tmp3_Test2
 
log outf=Test2_MOSLEX_3.log
 
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
 
# 提取最大漏极电流和β值（斜率）
 
extract name="nidsmax" max(i."drain")
 
extract name="sat_slope" slope(minslope(curve(v."drain",i."drain")))
 
tonyplot -overlay -st Test2_MOSLEX_0.log Test2_MOSLEX_1.log Test2_MOSLEX_2.log Test2_MOSLEX_3.log
 
#接下来进行Vt 测试：返回 Vt、Beta 和 θ
 
go atlas
 
#建立材料模型
 
models cvt srh print
 
contact name=gate n.poly
 
interface qf=3e10
 
method gummel newton
 
solve init
 
# 漏极给偏置电压
 
solve vdrain=0.1
 
# 栅压步进
 
log outf=Test2-Vt.log master
 
solve vgate=0 vstep=0.25 vfinal=3.0 name=gate
 
save outf=Test2-Vt.str
 
tonyplot Test2-Vt.log
 
#提取器件参数
 
extract name="nvt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) \
    - abs(ave(v."drain"))/2.0)
 
extract name="nbeta" slope(maxslope(curve(abs(v."gate"),abs(i."drain"))))* (1.0/abs(ave(v."drain")))
 
extract name="nsubvt" 1.0/slope(maxslope(curve(abs(v."gate"),log10(abs(i."drain")))))
 
quit
