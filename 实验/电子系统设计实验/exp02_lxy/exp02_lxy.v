module exp02_lxy(sys_clk,en,data_in,sel,data_out,cs_led);
input sys_clk;
input en;
input [3:0] data_in;
input [2:0] sel;
output [7:0] data_out;
output reg [7:0] cs_led;
wire [2:0] st;
wire [3:0] data_out_0;
wire [3:0] data_out_1;
wire [3:0] data_out_2;
wire [3:0] data_out_3;
wire [3:0] data_out_4;
wire [3:0] data_out_5;
wire [3:0] data_out_6;
wire [3:0] data_out_7;
reg [3:0] data_out_seled;
wire [7:0] data_out_temp;

always @(*) begin
    if (!en) begin
        cs_led <= 8'b0000_0000;
    end
    else case (st)
        3'd0:cs_led <= 8'b0000_0001;
        3'd1:cs_led <= 8'b0000_0010;
        3'd2:cs_led <= 8'b0000_0100;
        3'd3:cs_led <= 8'b0000_1000;
        3'd4:cs_led <= 8'b0001_0000;
        3'd5:cs_led <= 8'b0010_0000;
        3'd6:cs_led <= 8'b0100_0000;
        3'd7:cs_led <= 8'b1000_0000;
    endcase
end

always @(*) begin
    if (!en) begin
        data_out_seled <= 0;
    end
    else case (st)
        3'd0:data_out_seled <= data_out_0;
        3'd1:data_out_seled <= data_out_1;
        3'd2:data_out_seled <= data_out_2;
        3'd3:data_out_seled <= data_out_3;
        3'd4:data_out_seled <= data_out_4;
        3'd5:data_out_seled <= data_out_5;
        3'd6:data_out_seled <= data_out_6;
        3'd7:data_out_seled <= data_out_7; 
    endcase
end

decoder_47_lxy decoder_47_inst(data_out_seled,data_out);
decoder_38_lxy decoder_38_lxy_inst(sel,data_in,en,data_out_0,data_out_1,data_out_2,data_out_3,data_out_4,data_out_5,data_out_6,data_out_7);
state_lxy state_inst(sys_clk,en,st);
endmodule