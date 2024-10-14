/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Ultra(TM) in wire load mode
// Version   : S-2021.06-SP3
// Date      : Sun Oct 13 19:12:53 2024
/////////////////////////////////////////////////////////////


module frequency_counter_control ( Clk, Clear, Cntover, Cntlow, reset, 
        std_f_sel, range );
  output [1:0] std_f_sel;
  output [2:0] range;
  input Clk, Clear, Cntover, Cntlow;
  output reset;
  wire   \*Logic0* , \range[2] , n8, n9, n10, n11, n12, n14, n15, n16, n17,
         n18, n19, n20;
  wire   [2:0] state;
  assign range[0] = \*Logic0* ;
  assign range[2] = \range[2] ;
  assign std_f_sel[1] = \range[2] ;
  assign range[1] = state[1];

  OAI21HDVL U17 ( .A1(n9), .A2(n8), .B(state[0]), .ZN(reset) );
  DRQHDV0 \state_reg[0]  ( .D(n12), .CK(Clk), .RD(Clear), .Q(state[0]) );
  DRQHDV0 \state_reg[2]  ( .D(n11), .CK(Clk), .RD(Clear), .Q(state[2]) );
  INHDVL U19 ( .I(state[2]), .ZN(n9) );
  OA1B2HDVL U20 ( .A1(std_f_sel[0]), .A2(n20), .B(n19), .Z(n10) );
  INHDVL U21 ( .I(n20), .ZN(n15) );
  NAND3BHDVL U22 ( .A1(Cntover), .B1(state[0]), .B2(Cntlow), .ZN(n20) );
  INHDVL U23 ( .I(state[1]), .ZN(n8) );
  PULLHD0 U25 ( .Z(\*Logic0* ) );
  NOR2HDVL U26 ( .A1(state[1]), .A2(n9), .ZN(\range[2] ) );
  CLKNAND2HDVL U27 ( .A1(state[0]), .A2(Cntlow), .ZN(n14) );
  CLKNAND2HDVL U28 ( .A1(state[0]), .A2(Cntover), .ZN(n18) );
  NAND4HDVL U29 ( .A1(state[1]), .A2(n14), .A3(n9), .A4(n18), .ZN(n17) );
  OAI211HDVL U31 ( .A1(n15), .A2(std_f_sel[0]), .B(n17), .C(n16), .ZN(n12) );
  OAI31HDVL U32 ( .A1(state[2]), .A2(n8), .A3(n20), .B(n16), .ZN(n11) );
  AOAI211HDVL U33 ( .A1(n8), .A2(n18), .B(n9), .C(n17), .ZN(n19) );
  DRQNHDV0 \state_reg[1]  ( .D(n10), .CK(Clk), .RD(Clear), .QN(state[1]) );
  NAND2HDVL U24 ( .A1(\range[2] ), .A2(n18), .ZN(n16) );
  NAND2HDVL U30 ( .A1(n8), .A2(n9), .ZN(std_f_sel[0]) );
endmodule
