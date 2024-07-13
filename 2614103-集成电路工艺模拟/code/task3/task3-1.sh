# Experiment 4. NMOS Device：Create an NMOS devise using ATHENA

go athena
# Non-unifrom Grid (0.6um×0.8um)
line x loc=0.00 spac=0.10
line x loc=0.20 spac=0.01
line x loc=0.6 spac=0.01

# Non-unifrom Grid (0.6um×0.8um)
line y loc=0.00 spac=0.008
line y loc=0.2 spac=0.01
line y loc=0.5 spac=0.05
line y loc=0.8 spac=0.15
# Initial Silicon
init silicon c.boron=1.0e14 orientation=100 two.d

# struct outfile = .history01.str
# tonyplot .history01.str

# Gate Oxidation
diffus time=11 minutes temp=950 dryo2 press=1 hcl.pc=3

# struct outfile = .history02.str
# tonyplot .history02.str
#
extract name="Gateoxide" thickness material="SiO~2" mat.occno=1 x.val=0.3
# Threshold Voltage Adjust implant
implant boron dose=9.5e11 energy=10 tilt=7 rotation=30 crystal 

# struct outfile = .history05.str
# tonyplot .history05.str

# Comformal Polysilicon Deposition
deposit polysilicon thick=0.2 divisions=10 

# struct outfile = .history07.str
# tonyplot .history07.str

# Polysilicon Definition
etch polysilicon left p1.x=0.35 

# struct outfile = .history08.str
# tonyplot .history08.str

# Polysilicon Oxidation
method fermi compress
diffus time=3 minutes temp=900 weto2 press=1 hcl.pc=3 

# Polysilicon Doping
implant phosphor dose=3.0e13 energy=20 tilt=7 rotation=30 crystal 

# struct outfile = .history09.str
# tonyplot .history09.str

# Spacer Oxide Deposit
deposit oxide thick=0.12 divisions=10 

# Spacer Oxide Etch
etch oxide dry thick=0.12 


# struct outfile = .history10.str
# tonyplot .history10.str

# Source/Drain Implant
implant arsenic dose=5.0e15 energy=50 tilt=7 rotation=30 crystal 
# Source/Drain Annealing
diffus time=1 minutes temp=900 nitro 

# struct outfile = .history12.str
# tonyplot .history12.str

# Open Contact Window
etch oxide left p1.x=0.2 

# struct outfile = .history13.str
# tonyplot .history13.str

# Aluminum Deposition
deposit aluminum thick=0.03 divisions=2 
# Etch Aluminum
etch aluminum right p1.x=0.18 

# struct outfile = .history14.str
# tonyplot .history14.str

#
extract name="nxj" xj material="Silicon" mat.occno=1 x.val=0.2 junc.occno=1

#

extract name="n++ sheet resistance" sheet.res material="Silicon" mat.occno=1 x.val=0.05 region.occno=1

# LDD didn't find @2.17.3, temp skipped

#
extract name="1dvt" 1dvt ntype qss=1e10 x.val=0.5

struct mirror right

# struct outfile = .history15.str
# tonyplot .history15.str

# define electrode
electrode name=Source x=0.10 
electrode name=Drain x=1.10 
electrode name=Gate x=0.60 

#
structure outfile=nmos.str
tonyplot nmos.str

# Following code is for task4(ex5)

go atlas

#创建ATLAS输入DECK文件
mesh infile=nmos.str
models consrh cvt boltzman print temperature=300
#模型定义
#
models consrh cvt boltzman print temperature=300 
#
mobility bn.cvt=4.75e7 bp.cvt=9.925e6 cn.cvt=1.74e5 cp.cvt=8.842e5 taun.cvt=0.125 taup.cvt=0.0317 gamn.cvt=2.5 gamp.cvt=2.2 mu0n.cvt=52.2 mu0p.cvt=44.9 mu1n.cvt=43.4 mu1p.cvt=29.0 mumaxn.cvt=1417.0 mumaxp.cvt=470.5 crn.cvt=9.68e16 crp.cvt=2.23e17 csn.cvt=3.43e20 csp.cvt=6.10e20 alphn.cvt=0.680 alphp.cvt=0.71 betan.cvt=2.0 betap.cvt=2.0 pcn.cvt=0.0 pcp.cvt=0.23e16 deln.cvt=5.82e14 delp.cvt=2.0546e14 
#
#定义接触性质
contact   name=gate n.poly
#定义界面性质
interface s.n=0 s.p=0 qf=3e+10
#数值方法选择命令组
method newton gummel itlimit=25 trap atrap=0.5 maxtrap=4 autonr nrcriterion=0.1 tol.time=5e-3 dt.min=1e-25 damped delta=0.5 damploop=10 dfactor=10.0 iccg lu1cri=3e3 lu2cri=3e2 maxinner=25 
#
#解定义命令组
solve init
solve vdrain=0.1 
#
solve init
solve vdrain=0.1 
log outf=nmos1_0.log
solve name=gate vgate=0 vfinal=3.3 vstep=0.1 
#提取器件参数
extract name="vt" (xintercept(maxslope(curve(abs(v."gate"),abs(i."drain")))) - abs(ave(v."drain"))/2.0)
#
extract name="beta" slope(maxslope(curve(abs(v."gate"),abs(i."drain")))) * (1.0/abs(ave(v."drain")))
#
extract name="theta" ((max(abs(v."drain")) * $"beta")/max(abs(i."drain"))) - (1.0 / (max(abs(v."gate")) - ($"vt")))
tonyplot nmos1_0.log
log off
#
solve vgate=1.1 outf=solve1
solve vgate=2.2 outf=solve2
solve vgate=3.3 outf=solve3
#
load infile=solve1 
log outf=nmos2_0.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3
#
load infile=solve2 
log outf=nmos3_0.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3 
#
load infile=solve3 
log outf=nmos4_0.log
solve name=drain vdrain=0 vfinal=3.3 vstep=0.3 
tonyplot -overlay nmos2_0.log nmos3_0.log nmos4_0.log  -set noms.set 
quit

