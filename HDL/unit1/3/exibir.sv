module exibir(SW,HEX0,HEX1);
	
	input logic [7:0] SW;
	output logic[6:0] HEX0,HEX1;
	
	logic [7:0] entrada1;
	logic [7:0] fio1,fio2;
	
	assign entrada1 = SW;
	assign fio1 = entrada1 % 10; 
	
	assign fio2 = entrada1 /10;
	
	numero v0(
		.entrada(fio1),
		.saida(HEX0)
	);
	
	numero v1(
		.entrada(fio2),
		.saida(HEX1)
	);
endmodule
