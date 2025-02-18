`timescale 10ns/1ns
module exp05_lxy_tb();
	reg CLK,RST;
	wire [7:0] Q;
	
	initial CLK=0;
	always #1 CLK=~CLK;
	
	initial begin
		#0 RST=0;
	end
	
	exp05_lxy U1(CLK,RST,Q);
	
endmodule