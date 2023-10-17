//: version "2.1"
//: property encoding = "utf-8"
//: property locale = "en"
//: property prefix = "_GG"
//: property timingViolationMode = 2
//: property initTime = "0 ns"

`timescale 1ns/1ns

//: /netlistBegin main
module main;    //: root_module
reg w0;    //: /sn:0 {0}(211,94)(262,94)(262,115)(277,115){1}
reg w1;    //: /sn:0 {0}(211,144)(262,144)(262,120)(277,120){1}
wire w4;    //: /sn:0 {0}(298,118)(331,118)(331,94){1}
//: enddecls

  //: LED g3 (w4) @(331,87) /sn:0 /w:[ 1 ] /type:0
  _GGAND2 #(6) g2 (.I0(w0), .I1(w1), .Z(w4));   //: @(288,118) /sn:0 /w:[ 1 1 0 ]
  //: SWITCH g1 (w1) @(194,144) /sn:0 /w:[ 0 ] /st:0 /dn:1
  //: SWITCH g0 (w0) @(194,94) /sn:0 /w:[ 0 ] /st:0 /dn:1

endmodule
//: /netlistEnd

