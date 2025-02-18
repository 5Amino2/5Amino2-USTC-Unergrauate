/*测试模块*/
`timescale 10ms/1ms
module exp03_lxy_tb();
reg clk;
reg reset;
reg sel;
wire detector_out;
wire seq1,seq2,seq_selected;
/*产生时钟信号*/
always @(*) begin
#1 clk<=~clk;
end
/*设定初始状态*/
initial begin
clk<=0;
reset<=0;
sel<=0;
end
/*选择信号开始测试*/
initial begin
#1 reset=1;
#9 reset=0;
#41 sel=1;
end

seq_gen1 seq_gen1_1(clk,reset,seq1);
seq_gen2 seq_gen2_1(clk,reset,seq2);
seq_sel seq_sel_1(clk,sel,seq1,seq2,seq_selected);
seq_detector seq_detector_1(clk,reset,seq_selected,detector_out);
endmodule
