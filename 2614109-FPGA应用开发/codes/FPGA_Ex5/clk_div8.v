module clk_div8(clkout,clkin);
input clkin;
output clkout;
reg clkout;
reg[1:0] counter;
always @(posedge clkin)
    begin
        if(counter[1:0]==2'd3)
            begin //每计到4个（0~3）上升沿，输出信号翻转一次
            counter <= 0;
            clkout <= ~clkout;
            end
            else
                counter[1:0]<=counter[1:0]+1'b1;
    end
endmodule