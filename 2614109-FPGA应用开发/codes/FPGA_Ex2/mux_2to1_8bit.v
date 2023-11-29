module mux_2to1_8bit (m,s,x,y);
input[7:0] x,y;
input s;
output reg[7:0] m; 
always @(s or x or y) 
begin 
    if(s==1'b0) 
        m=x;
    else 
        m=y; 
end 
endmodule