module edge_detection_tb();
reg clk, rst, data;
wire pos_edge , neg_edge , data_edge;

edge_detection uut(
    .clk(clk),
    .rst(rst),
    .data(data),
    .pos_edge(pos_edge),
    .neg_edge(neg_edge),
    .data_edge(data_edge));
    
always #2 clk = ~clk;

initial begin
    $monitor($stime,,"clk=%b rst=%b data=%b pos_edge=%b neg_edge=%b data_edge=%b" , clk, rst , data, pos_edge , neg_edge , data_edge);
    clk=0; rst=0; data=1;
    #10 data=0;
    #10 data=1;
    #10 data=0;
    #10 data=1;
    #10 rst=1;
    #40 $finish;
end

initial begin
    $vcdpluson; // vcdplus.vpd格式的波形文件
end
endmodule