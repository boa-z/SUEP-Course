module addertb.v;
    reg [7:0] a_test,b_test;
    wire [7:0] sum_test;
    reg cin_test;
    wire cout_test;
    reg [17:0] test;

add8 u1(a_test,b_test,cin_test,sum_test,cout_test);

initial
    if (!$test$plusargs("monitoroff"))
        $monitor ($time, " %h+%h=%h;cin=%h,cout=%h",
        a_test,b_test,sum_test,cin_test,cout_test);
initial
    begin
    for (test=0,test<=18'h1ffff; test=test+1) begin
            cin_test=test[16];
            a_test=test[15:8];
            b_test=test[7:0];
            #100;
            if ({cout_test,sum_test}!= =(a_test+b_test+cin_test)) begin
                $display("***ERROR at time = %0d ***",$time);
                $display("a=%h,b=%h,sum=%h,cin=%h,cout=%h",
                        a_test,b_test,sum_test,cin_test,cout_test);
                $display("\nIn add4(u1)");
                $display("a=%b,b=%b,sum=%b,cin=%b,c=%b,cout=%b",
                    u1.u1.a,u1.u1.b,u1.u1.sum,u1.u1.cin,u1.u1.c,u1.u1.cout);
                $display("\nIn add8(u1)");
                $display("a=%b,b=%b,sum=%b,cin=%b,cout=%b",
                    u1.a,u1.b,u1.sum,u1.cin,u1.cout);
              $finish;
            end
    end
    $display("***Testbench Successfully completed!***");
    $finish;
end
endmodule