module decoder_38_lxy (
    input   wire    [2:0]   sel,
    input   wire    [3:0]   data_in,
    input   wire            en,
    
    output  wire    [3:0]   data_out_0,
    output  wire    [3:0]   data_out_1,
    output  wire    [3:0]   data_out_2,
    output  wire    [3:0]   data_out_3,
    output  wire    [3:0]   data_out_4,
    output  wire    [3:0]   data_out_5,
    output  wire    [3:0]   data_out_6,
    output  wire    [3:0]   data_out_7
);
    
    reg [7:0]  decoder_out;
    wire cs_0 = decoder_out[0];
    wire cs_1 = decoder_out[1];
    wire cs_2 = decoder_out[2];
    wire cs_3 = decoder_out[3];
    wire cs_4 = decoder_out[4];
    wire cs_5 = decoder_out[5];
    wire cs_6 = decoder_out[6];
    wire cs_7 = decoder_out[7];

    always @(*) begin
        case (sel)
            3'd0:decoder_out = 8'b1111_1110;
            3'd1:decoder_out = 8'b1111_1101;
            3'd2:decoder_out = 8'b1111_1011;
            3'd3:decoder_out = 8'b1111_0111;
            3'd4:decoder_out = 8'b1110_1111;
            3'd5:decoder_out = 8'b1101_1111;
            3'd6:decoder_out = 8'b1011_1111;
            3'd7:decoder_out = 8'b0111_1111;
        endcase  
    end

D_unit_lxy D_unit_lxy_inst_0(
    .cs_n(cs_0),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_0) 
);

D_unit_lxy D_unit_lxy_inst_1(
    .cs_n(cs_1),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_1) 
);

D_unit_lxy D_unit_lxy_inst_2(
    .cs_n(cs_2),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_2) 
);

D_unit_lxy D_unit_lxy_inst_3(
    .cs_n(cs_3),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_3) 
);

D_unit_lxy D_unit_lxy_inst_4(
    .cs_n(cs_4),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_4) 
);

D_unit_lxy D_unit_lxy_inst_5(
    .cs_n(cs_5),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_5) 
);

D_unit_lxy D_unit_lxy_inst_6(
    .cs_n(cs_6),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_6) 
);

D_unit_lxy D_unit_lxy_inst_7(
    .cs_n(cs_7),
    .en(en),
    .data_in(data_in), 
    .data_out(data_out_7) 
);

endmodule