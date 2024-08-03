library ieee; 
use ieee.std_logic_1164.all;
entity mediosumador is
port ( A: in std_logic;
	   B: in std_logic;
	   sum: out std_logic;
	   cout: out std_logic);
end mediosumador;
	ARCHITECTURE mediosumarch of mediosumador is
    begin
	cout <=A and B ;
	sum <=A xor B;
	end mediosumarch;
