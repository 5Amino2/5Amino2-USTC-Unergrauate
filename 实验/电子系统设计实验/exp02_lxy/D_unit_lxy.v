module D_unit_lxy (
    input   wire            cs_n,
    input   wire            en,
    input   wire    [3:0]   data_in, 
    output  reg     [3:0]   data_out 
);

always @(*) begin
    if ((en == 1'b1) && (cs_n == 1'b0)) begin
        data_out <= data_in;
    end
    else begin
        data_out <= data_out;
    end
end

endmodule