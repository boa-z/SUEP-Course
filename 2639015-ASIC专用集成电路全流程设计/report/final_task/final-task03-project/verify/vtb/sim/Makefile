# Makefile for simulate the ALU with the simulator VCS

all: clean compile simulate

compile:
	vcs -Mupdate -sverilog  -debug_access+all +define+VCS \
		 -f ../../../rtl/verilog/rtl.f\
		 -f ../tb/tb.f \
		 +vcs+lic+wait \
	   -kdb -l com.log

simulate:
	./simv -l sim.log


vcs:
	dve  -vpd  frequency_counter_control.vpd  &


clean:
	rm -rf *.log  csrc simv simv.daidir ucli.key vcdplus.vpd DVEfiles coverage simv.vdb \
	verdiLog *.fsdb *.vpd novas.rc novas.conf

verdi:
	verdi -ssf frequency_counter_control.fsdb &

