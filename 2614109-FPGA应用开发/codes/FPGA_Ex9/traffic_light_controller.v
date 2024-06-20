module traffic_light_controller(
    input clk,
    input urgency,
    output reg [1:0] east_west,
    output reg [1:0] south_north,
    output reg [7:0] countdown
);

// 计数器
reg [7:0] counter;
// 状态
reg [1:0] state;

// 状态转换
always @ (posedge clk) begin
    if (counter == 0) begin
        case (state)
            2'b00: begin
                state <= 2'b01;
                counter <= 45;
                east_west <= 2'b10;
                south_north <= 2'b00;
            end
            2'b01: begin
                state <= 2'b10;
                counter <= 5;
                east_west <= 2'b10;
                south_north <= 2'b01;
            end
            2'b10: begin
                state <= 2'b11;
                counter <= 40;
                east_west <= 2'b00;
                south_north <= 2'b10;
            end
            2'b11: begin
                state <= 2'b00;
                counter <= 5;
                east_west <= 2'b01;
                south_north <= 2'b10;
            end
        endcase
    end else begin
        counter <= counter - 1;
    end

    // 更新倒计时输出
    countdown <= counter;
end

endmodule