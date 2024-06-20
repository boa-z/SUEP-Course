module clk_1_gen(clkout,clkin);
input clkin;
output reg clkout;
reg [25:0] counter = 0;
always @(posedge clkin) begin
    counter <= counter + 1;
    if (counter == 50000000 - 1) begin
        clkout <= ~clkout;
        counter <= 0;
    end
end
endmodule