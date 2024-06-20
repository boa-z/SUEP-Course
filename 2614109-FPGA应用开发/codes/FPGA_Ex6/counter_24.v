module counter_24(q1,q0, clk,en,clr);
input clk,en,clr;
output[3:0] q0,q1;
reg[3:0] q0,q1;
always @ (posedge clk or negedge clr)
    begin
        if (!clr)
            begin
                q0<=0;q1<=0; 
            end 
        else if (en)
            begin
                if ((q1>2) || (q0>9) || ((q1==2) && (q0>=3)))
                    begin
                        q0<=0;
                        q1<=0;
                    end
                else if (q0==9)
                    begin
                        q0<=0;
                        q1<=q1+1'b1;
                    end
                else q0<=q0+1'b1;
            end
    end

endmodule