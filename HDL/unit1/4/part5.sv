module part5(HEX0,HEX1,HEX2,HEX3,HEX4,HEX5,HEX6,HEX7,CLOCK_27);
	output logic[6:0] HEX0,HEX1,HEX2,HEX3,HEX4,HEX5,HEX6,HEX7;
	logic [22:0] Q;
	logic [2:0] c, ent0,ent1,ent2,ent3,ent4,ent5,ent6,ent7;
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
	
	
	assign ent0 =  c+ 0;
	assign ent1 =  c+ 1;
	assign ent2 =  c+ 2;
	assign ent3 =  c+ 3;
	assign ent4 =  c+ 4+2;
	assign ent5 =  c+ 5+3;
	assign ent6 =  15;
	assign ent7 =  15;
	
		char_7seg2 ponto0(
				.c(ent0),
				.s(HEX0)		);

		char_7seg2 ponto1(
				.c(ent1),
				.s(HEX1)
		);
		char_7seg2 ponto2(
				.c(ent2),
				.s(HEX2)
		);
		char_7seg2 ponto3(
				.c(ent3),
				.s(HEX3)
		);
		char_7seg2 ponto4(
				.c(ent4),
				.s(HEX4)
		);
		char_7seg2 ponto5(
				.c(ent5),
				.s(HEX5)
		);
		char_7seg2 ponto6(
				.c(ent6),
				.s(HEX6)
		);
		char_7seg2 ponto7(
				.c(ent7),
				.s(HEX7)
		);
		
endmodule
