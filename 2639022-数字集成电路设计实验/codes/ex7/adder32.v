module adder32 (
    // module head: verillog-2001 format
    input wire [31:0] a_in,
    input wire [31:0] b_in,
    input wire [0:0] c_in, // carry in
    output wire [31:0] sum_out,
    output wire [0:0] c_out // carry out
) ;

// behavior of the adder can be synthesizable
// "assign" means connectivity
assign {c_out, sum_out} = a_in + b_in + c_in;
endmodule