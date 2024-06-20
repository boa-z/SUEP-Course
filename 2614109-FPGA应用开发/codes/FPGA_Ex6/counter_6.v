module counter_6(q,clk,en,clr,cout);
input clk,en,clr;
output[3:0] q;
output cout;
reg[3:0] q;
reg cout;
always @ (posedge clk or negedge clr)
    begin
        if (!clr)
            begin
                q<=0; 
            end 
        else if (en)
            begin
                if (q==5) 
					begin 
						q<=0;
						cout = ~cout;
					end
                else q <= q+1'b1;
            end
    end

endmodule