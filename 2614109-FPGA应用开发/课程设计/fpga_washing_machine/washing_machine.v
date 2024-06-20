module washing_machine(
    input clk,
    input reset,
    input cover_closed,
    input water_connected,
    input pause,
    input start,
    input [1:0] mode,
    
    output reg [6:0] number_out,
    output reg [6:0] state_out,
    output reg [6:0] timer_out,
    output reg warning_out
);

// ���峣��
localparam IDLE = 2'b00;
localparam WATER_IN = 2'b01;
localparam FORWARD = 2'b10;
localparam REVERSE = 2'b11;

localparam NORMAL_WASH = 2'b00;
localparam WOOL_WASH = 2'b01;
localparam QUICK_WASH = 2'b10;

// �������
reg warning;
reg [31:0] counter;
reg [25:0] cnt;
reg preparing;
reg [2:0] status; // ���� status ���������ڼ�¼����״̬�ı仯
reg [1:0] last_state; // ���� last_state ���������ڼ�¼ state ������ǰһ��ֵ
reg start_debouncing; // ������������������ʱ��ʧstatus
reg clk_out = 0;
reg [3:0] number;
reg [1:0] state;
reg [31:0] timer;

always @(posedge clk) begin //50MHz ��Ƶ 1 Hz 
    if (cnt < 25000000)
        cnt <= cnt + 1;
    else begin
        clk_out <= ~clk_out;
        cnt <= 0;
    end
end

always @(posedge clk_out) begin
    if (reset) begin
        state <= IDLE;
        timer <= 0;
        number <= 0;
        counter <= 0;
        warning <= 0;
        preparing <= 1; // ��ʼ״̬Ϊ׼���׶�
        last_state <= IDLE; // ��ʼ״̬Ϊ IDLE
        status <= 2; // ��ʼ״̬Ϊ 2
        start_debouncing <= 0;
    end else if (start && cover_closed && water_connected) begin
        warning <= 0; // turn off warning when starting
        case (mode)
            NORMAL_WASH: begin
                if (preparing) begin // ׼���׶�
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // ���������˶� status ���ж�
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && timer == 0) begin // ���������˶� status ���ж�
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && timer == 0) begin // ���������˶� status ���ж�
                        preparing <= 0; // ���빤���׶�
                        start_debouncing <= 0; // ������������
                        status <= 3;//���ù����׶�ѭ��������
                    end else if (timer > 0) begin
                        timer <= timer -1; // ��ʱ������ʱ
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end 
                end else begin // �����׶�
                    if (status == 3  && number < 8 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 10; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 2 && number < 8 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && number <8 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=10; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && number<8 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//ѭ��������һ��
                      status<=3;//���ù����׶�״̬��
                    end else if (number>=8 && timer == 0) begin
                      warning<=~warning;//ģʽ���������������źš�
                      preparing<=1;//����׼���׶Ρ�
                      number<=0;//����ѭ��������
                      status<=2;//����׼���׶�״̬��
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//��ʱ������ʱ��
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end
                    
                end // else: �����׶�
            end

            WOOL_WASH: begin
                if (preparing) begin // ׼���׶�
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // ���������˶� status ���ж�
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && timer == 0) begin // ���������˶� status ���ж�
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && timer == 0) begin // ���������˶� status ���ж�
                        preparing <= 0; // ���빤���׶�
                        start_debouncing <= 0; // ������������
                        status <= 3;//���ù����׶�ѭ��������
                    end else if (timer > 0) begin
                        timer <= timer -1; // ��ʱ������ʱ
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end 
                end else begin // �����׶�
                    if (status == 3  && number < 11 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 5; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 2 && number < 11 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && number < 11 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=5; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && number< 11 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//ѭ��������һ��
                      status<=3;//���ù����׶�״̬��
                    end else if (number>= 11 && timer == 0) begin
                      warning<=~warning;//ģʽ���������������źš�
                      preparing<=1;//����׼���׶Ρ�
                      number<=0;//����ѭ��������
                      status<=2;//����׼���׶�״̬��
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//��ʱ������ʱ��
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end
                    
                end // else: �����׶�
            end

            QUICK_WASH: begin
                if (preparing) begin // ׼���׶�
                    if (status == 2 && timer == 0 && start_debouncing == 1) begin // ���������˶� status ���ж�
                        state <= IDLE;
                        start_debouncing <= 1;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && timer == 0) begin // ���������˶� status ���ж�
                        state <= WATER_IN;
                        timer <= 3;
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && timer == 0) begin // ���������˶� status ���ж�
                        preparing <= 0; // ���빤���׶�
                        start_debouncing <= 0; // ������������
                        status <= 3;//���ù����׶�ѭ��������
                    end else if (timer > 0) begin
                        timer <= timer -1; // ��ʱ������ʱ
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end 
                end else begin // �����׶�
                    if (status == 3  && number < 6 && timer == 0 && start_debouncing == 1) begin
                        state <= FORWARD;
                        timer <= 10; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 2 && number < 6 && timer == 0) begin
                        state <= IDLE;
                        timer <= 1; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 1 && number <8 && timer == 0)begin 
                        state<=REVERSE; 
                        timer<=10; 
                        status <= status - 1; // ���� status ������ֵ
                    end else if (status == 0 && number<6 && timer == 0)begin
                      state<=FORWARD;
                      timer<=2;
                      number <= number + 1;//ѭ��������һ��
                      status<=3;//���ù����׶�״̬��
                    end else if (number>=6 && timer == 0) begin
                      warning<=~warning;//ģʽ���������������źš�
                      preparing<=1;//����׼���׶Ρ�
                      number<=0;//����ѭ��������
                      status<=2;//����׼���׶�״̬��
                    end else if(timer>0 && start_debouncing == 1) begin
                      timer<=timer-1;//��ʱ������ʱ��
                    end else if (timer == 0 && start_debouncing == 0) begin
                        timer <= 2; // ��������Ϊ��һ��state��timer��ֵ
                        start_debouncing <= 1;
                    end
                    
                end // else: �����׶�
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
        4'b0000:number_out=7'b1000000;
        4'b0001:number_out=7'b1111001;
        4'b0010:number_out=7'b0100100;
        4'b0011:number_out=7'b0110000;
        4'b0100:number_out=7'b0011001;
        4'b0101:number_out=7'b0010010;
        4'b0110:number_out=7'b0000010;
        4'b0111:number_out=7'b1111000;
        4'b1000:number_out=7'b0000000;
        4'b1001:number_out=7'b0010000;
        4'b1010:number_out=7'b0001000;
        4'b1011:number_out=7'b0000011;
        default:number_out=7'b0000000;

    endcase

    case (timer)
        4'b0000: timer_out=7'b1000000;
        4'b0001: timer_out=7'b1111001;
        4'b0010: timer_out=7'b0100100;
        4'b0011: timer_out=7'b0110000;
        4'b0100: timer_out=7'b0011001;
        4'b0101: timer_out=7'b0010010;
        4'b0110: timer_out=7'b0000010;
        4'b0111: timer_out=7'b1111000;
        4'b1000: timer_out=7'b0000000;
        4'b1001: timer_out=7'b0010000;
        4'b1010: timer_out=7'b0001000;
        4'b1011: timer_out=7'b0000011;
        default: timer_out=7'b0000000;
    endcase

    warning_out = warning; // display warning on warning_out

end

endmodule // washing_machine
