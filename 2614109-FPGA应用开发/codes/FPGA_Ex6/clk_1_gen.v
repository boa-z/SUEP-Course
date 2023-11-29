module clk_1_gen (clkout,clkin);
input clkin;
output clkout;
reg clkout;
reg[24:0] counter;
always @(posedge clkin)
    begin
        if( counter[24:0] == 25'd49999999)
            begin
                counter <= 0;
                clkout <= ~ clkout;
            end
        else
            counter[24:0] <= counter[24:0] + 1'b1;
    end
endmodule