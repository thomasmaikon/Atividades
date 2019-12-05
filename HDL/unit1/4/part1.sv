module part1(HEX0,HEX1,SW,KEY,LEDR);
	output logic [6:0]HEX0,HEX1;
	output logic [7:0]LEDR;
	input  logic [1:0] SW;
	input  logic [1:0]KEY;
	logic [8:0] soma;
	
	
	logic saida1,saida2,saida3,saida4,saida5,saida6,saida7,result1,result2,result3,result4,result5,result6;
	
	FFT ff1(
		.T(~KEY[1]),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida1),
	);
	
	assign result1 =  ~KEY[1] & saida1;
	
	FFT ff2(
		.T(result1),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida2)
	);
	
	assign result2 =  result1 & saida2;

	
	FFT ff3(
		.T(result2),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida3)
	);
	
	assign result3 =  result2 & saida3;

	
	FFT ff4(
		.T(result3),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida4)
	);
	
	assign result4 =  result3 & saida4;

	FFT ff5(
		.T(result4),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida5)
	);
	
	assign result5 =  result4 & saida5;
	
	FFT ff6(
		.T(result5),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida6)
	);
		
		assign result6 =  result5 & saida6;
	
		
	FFT ff7(
		.T(result6),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida7)
		
	);
		
		assign result7 =  result6 & saida7;
		
	FFT ff8(
		.T(result7),
		.Clk(SW[1]),
		.reset(KEY[0]),
		.Q(saida8)
	);
	
	assign result8 =  result7 & saida8;
	assign LEDR = {saida8,saida7,saida6,saida5,saida4,saida3,saida2,saida1};
	
	exibir(
		.SW({saida8,saida7,saida6,saida5,saida4,saida3,saida2,saida1}),
		.HEX0(HEX0),
		.HEX1(HEX1)
	);
	
endmodule
