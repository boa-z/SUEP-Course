module mux_2to1(
  input wire sel,
  input wire a,
  input wire b,
  output wire out
);

assign out = sel ? a : b;

endmodule

module mux_2to1_tb();

reg sel;
reg a;
reg b;
wire out;

mux_2to1 dut(
  .sel(sel),
  .a(a),
  .b(b),
  .out(out)
);

initial begin
  $monitor("sel = %b, a = %b, b = %b, out = %b", sel, a, b, out);
  
  sel = 0; a = 0; b = 1; #10;
  sel = 0; a = 1; b = 0; #10;
  sel = 1; a = 0; b = 1; #10;
  sel = 1; a = 1; b = 0; #10;
  
  $finish;
end

endmodule