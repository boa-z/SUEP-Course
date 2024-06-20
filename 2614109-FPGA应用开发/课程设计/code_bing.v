module washing_machine(
    input clk,
    input reset,
    input cover_closed,
    input water_connected,
    input pause,
    input start,
    input [1:0] mode,
    output reg warning,
    output reg [1:0] state,
    output reg [3:0] number,
    output reg [6:0] number_out,
    output reg [6:0] state_out,
    output reg [6:0] timer_out,
    output reg warning_out,
    output reg [2:0] status, // 定义 status 变量，用于记录工作状态的变化
    output reg [31:0] timer
);

// 定义常量
localparam IDLE = 2'b00;
localparam WATER_IN = 2'b01;
localparam FORWARD = 2'b10;
localparam REVERSE = 2'b11;

localparam NORMAL_WASH = 2'b00;
localparam WOOL_WASH = 2'b01;
localparam QUICK_WASH = 2'b10;

// 定义变量
reg [31:0] counter;
reg preparing;
reg [1:0] last_state; // 定义 last_state 变量，用于记录 state 变量的前一个值
reg start_debouncing; // 启动消抖，避免启动时丢失status

always @(posedge clk) begin
    if (reset) begin
        state <= IDLE;
        timer <= 0;
        number <= 0;
        counter <= 0;
        warning <= 0;
        preparing <= 1; // 初始状态为准备阶段
        last_state <= IDLE; // 初始状态为 IDLE
        status <= 2; // 初始状态为 2
        start_debouncing <= 0;
    end else if (start && cover_closed && water_connected) begin
        warning <= 0; // turn off warning when starting
        case (mode)
            NORMAL_WASH: begin
                if (preparing) begin // 准备阶段
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // 这里增加了对 status 的判断
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && timer == 0) begin // 这里增加了对 status 的判断
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && timer == 0) begin // 这里增加了对 status 的判断
                        preparing <= 0; // 进入工作阶段
                        start_debouncing <= 0; // 重制启动消抖
                        status <= 3;//设置工作阶段循环次数。
                    end else if (timer > 0) begin
                        timer <= timer -1; // 计时器倒计时
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end 
                end else begin // 工作阶段
                    if (status == 3  && number < 8 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 10; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 2 && number < 8 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && number <8 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=10; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && number<8 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//循环次数加一。
                      status<=3;//重置工作阶段状态。
                    end else if (number>=8 && timer == 0) begin
                      warning<=~warning;//模式结束，发出警告信号。
                      preparing<=1;//进入准备阶段。
                      number<=0;//重置循环次数。
                      status<=2;//重置准备阶段状态。
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//计时器倒计时。
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end
                    
                end // else: 工作阶段
            end

            WOOL_WASH: begin
                if (preparing) begin // 准备阶段
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // 这里增加了对 status 的判断
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && timer == 0) begin // 这里增加了对 status 的判断
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && timer == 0) begin // 这里增加了对 status 的判断
                        preparing <= 0; // 进入工作阶段
                        start_debouncing <= 0; // 重制启动消抖
                        status <= 3;//设置工作阶段循环次数。
                    end else if (timer > 0) begin
                        timer <= timer -1; // 计时器倒计时
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end 
                end else begin // 工作阶段
                    if (status == 3  && number < 11 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 5; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 2 && number < 11 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && number < 11 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=5; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && number< 11 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//循环次数加一。
                      status<=3;//重置工作阶段状态。
                    end else if (number>= 11 && timer == 0) begin
                      warning<=~warning;//模式结束，发出警告信号。
                      preparing<=1;//进入准备阶段。
                      number<=0;//重置循环次数。
                      status<=2;//重置准备阶段状态。
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//计时器倒计时。
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end
                    
                end // else: 工作阶段
            end

            QUICK_WASH: begin
                if (preparing) begin // 准备阶段
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // 这里增加了对 status 的判断
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && timer == 0) begin // 这里增加了对 status 的判断
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && timer == 0) begin // 这里增加了对 status 的判断
                        preparing <= 0; // 进入工作阶段
                        start_debouncing <= 0; // 重制启动消抖
                        status <= 3;//设置工作阶段循环次数。
                    end else if (timer > 0) begin
                        timer <= timer -1; // 计时器倒计时
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end 
                end else begin // 工作阶段
                    if (status == 3  && number < 6 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 10; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 2 && number < 6 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 1 && number <8 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=10; 
                        status <= status - 1; // 更新 status 变量的值
                    end else if (status == 0 && number<6 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//循环次数加一。
                      status<=3;//重置工作阶段状态。
                    end else if (number>=6 && timer == 0) begin
                      warning<=~warning;//模式结束，发出警告信号。
                      preparing<=1;//进入准备阶段。
                      number<=0;//重置循环次数。
                      status<=2;//重置准备阶段状态。
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//计时器倒计时。
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // 在启动区为第一个state的timer赋值
                        start_debouncing <= 1;
                    end
                    
                end // else: 工作阶段
            end

            default: begin
                // do nothing.
            end

        endcase // case(mode)
    end else if (!cover_closed || !water_connected || pause) begin
        warning <= ~warning;
        state <= IDLE;
    end
end // always @(posedge clk)

always @(*) begin
    case (state)
        IDLE: state_out = 7'b1000000; // display "0" on state_out when in idle state
        WATER_IN: state_out = 7'b1111001; // display "1" on state_out when in water_in state
        FORWARD: state_out = 7'b0100100; // display "2" on state_out when in forward state
        REVERSE: state_out = 7'b0110000; // display "3" on state_out when in reverse state
        default: state_out = 7'b1111111;
    endcase
    
    case (number)
        4'h0: number_out = 7'b1000000;
        4'h1: number_out = 7'b1111001;
        4'h2: number_out = 7'b0100100;
        4'h3: number_out = 7'b0110000;
        4'h4: number_out = 7'b0011001;
        4'h5: number_out = 7'b0010010;
        4'h6: number_out = 7'b0000010;
        4'h7: number_out = 7'b1111000;
        4'h8: number_out = 7'b0000000;
        4'h9: number_out = 7'b0010000;
        default: number_out = 7'b1111111;
    endcase

    case (timer)
        4'h0: timer_out = 7'b1000000;
        4'h1: timer_out = 7'b1111001;
        4'h2: timer_out = 7'b0100100;
        4'h3: timer_out = 7'b0110000;
        4'h4: timer_out = 7'b0011001;
        4'h5: timer_out = 7'b0010010;
        4'h6: timer_out = 7'b0000010;
        4'h7: timer_out = 7'b1111000;
        4'h8: timer_out = 7'b0000000;
        4'h9: timer_out = 7'b0010000;
        default: timer_out = 7'b1111111;
    endcase

    warning_out = warning; // display warning on warning_out

end

endmodule // washing_machine
