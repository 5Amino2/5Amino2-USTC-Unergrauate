`timescale 10ms/1ms
module decoder_38_tb_lxy();
reg [2:0] sel;
reg [3:0]   data_in;
reg en;
wire    [3:0]   data_out_0;
wire    [3:0]   data_out_1;
wire    [3:0]   data_out_2;
wire    [3:0]   data_out_3;
wire    [3:0]   data_out_4;
wire    [3:0]   data_out_5;
wire    [3:0]   data_out_6;
wire    [3:0]   data_out_7;

decoder_38_lxy U1(
sel,
data_in,
en,
    
data_out_0,
data_out_1,
data_out_2,
data_out_3,
data_out_4,
data_out_5,
data_out_6,
data_out_7
);

initial begin
/*设置初始状态*/
#0 en=1; #0 data_in=0; #0 sel=0;
/*验证en对data_in的控制作用*/
#1 en=0;
#2 data_in=1;
#3 en=1;
/*验证en对sel的控制作用*/
#4 en=0;
#5 sel=1;
#6 en=1;
/*验证data_in的传输作用*/
#7 data_in=2;
#8 data_in=3;
/*验证sel的片选作用*/
#9 sel=2;
#10 sel=3;
end
endmodule
