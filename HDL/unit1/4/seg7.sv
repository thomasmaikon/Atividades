module seg7(entrada,saida);

	input logic[4:0] entrada;
	output logic[6:0] saida;

	logic [4:0] c;
	
	assign c = entrada;
	
	always @(*) begin 
		
		case (c)
			0: begin 
				saida = 7'b1000000;
			end
			1: begin 
				saida = 7'b1111001;
			end
			2: begin 
				saida = 7'b0100100;
			end
			3: begin 
				saida = 7'b0110000;
			end
			4: begin 
				saida = 7'b0011001;
			end
			5: begin 
				saida = 7'b0010010;
			end
			6: begin 
				saida = 7'b0000010;
			end
			7: begin 
				saida = 7'b1111000;
			end
			8: begin 
				saida = 7'b0000000;
			end
			9: begin 
				saida = 7'b0011000;
			end
		
			default: begin
				saida = 7'b0111111;
			end
		endcase
	end
	
endmodule
