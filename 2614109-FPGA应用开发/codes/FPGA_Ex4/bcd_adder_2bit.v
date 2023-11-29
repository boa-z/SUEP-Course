module bcd_adder_2bit(
  input [3:0] a, b,
  input cin, 
  output reg [3:0] sum,
  output reg cout
);

  reg [3:0] temp_sum;
  reg [1:0] state;

  always @*
    begin
      case (state)
        2'b00:
          begin
            temp_sum = a + b;
            state = 2'b01;
          end
        2'b01:
          begin
            if (temp_sum > 4'h9)
              begin
                temp_sum = temp_sum + 4'h6;
                cout = 1'b1;
              end
            else
              cout = 1'b0;
            state = 2'b10;
          end
        2'b10:
          begin
            sum = temp_sum + cin;
            state = 2'b00;
          end
      endcase
    end

endmodule
