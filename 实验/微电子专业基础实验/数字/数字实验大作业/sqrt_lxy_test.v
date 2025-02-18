`timescale 10ns/1ns

module sqrt_lxy_test ();
	parameter N = 16;
	reg clk,rst_n,start;
	reg [N+N-1:0] a=32'b11111111111111111111111111111111;
	wire complete;
	wire [N-1:0] root;
	wire [N:0] reminder;
	initial begin #0 start=0;clk=0;rst_n=0; #100 rst_n=1; #100 start=1; #20 start=0; end 
	always begin clk=1'b0; #5 clk=1'b1; #5; end
	always begin #400 a=a+2'b10; end
	always @(posedge complete) begin
		#20 rst_n=0;
		#20 rst_n=1;
		#20 start=1;
		#20 start=0;
	end

	
	sqrt_lxy #(N) U1 (clk,rst_n,start,a,complete,root,reminder);
endmodule 