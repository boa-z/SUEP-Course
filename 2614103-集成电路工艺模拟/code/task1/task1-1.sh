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
# Gate Oxidation
diffus time=30 minutes temp=1000 dryo2 press=1 hcl.pc=3
#
extract name="Oxidethick" thickness material="SiO~2" mat.occno=1 x.val=0.3
# 
deposit polysilicon thick=0.2 divisions=10 
# 
implant arsenic dose=1.0e15 energy=40 tilt=7 rotation=30 crystal 
# 
diffus time=2 minutes temp=1000 nitro press=1 
#

extract name="Oxidethick" sheet.res material="Silicon" mat.occno=1 x.val=0.3 region.occno=1 semi.poly
#  Polysilicon Definition
etch polysilicon left p1.x=0.15 
# 
etch polysilicon right p1.x=0.45 

 # Polysilicon Oxidation
method fermi compress
diffus time=3 minutes temp=900 weto2 press=1 
# Polysilicon Definition
etch oxide start x=0.25 y=-0.25 
etch cont x=0.35 y=-0.25 
etch cont x=0.35 y=-0.20 
etch done x=0.25 y=-0.20 
# 
deposit aluminum thick=0.05 divisions=10 
# Polysilicon Definition
etch aluminum left p1.x=0.2 
# 
etch aluminum right p1.x=0.4 

structure outf=tfmr.str
tonyplot tfmr.str