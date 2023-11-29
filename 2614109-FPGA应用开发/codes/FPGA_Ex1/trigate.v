module trigate ( dout, din,en );
input din, en;
output dout;
reg dout;
always @ ( en or din) 
	begin 
		if (en)
		dout<=din;
		else
		dout<=1'bZ; 
		end 
endmodule