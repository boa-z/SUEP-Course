create_clock -name my_clk -period 4.0 [get_ports Clk]

set_clock_uncertainty 0.25 [get_clocks my_clk]

set_dont_touch_network [get_clocks my_clk]

set_input_delay -max 1.0 [get_ports {Clear reset Cntover Cntlow}]

set_input_delay -max 1.0 [get_ports {Clear reset Cntover Cntlow}] -clock my_clk

set_output_delay -max 3.0 [get_ports {range std_f_sel}] -clock my_clk

set_output_delay -min 0.0 -max 3.0 [get_ports {range std_f_sel}] -clock my_clk

set_dont_touch [get_ports {Clear reset Cntover Cntlow}]
