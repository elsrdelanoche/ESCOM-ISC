library ieee;
use ieee.std_logic_1164.all;
entity restador is
port ( 
	   A,B: in std_logic;
	   R,Carry: out std_logic);
end restador;

Architecture arestador of restador is
begin
Carry <=((NOT A)and B);
R<= A XOR B;
end arestador;


