module part2(HEX0, HEX1,KEY);
	logic [8:0] Q;
	input logic [1:0] KEY;
	output [6:0]HEX0,HEX1;
	
	always_ff @(posedge KEY[1], negedge KEY[0])begin
		
		 if(~KEY[0])begin
			Q <= 1'b0;
		end else begin
				Q <= Q + 1;
		end
	end

exibir ex1(
		.SW(Q),
		.HEX0(HEX0),
		.HEX1(HEX1)
);

endmodule
