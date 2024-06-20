module clk_div8(clkout,clkin);
input clkin;
output clkout;
reg clkout;
reg[1:0] counter;
always @(posedge clkin)
    begin
        if(counter[1:0]==2'd3)
            begin //ÿ�Ƶ�4����0~3�������أ�����źŷ�תһ��
            counter <= 0;
            clkout <= ~clkout;
            end
            else
                counter[1:0]<=counter[1:0]+1'b1;
    end
endmodule