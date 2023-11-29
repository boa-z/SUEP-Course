module top (
    input clk,
    input reset,
    output R1, Y1, G1,
    output R2, Y2, G2
);

    wire C1, C2, C3;
    wire W1, W2, W3;
    
    fsm_control fsm_control_inst (
        .clk(clk),
        .reset(reset),
        .W1(W1),
        .W2(W2),
        .W3(W3),
        .C1(C1),
        .C2(C2),
        .C3(C3),
        .R1(R1),
        .Y1(Y1),
        .G1(G1),
        .R2(R2),
        .Y2(Y2),
        .G2(G2)
    );
    
    cnt40 cnt40_inst (
        .clk(clk),
        .enable(C1),
        .W(W1)
    );
    
    cnt45 cnt45_inst (
        .clk(clk),
        .enable(C2),
        .W(W2)
    );
    
    cnt5 cnt5_inst (
        .clk(clk),
        .enable(C3),
        .W(W3)
    );

endmodule