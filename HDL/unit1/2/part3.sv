module part3(LEDR,SW);

	input logic[8:0] SW;
	output logic[4:0] LEDR;
	
	logic out1,out2,out3,out4;
	logic [3:0] a,b;
	
	assign a = SW[3:0];
	assign b = SW[7:4];
	
	somador s1(
			.A(a[0]),
			.B(b[0]),
			.Cin(SW[8]),
			.Saida(LEDR[0]),
			.Cout(out1)
	);
	somador s2(
			.A(a[1]),
			.B(b[1]),
			.Cin(out1),
			.Saida(LEDR[1]),
			.Cout(out2)
	);
	somador s3(
			.A(a[2]),
			.B(b[2]),
			.Cin(out2),
			.Saida(LEDR[2]),
			.Cout(out3)
	);
	somador s4(
			.A(a[3]),
			.B(b[3]),
			.Cin(out3),
			.Saida(LEDR[3]),
			.Cout(LEDR[4])
	);
	
	
endmodule
