module add8(a, b, cin, sum, cout);

input [7:0] a, b;
input cin;
output cout;
output [7:0] sum;
wire c4, c8_0, c8_1;
wire [7:4] sum_0, sum_1;

add4 u1(a[3:0], b[3:0], cin, sum[3:0], c4);
add4 low_add(a[7:4], b[7:4], 1'b0, sum_0, c8_0);
add4 high_add(a[7:4], b[7:4], 1'b1, sum_1, c8_1);
assign sum[7:4] = c4?sum_1: sum_0;
assign cout = c4?c8_1:c8_0;
endmodule