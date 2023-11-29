module ext_sram (
	input wire clk,
    input wire [6:0] iaddr,
    input wire [7:0] idata,
    input wire ilb_n, iub_n, ioe_n, ice_n, iwe_n,
    output reg [7:0] odata,
    output reg [3:0] led
);

reg [7:0] sram_dq [0:63];
reg [3:0] read_addr = 4'd0;
integer count = 0;
reg [7:0] mif_data [15:0] = {8'h01, 8'h02, 8'h03, 8'h04, 8'h05, 8'h06, 8'h07, 8'h08, 8'h09, 8'h0A, 8'h0B, 8'h0C, 8'h0D, 8'h0E, 8'h0F, 8'h10};


assign sram_lb_n = ilb_n;
assign sram_ub_n = iub_n;
assign sram_oe_n = ioe_n;
assign sram_ce_n = ice_n;
assign sram_we_n = iwe_n;

always @(posedge sram_ce_n or negedge sram_lb_n or negedge sram_ub_n) begin
    if (!sram_ce_n && !sram_lb_n && !sram_ub_n) begin
        odata <= sram_dq[iaddr];
    end
end

always @(posedge sram_we_n) begin
    if (!sram_we_n) begin
        sram_dq[iaddr] <= idata;
    end
end

initial begin
    $readmemh("ram_init.mif", sram_dq);
end

always @ (posedge clk) begin
    if (count == 50000000) begin
        read_addr <= read_addr + 1;
        if (read_addr == 4'd16) begin
            read_addr <= 4'd0;
        end
        led <= sram_dq[read_addr];
        count <= 0;
    end else begin
        count <= count + 1;
    end
end

endmodule
