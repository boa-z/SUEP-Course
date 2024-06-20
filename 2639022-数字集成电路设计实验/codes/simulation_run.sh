# on macOS use iverilog

iverilog -o edge_detection edge_detection.v edge_detection_tb.v
vvp edge_detection
gtkwave edge_detection.vcd

# on CentOS use vcs

# vcs -debug_all edge_detection.v full_adder_tb.v -l com.log \
# ./simv -l sim.log \
# dve -vpd vcdplus.vpd &vd