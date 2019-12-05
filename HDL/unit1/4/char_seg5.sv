module char_7seg(c,s);
	input [1:0] c;
	output [6:0] s;
	
	always @(*)
	begin
	 case(c)
		2'b00: begin
			 s = 7'b0100001;
		end
		
		2'b01: begin
			 s = 7'b0000110;
		end
		
		2'b10: begin
			 s = 7'b1000000;
		end
		
		2'b11: begin
			 s = 7'b1111111;
		end
		
		default: begin
			s =  7'b0111111;
		end
	 endcase
	end
	
endmodule