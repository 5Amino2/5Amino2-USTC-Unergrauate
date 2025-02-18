`timescale 10us/1us

module exp04_lxy_tb();
reg clk;
wire [3:0] scan_code;
reg [3:0] read_code;
wire [7:0] led;
reg on;
wire [2:0] st;
wire [3:0] data_out;
state state_1(clk,st);
scan scan_1(st,scan_code);
read read_1(st,read_code,data_out);
decoder4_7 decoder4_7_1(data_out,led);
initial on<=1;

/*产生时钟信号*/
initial clk=0;
always #1 clk=~clk;

/*逐行测试*/
initial begin
#0 	  read_code=4'b1110;
#100 read_code=4'b1101;
#200 read_code=4'b1011;
#300 read_code=4'b0111;
end
endmodule