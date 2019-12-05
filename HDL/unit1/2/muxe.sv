module muxe(entradax,entraday, entradaposicao, saida);
			 input logic [3:0] entradax, entraday;
			 input logic entradaposicao;
          output logic [3:0] saida;
   assign saida = entradaposicao ? entraday : entradax;
	
endmodule
