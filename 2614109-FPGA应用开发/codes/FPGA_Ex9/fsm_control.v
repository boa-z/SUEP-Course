module fsm_control (
    clk, reset,
    W1, W2, W3,
    C1, C2, C3,
    R1, Y1, G1,
    R2, Y2, G2
);
    input clk, reset;
    input W1, W2, W3;
    output R1, Y1, G1, R2, Y2, G2;
    output C1, C2, C3;
    
    wire C1, C2, C3;
    wire R1, Y1, G1, R2, Y2, G2;
    
    reg [1:0] state;
    
    parameter S0 = 2'b00,
              S1 = 2'b01,
              S2 = 2'b11,
              S3 = 2'b10;
              
    always @ (posedge clk) begin
        if (reset) state <= S0;
        else case (state)
            S0: begin
                if (W1 == 1) state <= S1;
                else state <= S0;
            end
            S1: begin
                if (W2 == 1) state <= S2;
                else state <= S1;
            end
            S2: begin
                if (W3 == 1) state <= S3;
                else state <= S2;
            end
            S3: begin
                if (W2 == 1) state <= S0;
                else state <= S3;
            end
        endcase
    end
    
    assign C1 = (state == S0) ? 1'b1 : 1'b0;
    assign C2 = (state == S1 || state == S3) ? 1'b1 : 1'b0;
    assign C3 = (state == S2) ? 1'b1 : 1'b0;
    
    assign G1 = (state == S0) ? 1'b1 : 1'b0;
    assign Y1 = (state == S1) ? 1'b1 : 1'b0;
    assign R1 = (state == S2 || state == S3) ? 1'b1 : 1'b0;
    
    assign G2 = (state == S2) ? 1'b1 : 1'b0;
    assign Y2 = (state == S3) ? 1'b1 : 1'b0;
    assign R2 = (state == S0 || state == S1) ? 1'b1 : 1'b0;

endmodule
