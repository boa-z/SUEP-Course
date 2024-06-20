module clk_div7(clk,clock);
input clock;
output clk;
reg[2:0] counter;
reg temp1,temp2;
always @(posedge clock)
    begin
        if(counter[2:0]==3'd6)
            begin
                counter<=0;
                temp1<=~temp1;
            end
        else
            counter[2:0]<=counter[2:0]+1'b1;
    end
always @(negedge clock)
    begin
        if(counter[2:0]==3'd3)
            temp2<=~temp2;
    end

assign clk=temp1^temp2;
endmodule