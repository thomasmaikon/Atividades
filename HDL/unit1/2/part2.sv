module part2(SW,HEX0,HEX1);
	
	input logic [4:0] SW;
	output logic[6:0] HEX0,HEX1;
	
	logic [4:0] entrada1,entrada2;
	logic [4:0] fio1,fio2;
	
	assign entrada1 = SW;
	assign entrada2 = entrada1 - 5'b01010;
	
	always@(*)begin
	
		if(entrada1 > 9)begin
			fio2 = 5'b00001;
		end else begin
			fio2 = 5'b00000;
		end
		
	end
	
	 muxer m1(
		.entradax(entrada1),
		.entraday(entrada2),
		.entradaposicao(fio2),
		.saida(fio1)
	 );
	
	numero v0(
		.entrada(fio1),
		.saida(HEX0)
	);
	
	numero v1(
		.entrada(fio2),
		.saida(HEX1)
	);
endmodule
