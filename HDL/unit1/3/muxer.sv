module muxer(entradax,entraday, entradaposicao, saida);
			input logic [7:0] entradax, entraday;
			input logic entradaposicao;
         output logic [7:0] saida;
   assign saida = entradaposicao ? entraday : entradax;
	
endmodule
