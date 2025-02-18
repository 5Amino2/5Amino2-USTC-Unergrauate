module exp05_lxy(CLK,RST,Q);
	input CLK,RST;
	output [7:0] Q;
	reg [9:0] count=10'b0000000000;
	always @(posedge CLK) count=(RST==1 | count==10'b11111111111)?10'b0000000000:count+10'b0000000001;
	mystorage U1(count,CLK,Q);
endmodule