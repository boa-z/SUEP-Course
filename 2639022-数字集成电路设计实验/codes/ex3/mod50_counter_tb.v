module mod50_counter_tb;

// 定义信号变量
reg clk; // 时钟信号
reg rst; // 复位信号
reg up_down; // 加减控制信号
wire [5:0] count; // 计数器输出

// 实例化模50加减法计数器模块
mod50_counter uut (
    .clk(clk),
    .rst(rst),
    .up_down(up_down),
    .count(count)
);

// 初始化信号变量的值
initial begin
    clk = 0; // 初始时钟信号为0
    rst = 1; // 初始复位信号为1，使计数器清零
    up_down = 1; // 初始加减控制信号为1，使计数器进行加法操作
end

// 每隔10ns改变一次时钟信号的值，产生周期为20ns的时钟波形
always #10 clk = ~clk;

// 在仿真开始后的100ns取消复位信号，使计数器开始工作
initial #100 rst = 0;

// 在仿真开始后的500ns改变加减控制信号的值，使计数器进行减法操作
initial #500 up_down = 0;

// 在仿真开始后的1000ns结束仿真
initial #1000 $finish;

// 显示计数器的输出值和当前时间
always @(posedge clk) begin
    $display("Count = %d at time = %t", count, $time);
end

endmodule