module somador(A,B,Cin,Saida,Cout);

	input A,B,Cin;
	output logic Saida, Cout;
	
	logic result1;
	
	xore Xor1(
		.x1(A),
		.x2(B),
		.saida(result1)
	);
	
	xore Xor2(
		.x1(Cin),
		.x2(result1),
		.saida(Saida)
	);
	
	muxe mx(
		.entradax(B),
		.entraday(Cin),
		.entradaposicao(result1),
		.saida(Cout)
	);

endmodule
