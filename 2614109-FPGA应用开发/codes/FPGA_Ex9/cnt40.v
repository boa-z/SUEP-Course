module cnt40 (clk, enable, W);
    input clk, enable; //1Hz 时钟信号，同步使能信号
    output W; //定时器状态指示信号
    reg [6:0] cnt;
    reg W;
    always @ (posedge clk)
    begin
        if (enable == 1'b1 && cnt < 40)
            cnt = cnt + 1'b1;
        else
            cnt = 0;
        if (cnt == 40)
            W = 1;
        else
            W = 0;
    end
endmodule