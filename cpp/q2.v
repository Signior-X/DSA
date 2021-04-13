module m81(input D0, D1, D2, D3, D4, D5, D6, D7, S0, S1, S2, output out);
	wire T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
	not n1(T1, S0);
	not n2(T2, S1);
	not n3(T3, S2);
	and a1(T4, D0, T1, T2, T3);
	and a2(T5, D1, S0, T2, T3);
	and a3(T6, D2, T1, S1, T3);
	and a4(T7, D3, S0, S1, T3);
	and a5(T8, D4, T1, T2, S2);
	and a6(T9, D5, S0, T2, S2);
	and a7(T10, D6, T1, S1, S2);
	and a8(T11, D7, S0, S1, S2);
	or a9(out, T4, T5, T6, T7, T8, T9, T10, T11);
endmodule


module Logical_right_shift_8bit(
    input [2:0] S,
    input [7:0] inp,
    output [7:0] out
);

    m81 mxl1(inp[0], inp[1], inp[2], inp[3], inp[4], inp[5], inp[6], inp[7], S[0], S[1], S[2], out[0]);
    m81 mxl2(inp[1], inp[2], inp[3], inp[4], inp[5], inp[6], inp[7], 1'b0, S[0], S[1], S[2], out[1]);
    m81 mxl3(inp[2], inp[3], inp[4], inp[5], inp[6], inp[7], 1'b0, 1'b0, S[0], S[1], S[2], out[2]);
    m81 mxl4(inp[3], inp[4], inp[5], inp[6], inp[7], 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[3]);
    m81 mxl5(inp[4], inp[5], inp[6], inp[7], 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[4]);
    m81 mxl6(inp[5], inp[6], inp[7], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[5]);
    m81 mxl7(inp[6], inp[7], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[6]);
    m81 mxl8(inp[7], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[7]);

endmodule



module Logical_left_shift_8bit(
    input [2:0] S,
    input [7:0] inp,
    output [7:0] out
);

    m81 mxl1(inp[0], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[0]);
    m81 mxl2(inp[1], inp[0], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[1]);
    m81 mxl3(inp[2], inp[1], inp[0], 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[2]);
    m81 mxl4(inp[3], inp[2], inp[1], inp[0], 1'b0, 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[3]);
    m81 mxl5(inp[4], inp[3], inp[2], inp[1], inp[0], 1'b0, 1'b0, 1'b0, S[0], S[1], S[2], out[4]);
    m81 mxl6(inp[5], inp[4], inp[3], inp[2], inp[1], inp[0], 1'b0, 1'b0, S[0], S[1], S[2], out[5]);
    m81 mxl7(inp[6], inp[5], inp[4], inp[3], inp[2], inp[1], inp[0], 1'b0, S[0], S[1], S[2], out[6]);
    m81 mxl8(inp[7], inp[6], inp[5], inp[4], inp[3], inp[2], inp[1], inp[0], S[0], S[1], S[2], out[7]);

endmodule




module Barrel_Shifter(
    input [2:0] S,
    input [7:0] A,
    output reg [7:0] Y
);

wire [7:0] y0, y1, y2, y3, y4, y5, y6, y7;

Logical_left_shift_8bit c1(3'b101, A, y0);
Logical_left_shift_8bit c2(3'b010, A, y1);
Logical_right_shift_8bit c3(3'b011, A, y2);
Logical_right_shift_8bit c4(3'b100, A, y3);
Logical_left_rotate_8bit c5(3'b001, A, y4);
Logical_right_rotate_8bit c6(3'b100, A, y5);
Arithematic_left_shift_8bit c7(3'b011, A, y6);
Arithematic_right_shift_8bit c8(3'b110, A, y7);

always @(*) begin
    case (S)
        3'b000 : Y = y0;
        3'b001 : Y = y1;
        3'b010 : Y = y2;
        3'b011 : Y = y3;
        3'b100 : Y = y4;
        3'b101 : Y = y5;
        3'b110 : Y = y6;
        3'b111 : Y = y7;
        default: Y = A;
    endcase
end

// Test Bench for Barrel Shifter
module test_Barrel_Shifter;

// Defining test variables
reg [2:0] S;
reg [7:0] A;
wire [7:0] Y;

Barrel_Shifter bs(S, A, Y); // Instantiate Barrel Shifter

initial begin
    $monitor("Values of S=%b, A=%b, Y=%b", S, A, Y);

    // Testing Left shift case 1 and 2
    S = 3'b000;
    A = 8'b11001100;
    #100;

    A = 8'b00001100;
    #100;

    A = 8'b11101101;
    #100;

    S = 3'b001;
    A = 8'b11001100;
    #100;
end

endmodule