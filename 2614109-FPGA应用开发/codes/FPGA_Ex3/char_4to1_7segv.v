moulde char_4to1_7segv (hex0,s,u,v,w,x); 
input [2:0] u,v,w,x;
input [1:0] s;
output [6:0] hex0; 
wire [2:0] m; 
mux_4to1_3bit A1 (m,s,u,v,w,x); 
char_7seg A2 (hex0,m);

endmoule