module part4(SW,HEX0,HEX1,HEX4,HEX5,LEDR);
	
	input logic[8:0] SW;
	output logic [6:0] HEX0,HEX1,HEX4,HEX5;
	output logic[4:0] LEDR;
	
	logic [4:0] value;
	
	part3 p3(
		.LEDR(value),
		.SW(SW)
	);
	
	part2 p2(
		.SW(value),
		.HEX0(HEX0),
		.HEX1(HEX1)
	);
	
	numero n0(
		.entrada(SW[3:0]),
		.saida(HEX4)
	);
	
	numero n1(
		.entrada(SW[7:4]),
		.saida(HEX5)
	);
	
	assign LEDR = value;

	
	
endmodule
