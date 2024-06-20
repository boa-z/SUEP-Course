module mux_2to1 (m,s,x,y); 
input x,y,s; 
output m; 
reg m; 
always @(s or x or y) 
begin 
    if(s==1'b0) 
        m=x;
    else 
        m=y; 
end 
endmodule