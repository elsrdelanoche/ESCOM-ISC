module bin_to_7seg ( 
	clk,
	bin_in,
	seg
	) ;

input  clk;
input [3:0] bin_in;
inout [6:0] seg;
