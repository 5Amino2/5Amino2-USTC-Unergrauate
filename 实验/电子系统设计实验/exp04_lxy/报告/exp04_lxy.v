/*主模块*/
module exp04_lxy(sys_clk,scan_code,read_code,led,on);
input sys_clk;
output [3:0] scan_code;
input [3:0] read_code;
output [7:0] led;
output reg on;
wire clk;
wire [2:0] st;
wire [3:0] data_out;
devender devender_1(sys_clk,clk);
state state_1(clk,st);
scan scan_1(st,scan_code);
read read_1(st,read_code,data_out);
decoder4_7 decoder4_7_1(data_out,led);
initial on<=1;
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

/*状态转换时钟*/
module state(clk,st);
input clk;
output reg [2:0] st;
initial st<=0;
always @(posedge clk) st<=st+1;
endmodule

/*输出扫描电平模块*/
module scan(st,scan_code);
input [2:0] st;
output reg [3:0] scan_code;
always @(st) begin
	case(st)
		0:scan_code<=4'b1110;
		2:scan_code<=4'b1101;
		4:scan_code<=4'b1011;
		6:scan_code<=4'b0111;
		//default:scan_code<=4'b1111;
	endcase
end
endmodule

/*读取模块*/
module read(st,read_code,data_out);
input [2:0] st;
input [3:0] read_code;
output reg [3:0] data_out;
always @(st) begin
	case({st,read_code})
	7'b0011110:data_out<=4'h1;
	7'b0011101:data_out<=4'h4;
	7'b0011011:data_out<=4'h7;
	7'b0010111:data_out<=4'hE;
	7'b0111110:data_out<=4'h2;
	7'b0111101:data_out<=4'h5;
	7'b0111011:data_out<=4'h8;
	7'b0110111:data_out<=4'h0;
	7'b1011110:data_out<=4'h3;
	7'b1011101:data_out<=4'h6;
	7'b1011011:data_out<=4'h9;
	7'b1010111:data_out<=4'hF;
	7'b1111110:data_out<=4'hA;
	7'b1111101:data_out<=4'hB;
	7'b1111011:data_out<=4'hC;
	7'b1110111:data_out<=4'hD;
	//default:data_out<=data_out;
	endcase
end
endmodule

/*数码管译码器模块*/
module decoder4_7 (
    input   wire    [3:0]   data_in,

    output  reg     [7:0]   data_out//[7:0]:a,b,c,d,e,f,g,dp
);

always @(*) begin
    case (data_in)
        4'd0: data_out <= 8'b0000_0011;//a,b,c,d,e,f
        4'd1: data_out <= 8'b1001_1111;//b,c
        4'd2: data_out <= 8'b0010_0101;//a,b,d,e,g
        4'd3: data_out <= 8'b0000_1101;//a,b,c,d,g
        4'd4: data_out <= 8'b1001_1001;//b,c,f,g
        4'd5: data_out <= 8'b0100_1001;//a,c,d,f,g
        4'd6: data_out <= 8'b0100_0001;//a,c,d,e,f,g
        4'd7: data_out <= 8'b0001_1111;//a,b,c
        4'd8: data_out <= 8'b0000_0001;//a,b,c,d,e,f,g
        4'd9: data_out <= 8'b0000_1001;//a,b,c,d,f,g
        4'd10:data_out <= 8'b0001_0001; //c,d,e,g,dp
        4'd11:data_out <= 8'b1100_0001;//c,d,e,f,g
        4'd12:data_out <= 8'b1110_0101;//d,e,g
        4'd13:data_out <= 8'b1000_0101;//b,c,d,e,g
        4'd14:data_out <= 8'b0110_0001;//a,d,e,f,g
        4'd15:data_out <= 8'b0111_0001;//a,e,f,g
    endcase
end
    
endmodule



