`timescale 1ns / 1ps

module washing_machine_tb;

reg clk;
reg start;
reg pause;
reg reset;
reg [1:0] mode;
reg cover_closed;
reg water_connected;
wire [1:0] state;
wire warning;

washing_machine uut (
    .clk(clk),
    .start(start),
    .pause(pause),
    .reset(reset),
    .mode(mode),
    .cover_closed(cover_closed),
    .water_connected(water_connected),
    .state(state),
    .warning(warning)
);

initial begin
    clk = 0;
    start = 0;
    pause = 0;
    reset = 0;
    mode = 0;
    cover_closed = 1;
    water_connected = 1;

    #10 reset = 1; // reset the machine
    #10 reset = 0; // release reset
    #10 start = 1; // start the machine
    #1000 start = 0; // stop the machine
    #10 mode = 1; // change mode to wool wash
    #10 start = 1; // start the machine again
    #1000 start = 0; // stop the machine again
end

always #5 clk = ~clk;

endmodule