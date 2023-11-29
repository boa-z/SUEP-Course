module and2gate (y, a, b);
input a,b;
output y;
reg y;
always @ ( a or b)
	y<=a & b;

endmodule