module part5(SW, HEX0,HEX1,HEX4,HEX5);
	
 input logic [8:0] SW;
 output logic [6:0] HEX0,HEX1,HEX4,HEX5;
 
 logic [4:0] A, B, Cin, Cout, Excesso, S0, S1, Soma;
 
 assign A = SW[3:0];
 assign B = SW[7:4];
 assign Cin = SW[8:8];
 
 assign Soma = (A + B) + Cin;
 assign S0 = Soma - Excesso;
 assign S1 = Cout;
	
 always @(*) begin
	if (Soma > 9) begin
		Excesso = 10;
		Cout = 1;
	end else begin
		Excesso = 0;
		Cout = 0;
	end
 end 
	
	char7seg n1(
		.entrada(S0),
		.saida(HEX0)
	);
	
	char7seg n2(
		.entrada(S1),
		.saida(HEX1)
	);
	
	
	char7seg n3(
		.entrada(A),
		.saida(HEX4)
	);
	
	char7seg n4(
		.entrada(B),
		.saida(HEX5)
	);
 
endmodule 