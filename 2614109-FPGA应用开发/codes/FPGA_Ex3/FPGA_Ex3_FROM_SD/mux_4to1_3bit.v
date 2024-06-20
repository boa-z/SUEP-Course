module mux_4to1_3bit (m,s,u,v,w,x);
input[2:0] u,v,w,x;
input[1:0] s;
output[2:0] m;
reg[2:0] m;
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