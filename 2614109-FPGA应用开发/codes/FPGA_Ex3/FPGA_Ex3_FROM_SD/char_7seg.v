module char_7seg (hex,c);
input[2:0] c;
output[6:0] hex;
reg[6:0] hex;
always @(c)
	begin
		case(c)
			3'b000: hex=7'b0001001;
			3'b001: hex=7'b0000110;
			3'b010: hex=7'b1000111;
			3'b011: hex=7'b1000000;
			default: hex=7'b1111111;
		endcase
	end
endmodule