module mod50_counter(
    input clk, // 时钟信号
    input rst, // 复位信号
    input up_down, // 加减控制信号，1为加，0为减
    output reg [5:0] count // 计数器输出
);

always @(posedge clk or posedge rst) begin
    if (rst) begin // 复位时，计数器清零
        count <= 6'b0;
    end else begin // 非复位时，根据加减控制信号进行计数
        if (up_down) begin // 加法模式
            if (count == 6'b110010) begin // 如果计数器达到50，重置为0
                count <= 6'b0;
            end else begin // 否则，计数器加1
                count <= count + 1;
            end
        end else begin // 减法模式
            if (count == 6'b0) begin // 如果计数器为0，重置为50
                count <= 6'b110010;
            end else begin // 否则，计数器减1
                count <= count - 1;
            end
        end
    end
end

initial begin
    $vcdpluson; // vcdplus.vpd格式的波形文件
end

endmodule