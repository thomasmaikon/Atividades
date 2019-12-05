module counter(clk,enable,set,saida);
	input clk;
	input logic set;
	input logic enable;
	logic [7:0] Q;
	output logic [7:0] saida;

	assign  saida = Q;
	always_ff @(posedge clk)begin
		if(set)begin 
			Q = 0;
		end else if(enable)begin 
					Q = Q + 1;
		end
	end
	
	
	
endmodule
