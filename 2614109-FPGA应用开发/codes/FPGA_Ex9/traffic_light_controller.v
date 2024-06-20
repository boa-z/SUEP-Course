module traffic_light_controller(
    input clk,
    input urgency,
    output reg [1:0] east_west,
    output reg [1:0] south_north,
    output reg [7:0] countdown
);

// ������
reg [7:0] counter;
// ״̬
reg [1:0] state;

// ״̬ת��
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

    // ���µ���ʱ���
    countdown <= counter;
end

endmodule