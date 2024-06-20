module mux_4to1 (m,s,u,v,w,x);
input u,v,w,x;
input[1:0] s;
output m;
reg m;

always @(s or u or v or w or x)
begin 
    case(s)
        2'b00: m=u;
        2'b01: m=v;
        2'b10: m=w;
        default: m=x;
    endcase
end
endmodule