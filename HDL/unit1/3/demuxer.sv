module demuxer(entrada, entradaposicao, saidax,saiday);
			input logic [7:0] entrada;
			input logic entradaposicao;
         output logic [7:0] saidax, saiday;
				
	always @(*) begin
		if(entradaposicao)begin
			saidax = entrada;
		end else begin
			saiday = entrada;
		end
	end
	
endmodule
