module FFD(D,Clk,Qa,Qb);
	input logic  D, Clk;
	output logic  Qa, Qb;
	
	logic S, R, s1, r1;
	
	assign S = D & Clk;
	assign R = ~D & Clk;
	
	assign s1 = ~S & Qb;
	assign r1 = ~R & Qa;
	
	assign Qb = ~r1;
	assign Qa = ~s1;
	
endmodule 