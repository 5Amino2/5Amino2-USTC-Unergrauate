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
        4'd10:data_out <= 8'b1100_0100; //c,d,e,g,dp
        4'd11:data_out <= 8'b1100_0001;//c,d,e,f,g
        4'd12:data_out <= 8'b1110_0101;//d,e,g
        4'd13:data_out <= 8'b1000_0101;//b,c,d,e,g
        4'd14:data_out <= 8'b0110_0001;//a,d,e,f,g
        4'd15:data_out <= 8'b0111_0001;//a,e,f,g
    endcase
end
    
endmodule