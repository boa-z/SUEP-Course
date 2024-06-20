module clk_div3(clk,clock);
input clock;
output clk;
reg[1:0] counter;
reg temp1,temp2;
always @(posedge clock)
    begin
        if(counter[1:0]==2'd2)
            begin //ÿ�Ƶ�4����0~3�������أ�����źŷ�תһ��
                counter<=0;
                temp1<=~temp1;
            end
        else
            counter[1:0]<=counter[1:0]+1'b1;
    end
always @(negedge clock)
    begin
        if(counter[1:0]==2'd1)
            temp2<=~temp2;
    end

assign clk=temp1^temp2;
endmodule
