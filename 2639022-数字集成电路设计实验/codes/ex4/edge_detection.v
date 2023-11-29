module edge_detection(
    input clk,
    input rst,
    input data,
    output pos_edge,
    output neg_edge,
    output data_edge
);

reg[1:0] data_n;
always @(posedge clk or negedge rst)
begin
    if(rst==1'b1)
        begin
        data_n<=2'b00;
        end
    else
    begin
        data_n<={data_n[0],data};
    end
end
assign pos_edge=(~data_n[1]) && data_n[0];
assign neg_edge=data_n[1] && (~data_n[0]);
assign data_edge=pos_edge | neg_edge;
endmodule