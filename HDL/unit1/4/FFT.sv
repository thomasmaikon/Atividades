module FFT(T,Clk,reset,Q);
	input  T,Clk,reset;
	output Q;

	always_ff @( posedge Clk ) begin
		if(~reset) begin
			Q <= 1'b0;
		end else if(T) begin
			Q <= !Q;
		end
	end

endmodule
