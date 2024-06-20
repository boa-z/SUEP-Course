module FSM_4led(
    input clk,
    input rst,
    input [1:0] mode,
    output reg [3:0] led,
    output reg [2:0] state_out
);

parameter T = 12500000; // 0.25s at 50MHz clock
reg [31:0] cnt;
reg [2:0] state;
reg [1:0] prev_mode;

always @(posedge clk) begin
    if (rst) begin
        cnt <= 0;
        state <= 0;
        led <= 4'b0000;
        prev_mode <= 2'b00; // 初始化prev_mode
    end else begin
        if (cnt == T) begin
            cnt <= 0;
            if (mode != prev_mode) begin
                state <= 0; // 将state清零
            end else begin
            case (mode)
                2'b00: begin // Mode 1
                    case (state)
                        3'b000: led <= 4'b0101;
                        3'b001: led <= 4'b1010;
                        default: led <= 4'b0000;
                    endcase
                    state <= state + 1;
                    state_out <= state;
                end
                2'b01: begin // Mode 2
                    case (state)
                        3'b000: led <= 4'b0001;
                        3'b001: led <= 4'b0011;
                        3'b010: led <= 4'b0111;
                        3'b011: led <= 4'b1111;
                        3'b100: led <= 4'b0111;
                        3'b101: led <= 4'b0011;
                        3'b110: led <= 4'b0001;
                        default: led <= 4'b0000;
                    endcase
                    state <= state + 1;
                    state_out <= state;
                end
                2'b10: begin // Mode 3
                    case (state)
                        3'b000: led <= 4'b0001;
                        3'b001: led <= 4'b0010;
                        3'b010: led <= 4'b0100;
                        3'b011: led <= 4'b1000;
                        3'b100: led <= 4'b0100;
                        3'b101: led <= 4'b0010;
                        default: led <= 4'b0000;
                    endcase
                    state <= state +1;
                    state_out <= state;
                end
                2'b11: begin // Mode 4
                    case (state)
                        3'b000: led <= 4'b1001;
                        3'b001: led <= 4'b1111;
                        3'b010: led <= 4'b0110;
                        3'b011: led <= 4'b0000;
                        default: led <= 4'b0000;
                    endcase
                    state <= state + 1;
                    state_out <= state;
                end
            endcase
            end
            prev_mode <= mode; // 更新prev_mode的值
        end else begin
            cnt <= cnt + T;
        end
    end
end

endmodule
