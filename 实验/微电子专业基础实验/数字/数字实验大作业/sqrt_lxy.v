`timescale 10ns/1ns
module sqrt_lxy #(parameter N = 16)(clk,rst_n,start,a,complete,root,remainder);
	input clk,rst_n,start;
	input [N+N-1:0] a;
	output complete;
	output [N-1:0] root;
	output [N:0] remainder;

	
	reg [2*N-1:0] A;//输入寄存器
	reg complete;//完成为1
	reg [N-1:0] root;//根
	reg [$clog2(N)-1:0] i;//迭代的计数器
	wire [N+N-1:0] ref;//
	
	assign remainder = A[N:0];
	assign ref = ((root << 1) + (1 << i)) << i;
	
	initial begin
	A=0;complete=1;root=0;i=0;
	end
	
	always @(posedge clk or negedge rst_n)
	begin
		if(!rst_n) //复位
		begin
			complete <= 1'b1;
			root <= 'b0;
			A <= 'b0;
			i <= 0;
		end
		
		else if(!complete)//迭代
		begin
			if (A >= ref)
				begin
				root[i] <= 1'b1;
				A <= A - ref;
				end
			else
				begin
				root[i] <= 1'b0;
				A <= A;
				end
			if(i == 0)//计算完成
				begin
				complete <= 1'b1;
				end
			else 
				begin
				i <= i - 1;
				end
		end
		
		else if(start) //启动
		begin
			i <= N - 1;
			complete <= 1'b0;
			root <= 'b0;
			A <= a;
		end
		
		else //没启动，无操作
		begin
		
		end
	end



endmodule
