module NegFF(D, Clk, Q);
	input D, Clk;
	output reg Q;
	
	always_ff @(negedge Clk)
			Q = D;
			
endmodule
