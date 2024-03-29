module part2(SW, LEDR);
		output logic [1:0] LEDR;
		input logic[1:0] SW;
		
		FFD ffd(
			.D(SW[0]),
			.Clk(SW[1]),
			.Qa(LEDR[0]),
			.Qb(LEDR[1]),
		);
		
endmodule 