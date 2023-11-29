module full_adder (ain, bin, cin, sumout, cout);
input ain;
input bin;
input cin;
output sumout, cout;
reg c_0, sum_0;
always@(ain,bin, cin)
begin
    {c_0, sum_0}=ain+bin+cin;
end
assign{cout, sumout}={c_0, sum_0};
endmodule