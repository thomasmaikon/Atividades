module PosFF(D, Clk, Q);
	input D, Clk;
	output reg Q;
	
	always_ff @(posedge Clk)
    Q = D;
endmodule
