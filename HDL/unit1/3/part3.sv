module part3(SW,LEDR);
	input logic [1:0] SW;
	output logic [1:0] LEDR;
	logic Q,NOTQ;

	FFD ff1(
		.D(SW[0]),
		.Clk(SW[1]),
		.Qa(Q),
		.Qb(NOTQ)
	);
	
	FFD ff2(
		.D(Q),
		.Clk(SW[1]),
		.Qa(LEDR[0]),
		.Qb(LEDR[1])
	);
	
endmodule
