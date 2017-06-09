`timescale 1ns / 1ps

module alu_four(
		input wire [1:0] opcode,
		input wire [3:0] a,b,
		output wire [3:0] result,
		output wire cf,sf,zf
	);
	reg signed [4:0]res;
	reg c,s,z;
	//opcodes: 00 : and, 01 : or , 10 : add, 01 : sub
	always @(*) begin
		c=0;
		s=0;
		z=0;
		if (opcode==2'b00) 	begin
			res[3:0] = a & b;	
			res[4]=0;
		end 
		if (opcode==2'b01) 	begin
			res[3:0] = a | b;	
			res[4]=0;
		end 
		if (opcode==2'b10) 	begin
			res = a + b;	
		end 
		if (opcode==2'b11) 	begin
			res = a - b;	
			$monitor(res[3:0]);
		end 
		if (res[3:0]==4'b0000) begin
				z = 1;
		end
		if (res[4]==1 && opcode==2'b11) begin
				s = 1;
				res= ~res;
				res=res+1;
		end
		if (res[4]==1 && opcode==2'b10) begin
				c = 1;
		end
		
	end
	assign result = res[3:0];
	assign zf = z;
	assign cf = c;
	assign sf = s;
	// assign result = res;
endmodule

module q2a3(

input clk,
input rr1b,
input rr2b,
input wrb,
input wdatab,
input wire[3:0] X,
input wenable,
output reg[3:0] outdata1,
output reg[3:0] outdata2
);
reg[3:0] rr1;
reg[3:0] rr2;
reg[3:0] wr;
reg[3:0] wdata;
reg wenable_store;
reg[3:0] file [15:0];

initial begin

	file[0]=4'b1000;
	file[1]=4'b0000;
	file[2]=4'b0000;
	file[3]=4'b0000;
	file[4]=4'b0000;
	file[5]=4'b0000;
	file[6]=4'b0000;
	file[7]=4'b0000;
	file[8]=4'b0000;
	file[9]=4'b0000;
	file[10]=4'b0000;
	file[11]=4'b0000;
	file[12]=4'b0000;
	file[13]=4'b0000;
	file[14]=4'b0000;
	file[15]=4'b0000;


end
// or rr1b or rr2b or wrb or wdatab or wenable
always @(posedge clk)
begin
  if(rr1b)	rr1 = X;
  if(rr2b)	rr2 = X;
  if(wrb)	wr = X;
  if(wdatab)	wdata = X;
  if(wenable)   wenable_store = 1;
  if(wenable_store == 1) begin
    file[wr] = wdata;
    wenable_store =0;
  end
  outdata1 = file[rr1];
  outdata2 = file[rr2];  

end	
endmodule  

module proc( 
	input wire clk,
	input [2:0] opcode,
	input [3:0] in,
	input wenable, rrb1, rrb2, wrb, wdatab,
	output [3:0] result,
	output c, s, z, invalidbit
);

wire [3:0] r1;
wire [3:0] r2;
reg [3:0] X;
reg [3:0] reg1, reg2;

assign rr1b = 0;
assign rr2b = 0;
assign wrb = 0;

assign invalidbit = 1'b0;

q2a3 ex1( .rr1b( rr1b ), .rr2b( rr2b ), .wrb( wrb ), .wdatab( wdatab ), .X( X ), .wenable( wenable ), .outdata1(r1), .outdata2(r2) );
alu_four rx1( .opcode(opcode[1:0]), .a(r1[3:0]), .b(r2[3:0]), .result(result), .cf(c), .sf(s), .zf(z) );

always @(posedge clk) begin
	
	if ( opcode==3'b100 ) begin

		if( wrb == 1'b1) begin
			X = in;
		end
		if( wdatab == 1'b1 ) begin
			X = in;
		end
			
	end
	else begin
		if( opcode==3'b000 || opcode==3'b001 || opcode==3'b010 || opcode!=3'b011 ) begin
			if( rrb1 == 1'b1 )begin
				X = in;
			end
			if( rrb2 == 1'b1 )begin	
				X = in	;
			end			
		end 
		else begin
			assign invalidbit = 1'b1;
		end
	end
end
endmodule