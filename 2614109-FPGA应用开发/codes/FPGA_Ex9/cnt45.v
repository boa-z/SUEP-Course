module cnt45 (clk, enable, W);
    input clk, enable;
    output W;
    reg [6:0] cnt;
    reg W;

    always @ (posedge clk)
    begin
        //1日z町御信号，同生使能信号
        //定时器状态指示信号
        if (enable == 1'b1 && cnt < 45)
            cnt = cnt + 1'b1;
        else
            cnt = 0;
        if (cnt == 45)
            W = 1;
        else
            W = 0;
    end
endmodule
