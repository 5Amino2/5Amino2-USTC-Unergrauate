module state_lxy(sys_clk,en,st);
input sys_clk,en;
output reg [2:0] st;
reg [12:0] div;
parameter DIV_MAX = 13'd99_999;
always @(posedge sys_clk or negedge en) begin
    if (!en) div<=0;
	 else if(div==DIV_MAX) div<=0;
    else div <= div + 1;
end

always @(posedge sys_clk or negedge en) begin
    if (!en) begin
        st <= 0;
    end
    else  if (div == DIV_MAX) begin
        st <= st + 1;
    end
end
endmodule
