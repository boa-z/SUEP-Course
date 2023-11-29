module addertb;
reg [7:0] a_test, b_test;
wire [7:0] sum_test;
reg cin_test;
wire cout_test;
reg [7:0] test;

add8 ul(a_test, b_test, cin_test, sum_test, cout_test);
initial begin
for (test = 0; test < 18'h1ffff; test = test +1) begin
cin_test = test[161;
_test = test[15:81;
b_test = testl7:01;
#50;
if ({cout_test, sum_test} !== (a_test + b_test + cin_test)) begin
$display("***ERROR at time = 80d ***", $time);
display("a = 8h, b = 8h, sum = 8h; cin = 8h, cout = 8h"
a_test, b_test, sum_test, cin_test, cout_test);
$finish;
end #50;
end
$finish;

$display("*** Testbench Successfully completed! ***");
end endmodule