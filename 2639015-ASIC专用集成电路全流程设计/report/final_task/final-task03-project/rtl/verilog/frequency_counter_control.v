`timescale 1ns/1ps

module frequency_counter_control(
    input wire Clk,
    input wire Clear,
    input wire Cntover,
    input wire Cntlow,
    output reg reset,
    output reg [1:0] std_f_sel,
    output reg [2:0] range
);
    reg [2:0] state, next_state;

    // 定义状态参数
    localparam STATE_A = 3'b000, // 100K stateA
               STATE_B = 3'b001, // 100K stateB
               STATE_C = 3'b010, // 10K stateC
               STATE_D = 3'b011, // 10K stateD
               STATE_E = 3'b100, // 1K stateE
               STATE_F = 3'b101; // 1K stateF

    // 时序逻辑：状态切换
    always @(posedge Clk or posedge Clear) begin
        if (Clear)
            state <= STATE_C;  // 初始化为 STATE_C
        else
            state <= next_state;
    end

    // 组合逻辑：状态转移和输出控制
    always @(*) begin
        // 默认值初始化，减少冗余赋值
        range = 3'b010;
        std_f_sel = 2'b01;
        reset = 1;
        next_state = state;  // 默认保持当前状态

        case (state)
            STATE_A: begin
                range = 3'b000;
                std_f_sel = 2'b00;
                next_state = STATE_B;
            end

            STATE_B: begin
                range = 3'b000;
                std_f_sel = 2'b00;
                reset = 0;
                if (Cntlow)
                    next_state = STATE_C;
            end

            STATE_C: begin
                range = 3'b010;
                std_f_sel = 2'b01;
                next_state = STATE_D;
            end

            STATE_D: begin
                range = 3'b010;
                std_f_sel = 2'b01;
                reset = 0;
                if (Cntover)
                    next_state = STATE_A;
                else if (Cntlow)
                    next_state = STATE_E;
            end

            STATE_E: begin
                range = 3'b100;
                std_f_sel = 2'b11;
                next_state = STATE_F;
            end

            STATE_F: begin
                range = 3'b100;
                std_f_sel = 2'b11;
                reset = 0;
                if (Cntover)
                    next_state = STATE_C;
            end

            default: begin
                next_state = STATE_C;
            end
        endcase
    end
endmodule
