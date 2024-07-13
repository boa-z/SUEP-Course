# Experiment 4. NMOS Device：Create an NMOS devise using ATHENA
# Notes: 
# Try to plot all ".history" file to one image
# To save time, I removed code for task4, if you need NMOS output, please refer to task3-1.sh
# Add more plot to show the process of NMOS device

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

struct outfile = .history01.str
# tonyplot .history01.str

# Gate Oxidation
diffus time=11 minutes temp=950 dryo2 press=1 hcl.pc=3

struct outfile = .history02.str
# tonyplot .history02.str
#
extract name="Gateoxide" thickness material="SiO~2" mat.occno=1 x.val=0.3
# Threshold Voltage Adjust implant
implant boron dose=9.5e11 energy=10 tilt=7 rotation=30 crystal 

struct outfile = .history05.str
# tonyplot .history05.str

# Comformal Polysilicon Deposition
deposit polysilicon thick=0.2 divisions=10 

struct outfile = .history07.str
# tonyplot .history07.str

# Polysilicon Definition
etch polysilicon left p1.x=0.35 

struct outfile = .history08.str
# tonyplot .history08.str

# Polysilicon Oxidation
method fermi compress
diffus time=3 minutes temp=900 weto2 press=1 hcl.pc=3 

# Polysilicon Doping
implant phosphor dose=3.0e13 energy=20 tilt=7 rotation=30 crystal 

struct outfile = .history09.str
# tonyplot .history09.str

# Spacer Oxide Deposit
deposit oxide thick=0.12 divisions=10 

# Spacer Oxide Etch
etch oxide dry thick=0.12 

struct outfile = .history10.str
# tonyplot .history10.str

# Source/Drain Implant
implant arsenic dose=5.0e15 energy=50 tilt=7 rotation=30 crystal 
# Source/Drain Annealing
diffus time=1 minutes temp=900 nitro 

struct outfile = .history12.str
# tonyplot .history12.str

# Open Contact Window
etch oxide left p1.x=0.2 

struct outfile = .history13.str
# tonyplot .history13.str

# Aluminum Deposition
deposit aluminum thick=0.03 divisions=2 

struct outfile = .history14.str
# tonyplot .history14.str

# Etch Aluminum
etch aluminum right p1.x=0.18 

struct outfile = .history15.str
# tonyplot .history15.str

#
extract name="nxj" xj material="Silicon" mat.occno=1 x.val=0.2 junc.occno=1

#

extract name="n++ sheet resistance" sheet.res material="Silicon" mat.occno=1 x.val=0.05 region.occno=1

# LDD didn't find @2.17.3, temp skipped

#
extract name="1dvt" 1dvt ntype qss=1e10 x.val=0.5

struct mirror right

struct outfile = .history16.str
# tonyplot .history16.str

# define electrode
electrode name=Source x=0.10 
electrode name=Drain x=1.10 
electrode name=Gate x=0.60 
electrode name=backside backside 


tonyplot .history01.str .history02.str .history05.str .history07.str .history08.str .history09.str .history10.str .history12.str .history13.str .history14.str .history15.str .history16.str

#
structure outfile=nmos.str
tonyplot nmos.str
