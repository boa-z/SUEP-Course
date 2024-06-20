module bin_bcd
  ( input wire[3:0] bin,  // binary
    output reg[3:0] d1,d0); // bcd

always @(bin)
begin
    if (bin <= 4'b1001) begin
        d1 <= 0;
        d0 <= bin;
    end
    else begin
        d1 <= 1;
        d0 <= bin - 10;
    end

end

endmodule