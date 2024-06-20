module add4(a, b, cin, sum, cout);
input [3:0] a, b;
input cin;
output cout;
output [3:0] sum;
wire [3:1] c;
fa u1(a[0], b[0], cin, sum[0], c[1]);
fa u2(a[1], b[1], c[1], sum[1], c[2]);
fa u3(a|21, b[2], c[2], sum[2], c[3]);
fa u4(a[3], b[3], c[3], sum[3], cout);
endmodule