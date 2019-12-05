module part4(SW,LEDR);

	output logic [2:0] LEDR;
	input logic[1:0] SW;
	
	
	FFD ff0(
		.D(SW[0]),
		.Clk(SW[1]),
		.Qa(LEDR[0]),
		.Qb()
	);
	
	PosFF ff1(
		.D(SW[0]),
		.Clc(SW[1]),
		.Q(LEDR[1])
	);
	
	NegFF ff2(
		.D(SW[0]),
		.Clc(SW[1]),
		.Q(LEDR[2])
	);

endmodule 