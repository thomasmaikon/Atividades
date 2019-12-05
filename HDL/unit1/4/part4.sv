module part4(HEX0,HEX1,HEX2,HEX3,KEY,CLOCK_27);
	input logic [0:0]KEY;
	output logic[6:0] HEX0,HEX1,HEX2,HEX3;
	logic [25:0] Q;
	logic [1:0] c, ent0,ent1,ent2,ent3;
	input CLOCK_27;
	
	
	clock clk1(
				.clk(CLOCK_27),
				.en(1),
				.s(Q)
	);
	clock clk2 (
			.clk(CLOCK_27),
				.en(&Q),
				.s(c)
	);
	
	
	assign ent0 =  c + 0;
	assign ent1 =  c + 1;
	assign ent2 =  c + 2;
	assign ent3 =  c + 3;
	
		char_7seg ponto0(
				.c(ent0),
				.s(HEX0)		);

		char_7seg ponto1(
				.c(ent1),
				.s(HEX1)
		);
		char_7seg ponto2(
				.c(ent2),
				.s(HEX2)
		);
		char_7seg ponto3(
				.c(ent3),
				.s(HEX3)
		);
		
endmodule
