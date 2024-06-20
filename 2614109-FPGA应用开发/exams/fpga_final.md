# fpga_final

期末考试:

* 和计数器与数码显示有关
* 仅需要仿真波形，不需要下载到开发板

## 来点AI

> To provide a good prompt to Bing, you can try to be as specific as possible about what you are looking for. For example, instead of asking “What is the weather like?”, you can ask “What is the weather like in Seattle today?”. This will help Bing understand exactly what you are looking for and provide more accurate results.
You can also try to use natural language when asking your question. Instead of using keywords like “weather” or “news”, try to ask your question in a way that you would ask a friend. This will help Bing understand the context of your question and provide more relevant results.
Finally, if you are not getting the results you are looking for, try rephrasing your question or breaking it down into smaller parts. Sometimes a small change in wording can make a big difference in the results you get.

[ChatGFT中文提示词秘籍 (prompt圣经）K-Render整理](https://qddmercny4.feishu.cn/sheets/shtcnMklYu0WsXEDUXXanrSEB2m)

please use verilog to code: ...

## 正文

题目：设计一个模 N+3 计数器(N 为学号最后一位)，结构框图如下图所示。

please use verilog to code: 设计一个模 4 计数器
用 SW0 作为使能信号，时钟通过 key0 产生，即每按一次key0，就产生一个上升沿；
输出通过 hex0 输出到7段数码管 16进制显示，同时输出结果 count。
当 SW0 = 1 时，每按一次key0, hex0 上显示的数宇就加 1。当 SW0 = 0 时，每按一次 key0, hex0 上显示的数字就减 1。

扩展部分：手动按钮key0 控制改由 N+5 分频实现 (N 为学号最后一位数)。

key0 控制改由 6 分频实现

---

修改这段代码，使计数结果到3时，计数器清零

```v
module counter_4(
    input key0,
    input reset,
    input sw0,
    output reg [3:0] count,
    output reg [3:0] hex0
);

always @(posedge key0) begin
    if (reset) begin
        count <= 4'b0000;
        hex0 <= 4'b0000;
    end else if (sw0) begin
        if (count == 4'b1111) begin
            count <= 4'b0000;
        end else begin
            count <= count + 1;
        end
    end else begin
        if (count == 4'b0000) begin
            count <= 4'b1111;
        end else begin
            count <= count - 1;
        end
    end

    case(count)
        4'b0000 : hex0 <= 4'b1111; // display "0"
        4'b0001 : hex0 <= 4'b0110; // display "1"
        4'b0010 : hex0 <= 4'b1101; // display "2"
        4'b0011 : hex0 <= 4'b1110; // display "3"
        default : hex0 <= 4'bxxxx; // don't display anything
    endcase

end

endmodule
```

在这个例子中，我们使用了一个时钟信号和一个复位信号。当复位信号为高电平时，计数器会被重置为零。当使能信号为高电平时，计数器会开始计数。当计数器达到最大值时，它会被重置为零。当使能信号为低电平时，计数器会开始倒数。当计数器达到最小值时，它会被重置为最大值。

希望这可以帮助您实现您的设计！如果您有任何其他问题，请随时问我。

---

这是一个计数器模块，用于计数。在这个模块中，SW0 作为使能信号，时钟通过 key0 产生，即每按一次key0，就产生一个上升沿。输出通过 hex0 输出到7段数码管 16进制显示，同时输出结果 count。当 SW0 = 1 时，每按一次key0, hex0 上显示的数宇就加 1。当 SW0 = 0 时，每按一次 key0, hex0 上显示的数字就减 1。

代码中有以下错误：
- 在 module 的 output 中，q 和 count 的位置颠倒了。
- 在 always 块中，else if 和 else 的位置颠倒了。
- 在 always 块中，if (count == 4'b0000) 应该改为 if (sw0)。
- 在 always 块中，else if (sw0) 的 begin 和 end 多余了。
- 在 always 块中，count == 3 应该改为 q == 3。
- 在 always 块中，cout 应该改为 count。

以下是修改后的代码：

```verilog
module counter_4(
    input key0,
    input reset,
    input sw0,
    output reg [3:0] q,
    output reg [3:0] count,
    output reg [6:0] hex0
);

always @(posedge key0) begin
    if (reset) begin
        count <= 4'b0000;
        hex0 <= 4'b0000;
    end else if (sw0) begin
        if (q==3) begin 
            q<=0;
            count = count+1'b1;
        end else q <= q+1'b1;
    end else begin
        if (sw0) begin
            if (q == 3) begin
                q<=0;
                count = count-1'b1;
            end else q <= q+1'b1;
        end
    end

    case(count)
        4'h0: hex0=7'b0000001; //0
        4'h1: hex0=7'b1001111; //1
        4'h2: hex0=7'b0010010; //2
        4'h3: hex0=7'b0000110; //3
        4'h4: hex0=7'b1001100; //4
        default: hex0=7'b1111111; 
    endcase

end

endmodule
```

## 参考代码

### 数码显示

7段数码管显示

```asm
module num_7seg (hex,c);
input[3:0] c;
output[6:0] hex;
reg[6:0] hex;

always @(c)
    begin
        case(c) 
            3'b0000: hex=7'b0000001; //0
            3'b0001: hex=7'b1001111; //1
            3'b0010: hex=7'b0010010; //2
            3'b0011: hex=7'b0000110; //3
            3'b0100: hex=7'b1001100; //4
            3'b0101: hex=7'b0100100; //5
            3'b0110: hex=7'b0100000; //6
            3'b0111: hex=7'b0001111; //7
            3'b1000: hex=7'b0000010; //8
            3'b1001: hex=7'b0000100; //9
            default: hex=7'b1111111; 
        endcase
    end
endmodule
```

### 计数器

模为6的计数器，将其修改为模为4的计数器

```v
module counter_6(q,clk,en,clr,cout);
input clk,en,clr;
output[3:0] q;
output cout;
reg[3:0] q;
reg cout;
always @ (posedge clk or negedge clr)
    begin
        if (!clr)
            begin
                q<=0; 
            end 
        else if (en)
            begin
                if (q==5) 
                    begin 
                        q<=0;
                        cout = ~cout;
                    end
                else q <= q+1'b1;
            end
    end
endmodule
```

4

```v
module counter_4(q,clk,en,clr,cout);
input clk,en,clr;
output[3:0] q;
output cout;
reg[3:0] q;
reg cout;
always @ (posedge clk or negedge clr)
    begin
        if (!clr)
            begin
                q<=0; 
            end 
        else if (en)
            begin
                if (q==3) 
                    begin 
                        q<=0;
                        cout = ~cout;
                    end
                else q <= q+1'b1;
            end
    end
endmodule
```

---

你好，你可以将代码修改为以下内容，当计数器到达3时，计数器会清零：

```verilog
module counter_4(
    input key0,
    input reset,
    input sw0,
    output reg [3:0] count,
    output reg [6:0] hex0
);

always @(posedge key0) begin
    if (reset) begin
        count <= 4'b0000;
        hex0 <= 4'b0000;
    end else if (sw0) begin
        if (count == 4'b1111) begin
            count <= 4'b0000;
        end else begin
            count <= count + 1;
        end
    end else begin
        if (count == 4'b0000) begin
            count <= 4'b1111;
        end else if (count == 4'b0011) begin // added this line to reset counter when it reaches 3
            count <= 4'b0000;
        end else begin
            count <= count - 1;
        end
    end

    case(count)
        3'b0000: hex0 <= 7'b0000001; //0
        3'b0001: hex0 <= 7'b1001111; //1
        3'b0010: hex0 <= 7'b0010010; //2
        3'b0011: hex0 <= 7'b0000110; //3
        3'b0100: hex0 <= 7'b1001100; //4
        default: hex0 <= 7'b1111111; 
    endcase

end

endmodule

```

这里我们在else if语句中添加了一个条件，当计数器到达3时，计数器会清零。¹

---

```v
module counter_4(
    input key0,
    input reset,
    input sw0,
    output reg [3:0] count,
    output reg [6:0] hex0
);

always @(posedge key0) begin
    if (reset) begin
        count <= 4'b0000;
        hex0 <= 4'b0000;
    end else if (sw0) begin
        if (count == 4'b0011) begin
            count <= 4'b0000;
        end else begin
            count <= count + 1;
        end
    end else begin
        if (count == 4'b0000) begin
            count <= 4'b0011;
        end else if (count == 4'b0011) begin // added this line to reset counter when it reaches 3
            count <= 4'b0000;
        end else begin
            count <= count - 1;
        end
    end
```

---

你可以将代码修改为以下内容，使key0控制6分频实现：

```verilog
module counter_4(
    input key0,
    input reset,
    input sw0,
    output reg [3:0] count,
    output reg [6:0] hex0
);

reg [2:0] div_counter;

always @(posedge key0) begin
    if (reset) begin
        count <= 4'b0000;
        hex0 <= 4'b0000;
        div_counter <= 3'b000;
    end else if (sw0) begin
        if (div_counter == 3'b100) begin
            div_counter <= 3'b000;
            if (count == 4'b1111) begin
                count <= 4'b0000;
            end else begin
                count <= count + 1;
            end
        end else begin
            div_counter <= div_counter + 1;
        end
    end else begin
        if (div_counter == 3'b100) begin
            div_counter <= 3'b000;
            if (count == 4'b0000) begin
                count <= 4'b1111;
            end else if (count == 4'b0011) begin // added this line to reset counter when it reaches 3
                count <= 4'b0000;
            else begin
                count <= count - 1;
            end
        end else begin
            div_counter <= div_counter + 1;
        end
    end

    case(count)
        3'b0000: hex0 <= 7'b0000001; //0
        3'b0001: hex0 <= 7'b1001111; //1
        3'b0010: hex0 <= 7'b0010010; //2
        3'b0011: hex0 <= 7'b0000110; //3
        3'b0100: hex0 <= 7'b1001100; //4
        default: hex0 <= 7'b1111111; 
    endcase

end

endmodule

```

这里我们添加了一个名为`div_counter`的计数器，用于计算key0的6分频。当`div_counter`到达100时，计数器会加一。²
