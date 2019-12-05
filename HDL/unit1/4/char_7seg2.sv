module char_7seg2(c,s);
	input [2:0] c;
	output [6:0] s;
	
	always @(*)
	begin
		if(c < 4 )begin
			case(c)
			3'b000: begin
				s = 7'b0100001;
			end
		
			3'b001: begin
				s = 7'b0000110;
			end
		
			3'b010: begin
				s = 7'b1000000;
			end
		
			3'b011: begin
				s = 7'b0001110;
			end
			endcase
		end 
		else begin
			s =  7'b1111111;
		end
	end
	
endmodule