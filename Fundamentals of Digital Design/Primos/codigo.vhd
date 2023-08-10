library ieee;
use ieee.std_logic_1164.all;
entity PRIMOS is port (
ENT : in std_logic_vector(3 downto 0);
F : out std_logic);
end PRIMOS;
architecture APRIMOS of PRIMOS is begin
F<=‘1’ when ENT=“0010” else
 ‘1’ when ENT=“0011” else
 ‘1’ when ENT=“0101” else
 ‘1’ when ENT=“0111” else
 ‘1’ when ENT=“1011” else
 ‘1’ when ENT=“1101” else
 ‘0’;
end APRIMOS;