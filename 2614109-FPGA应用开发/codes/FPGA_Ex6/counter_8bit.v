module counter_8bit (q, data, clock,en,sload,aclr);
    input clock,en,sload,aclr;
    input [7:0] data;
    output [7:0] q;
    reg [7:0] q;

    always @ (posedge clock or posedge aclr) begin
        if (aclr) 
            q<=0;
        else if (sload) 
            q<=data;
        else if (en) begin
            q<=q+1'b1; // count up
            if (q == 100) // check if count reaches 100
                q<=0; // reset count to zero
        end
    end
endmodule