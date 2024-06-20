# TODO task 1:
# NOVAS_INST_DIR=/qixin/eda/synopsys/verdi/2018.09
# In new version of verdi,
NOVAS_INST_DIR=/qixin/eda/synopsys_2021/verdi/S-2021.09
PLATFORM=LINUX64
TOOL=VCS

# Question 1. how to generate the random number?
# Solution 1. random seed generation
SEED = $(shell date +%s)
v
CYCLE_NUM = 200

# variables definition
DUT = -f ./rtl.f
TB = -f ./tb.f

# --- run the simulation through the common method ---
run: compile simulate

# TODO task 2:
compile:
    vcs -timescale=1ns/1ps -debug_all $(DUT) $(TB) -l com_$(SEED).log \
    -P ${NOVAS_INST_DIR}/share/PLI/${TOOL}/${PLATFORM}/novas.tab \
    ${NOVAS_INST_DIR}/share/PLI/${TOOL}/${PLATFORM}/pli.a

# --- coverage driven strategy ---
run_cov: compile_coverage simulate_coverage

compile_coverage:
	vcs -debug_all -cm line+cond+fsm+tgl+branch -lca $(DUT) $(TB) -l com_$(SEED).log

simulate_coverage:
	./simv +plusarg_save +seed=$(SEED) + cycle_num=$(CYCLE_NUM) -cm line+cond+fsm+tgl+branch -lca -cm_log \
	cm_$(SEED).log -l sim_$(SEED)

report_cov:
	urg -dir simv.vdb -format both -report coverage

dve_cov:
	dve -cov -covdir simv.vdb -lca


# TODO task 4:
verdi_fsdb:
    cat rtl.f > all.f
    cat tb.f >> all.f
    verdi -f all.f -ssf adder32.fsdb