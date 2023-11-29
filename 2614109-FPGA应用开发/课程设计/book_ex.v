// 请解释一下以下代码，如何设置input才能使程序启动
// 修改代码，将dout的值显示在数码管上
module wash_machine(clk, select,cyindex,rst,start,dout);
    output [3:0] dout;
    input clk;
    input select;
    input start,rst;
    input[3:0] cyindex;

    parameter
        t1=8'h60,
        t2=8'h05,
        t3=8'h60,
        t4=8'h05;

    reg[3:0] dout;
    reg[7:0] timer,number;
    reg switch;
    reg label;
    reg warning=0;
    reg[2:0] state;
    reg clk_out = 0;
    reg [25:0] cnt;
    reg[2:0] status;
    wire sub,en_warning;

    assign sub=((state == 0 && timer == 2 && status == 2) || !start || rst);
    assign en_warning=(!number&&start);

    always@(posedge clk)
        begin
            if(cnt<25000000)
                cnt<= cnt+1;
            else
                begin
                    clk_out<=~clk_out;
                    cnt<=0;
                end
        end

    always @(posedge clk_out)
        begin
            if(!rst)
                begin
                    label<=0;
                    if(start&&!label)
                        begin
                            if(!switch&&number)
                                begin
                                    switch<=1;
                                    case(state)
                                        0:begin
                                            timer<=t1;
                                            status<=4;
                                            state<=1;
                                        end
                                        1:begin
                                            timer<=t2;
                                            status<=2;
                                            state<= 2;
                                        end
                                        2:begin
                                            timer<=t3;
                                            status<=1;
                                            state<=3;
                                        end
                                        3:begin
                                            timer<=t4;
                                            status<=2;
                                            state<=0;
                                        end
                                        default:status<=2;
                                    endcase
                                end
                            else
                                begin
                                    if(timer[3:0]>4'h0)
                                        timer[3:0]<= timer[3:0]-4'h1;
                                    else if(timer[7:4]>4'h0)
                                        begin
                                            timer[3:0]<=4'h9;
                                            timer[7:4]<=timer[7:4]-4'h1;
                                        end
                                    else
                                        begin
                                            timer[3:0]<= timer[3:0];
                                            timer[7:4]<=timer[7:4];
                                        end
                                    if(timer[7:0]==2)
                                        switch<=0;
                                end
                        end
                end
            else
                begin
                    state <= 0;
                    timer <= 0;
                    switch <= 0;
                    status<=2;
                    label<=1; 
                end 
        end

    always @(negedge sub)
        begin 
            if(!timer&&!number) 
                number <= cyindex; 
            else if(timer==0&&status==2) 
                number<=0; 
            else if(timer) 
                number<= number-1; 
        end

    always @(posedge clk_out)
        begin 
            if(en_warning) 
                warning =~warning; 
            else 
                warning =0; 
        end

    always @(posedge clk)
        if(!select) 
            dout <= number; 
        else 
            begin 
                dout[3]<= warning; 
                dout[2:0]<=status[2:0]; 
            end


endmodule
