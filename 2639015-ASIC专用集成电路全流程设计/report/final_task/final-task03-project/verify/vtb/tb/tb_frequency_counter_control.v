`timescale 1ns/1ps

module tb_frequency_counter_control();
	reg Clk;
	reg Clear;
	reg Cntover;
	reg Cntlow;

  	wire reset;
	wire [2:0] range;
	wire [1:0] std_f_sel;

 frequency_counter_control uut(
	.Clk(Clk),
	.Clear(Clear),
	.reset(reset),
	.Cntover(Cntover),
	.Cntlow(Cntlow),
	.range(range),
	.std_f_sel(std_f_sel)
);

always #5 Clk = ~Clk;

initial begin
	Clk=0;
	Clear=0;
	Cntover=0;
	Cntlow=0;
	$monitor("Time:%0t.State:%b,range:%b,std_f_sel:%b,Clk:%b,Clear:%b,reset:%b,Cntover:%b,Cntlow:%b",$time,uut.state,range,std_f_sel,Clk,Clear,reset,Cntover,Cntlow);
	#10 Clear=1;
	#10 Clear=0;
	#20 Cntlow=0;Cntover=0;
	#20 Cntlow=1;
	#20 Cntlow=0;
	#20 Cntlow=1;
	#20 Cntlow=0;
	#20 Cntlow=1;
	#20 Cntlow=0;Cntover=1;
	#50 $finish;
   end

    initial begin
      $vcdplusfile("frequency_counter_control.vpd");
      $vcdpluson();
    end 

    initial begin
      $fsdbDumpfile("frequency_counter_control.fsdb");
      $fsdbDumpvars;
      $fsdbDumpon();
    end
endmodule
