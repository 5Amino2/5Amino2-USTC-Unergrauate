/*主模块*/
module exp03_lxy(sys_clk,reset,sel,detector_out);
input sys_clk;
input reset;
input sel;
output detector_out;
wire clk,seq1,seq2,seq_selected;

devender devender_1(sys_clk,clk);
seq_gen1 seq_gen1_1(clk,reset,seq1);
seq_gen2 seq_gen2_1(clk,reset,seq2);
seq_sel seq_sel_1(clk,sel,seq1,seq2,seq_selected);
seq_detector seq_detector_1(clk,reset,seq_selected,detector_out);
endmodule

/*分频器*/
module devender(sys_clk,clk);
parameter DIV_MAX=13'd99999;
input sys_clk;
output reg clk;
reg [12:0] div;
always @(posedge sys_clk) begin
div<=(div==DIV_MAX)?0:(div+1);
end
always @(posedge sys_clk) begin
clk<=(div==DIV_MAX)?(~clk):clk;
end
endmodule

/*产生序列1*/
module seq_gen1(clk,reset,seq);
input clk,reset;
output reg seq;
parameter S0=0,S1=1,S2=2,S3=3,S4=4,S5=5,S6=6,S7=7,S8=8,S9=9;
reg [3:0] st;

always @(posedge clk,posedge reset) begin
	if(reset) st<=S0;
	else begin
	case(st)
		S0:st<=S1;
		S1:st<=S2;
		S2:st<=S3;
		S3:st<=S4;
		S4:st<=S5;
		S5:st<=S6;
		S6:st<=S7;
		S7:st<=S8;
		S8:st<=S9;
		S9:st<=S0;
		default:st<=S0;
		endcase
	end
	
	case(st)
		S0:seq<=1;
		S1:seq<=1;
		S2:seq<=1;
		S3:seq<=0;
		S4:seq<=1;
		S5:seq<=0;
		S6:seq<=0;
		S7:seq<=1;
		S8:seq<=1;
		S9:seq<=0;
		endcase
end
endmodule

/*产生序列2*/
module seq_gen2(clk,reset,seq);
input clk,reset;
output reg seq;
parameter S0=0,S1=1,S2=2,S3=3,S4=4,S5=5,S6=6,S7=7,S8=8,S9=9;
reg [3:0] st;

always @(posedge clk,posedge reset) begin
	if(reset) st<=S0;
	else begin
	case(st)
		S0:st<=S1;
		S1:st<=S2;
		S2:st<=S3;
		S3:st<=S4;
		S4:st<=S5;
		S5:st<=S6;
		S6:st<=S7;
		S7:st<=S8;
		S8:st<=S9;
		S9:st<=S0;
		default:st<=S0;
		endcase
	end
	
	case(st)
		S0:seq<=1;
		S1:seq<=0;
		S2:seq<=1;
		S3:seq<=0;
		S4:seq<=1;
		S5:seq<=0;
		S6:seq<=1;
		S7:seq<=0;
		S8:seq<=1;
		S9:seq<=0;
		default:seq<=0;
		endcase
end
endmodule

/*选择序列输出*/
module seq_sel(clk,sel,seq0,seq1,seq_out);
input clk;
input sel;
input seq0;
input seq1;
output reg seq_out;

always @(posedge clk) begin
seq_out<=sel?seq1:seq0;
end
endmodule

/*检测序列*/
module seq_detector(clk,reset,seq_in,detector_out);
input clk;
input reset;
input seq_in;
output reg detector_out;
reg [3:0] st;
parameter S0=0,S1=1,S2=2,S3=3,S4=4,S5=5,S6=6,S7=7,S8=8,S9=9;

always @(posedge clk,posedge reset) begin
if(reset) st<=S0;
else begin
	case(st)
	S0:st<=(seq_in?S1:S0);
	S1:st<=(seq_in?S2:S0);
	S2:st<=(seq_in?S3:S0);
	S3:st<=(seq_in?S3:S4);
	S4:st<=(seq_in?S5:S0);
	S5:st<=(seq_in?S2:S6);
	S6:st<=(seq_in?S1:S7);
	S7:st<=(seq_in?S8:S0);
	S8:st<=(seq_in?S9:S0);
	S9:st<=(seq_in?S1:S0);
	default:st<=S0;
	endcase
end

	case(st)
	S9:detector_out<=1;
	default:detector_out<=0;
	endcase
end
endmodule

