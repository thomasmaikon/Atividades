module soma(clk,Q,saida);
	input clk;
	input logic [26:0] Q;
	output logic [26:0] saida;
	
	always_ff @(posedge clk)begin
			saida <=  Q + 1;
		
	end
	

	
endmodule
