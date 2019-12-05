module part1(SW,HEX0,HEX1);
		input logic [7:0] SW;
		output logic[6:0]HEX0,HEX1;
	
	valores v1(
			.entrada(SW[3:0]),
			.saida(HEX0)
	);
	
	valores v2(
			.entrada(SW[7:4]),
			.saida(HEX1)
	);
endmodule
