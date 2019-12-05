module clock(clk, en , s );
	input logic  clk ;
	input logic  en ;
	logic [25:0] q;
	output logic [25:0] s ;	
	
	always_ff @ ( posedge clk)
			if(en)
				begin
					q <= q+1;
				end
			
	assign s = q;		

endmodule