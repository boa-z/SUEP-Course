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