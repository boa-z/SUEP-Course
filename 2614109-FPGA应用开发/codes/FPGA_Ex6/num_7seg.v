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