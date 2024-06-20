# tmp

使用 Verilog 实现以下功能 (有限状态机)

实验板共4个LED灯，该实验实现它们的组合显示。具体功能如下：

(1) 模式1：先点亮奇数的LED灯，即1、3，后点亮偶数的LED灯，即2、4，依次循环。

(2) 模式2：按照1、2、3、4的顺序依次点亮所有LED灯，然后再按该顺序依次熄灭所有LED灯。

(3) 模式3：每次只点亮一个LED灯，亮灯顺序为1、2、3、4、3、2，按照该顺序循环。

(4) 模式4：按照1/4、2/3的顺序依次点亮所有灯，每次同时点亮两个LED灯；然后再按该顺序依次熄灭所有LED灯，每次同时熄灭两个LED灯。

注：

点亮与熄灭的时间间隔均为0.25s。

在演示过程中，只有当一种模式演示完毕才能转向其他演示模式。

Using Verilog to implement the following (finite state machine)
The experimental board has a total of 4 LED lights, and the experiment realizes their combination display. The specific functions are as follows:
(1) Mode 1: First light the odd number of LED lights, namely 1, 3, and then light the even number of LED lights, namely 2, 4, in turn cycle.
(2) Mode 2: Light up all LED lights in the order of 1, 2, 3 and 4, and then turn off all LED lights in the order.
(3) Mode 3: only one LED light is lit each time, and the lighting order is 1, 2, 3, 4, 3, 2, and the cycle is in this order.
(4) Mode 4: light up all lights in the order of 1/4 and 2/3, and light up two LED lights at the same time. Then all LED lights are turned off in that order, and two LED lights are turned off at the same time each time.

Note:
The time interval between lighting and quenching was 0.25s for both.
In the course of the demonstration, only when one mode is demonstrated can it turn to other demonstration modes.

use verilog to code, and there is 4 light: First light the odd number of LED lights, namely 1, 3, and then light the even number of LED lights, namely 2, 4, in turn cycle.
use verilog to code, and there is 4 light: light up all lights in the order of 1/4 and 2/3, and light up two LED lights at the same time. Then all LED lights are turned off in that order, and two LED lights are turned off at the same time each time.

使用 Verilog 实现以下功能：写一个module，操作4个LED顺序点亮，LED灯点亮与熄灭的时间间隔均为0.25s。

```v
module led_blink(
    input clk,
    input rst,
    output reg [3:0] led
);

parameter CNT_MAX = 12500000; // 0.25s at 50MHz clock
reg [24:0] cnt;

always @(posedge clk) begin
    if (rst) begin
        cnt <= 0;
        led <= 4'b0001;
    end else begin
        if (cnt == CNT_MAX) begin
            cnt <= 0;
            led <= {led[2:0], led[3]};
        end else begin
            cnt <= cnt + 1;
        end
    end
end

endmodule
```

---

From Bing AI

```verilog
module FSM_4led(
    input clk,
    input rst,
    input [1:0] mode,
    output reg [3:0] led
);

parameter T = 12500000; // 0.25s at 50MHz clock
reg [31:0] cnt;
reg [2:0] state;

always @(posedge clk) begin
    if (rst) begin
        cnt <= 0;
        state <= 0;
        led <= 4'b0000;
    end else begin
        if (cnt == T) begin
            cnt <= 0;
            case (mode)
                2'b00: begin // Mode 1
                    case (state)
                        3'b000: led <= 4'b0101;
                        3'b001: led <= 4'b1010;
                        default: led <= 4'b0000;
                    endcase
                    state <= state + 1;
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
                end
            endcase
        end else begin
            cnt <= cnt + T;
        end
    end
end

endmodule
```

---

以下verilog代码有几种工作状态，见注释中的(Mode 1等)，修改代码，使切换模式后，首先进行清零

```verilog
module FSM_4led(
    input clk,
    input rst,
    input [1:0] mode,
    output reg [3:0] led
);

parameter T = 12500000; // 0.25s at 50MHz clock
reg [31:0] cnt;
reg [2:0] state;

always @(posedge clk) begin
    if (rst) begin
        cnt <= 0;
        state <= 0;
        led <= 4'b0000;
    end else begin
        if (cnt == T) begin
            cnt <= 0;
            case (mode)
                2'b00: begin // Mode 1
                    case (state)
                        3'b000: led <= 4'b0101;
                        3'b001: led <= 4'b1010;
                        default: led <= 4'b0000;
                    endcase
                    state <= state + 1;
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
                end else begin
            cnt <= cnt + T;
        end
    end
end

endmodule
```
