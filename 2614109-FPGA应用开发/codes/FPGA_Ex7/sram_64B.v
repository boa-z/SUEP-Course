module sram_64B (dataout, datain, addr, clk,wren);
    input clk, wren;
    input [5:0] addr;
    input [7:0] datain;
    output [7:0] dataout;
    reg [7:0] dataout;
    (* ramstyle="no_rw_check, m4k", ram_init_file="sram_init.mif" *) reg [7:0] sram [63:0];
    
    integer i = 0;
    
    always @ (posedge clk) begin
        if (wren)
            sram[addr] <= datain; //Write data
        else begin
            dataout <= sram[i]; //Read data
            i <= i + 1;
            if (i == 16)
                i <= 0;
        end
    end
endmodule