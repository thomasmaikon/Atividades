module parte3(CLOCK_27,HEX0,HEX1);
	output [6:0] HEX0,HEX1;
	logic[25:0] Q;
	logic [7:0]saida;

	
	input CLOCK_27;

	clock clk1(
				.clk(CLOCK_27),
				.en(1),
				.s(Q)
	);
	clock clk2 (
			.clk(CLOCK_27),
				.en(&Q),
				.s(saida)
	);

	exibir ex(
		.SW(saida),
		.HEX0(HEX0),
		.HEX1(HEX1)
	);
	
endmodule

