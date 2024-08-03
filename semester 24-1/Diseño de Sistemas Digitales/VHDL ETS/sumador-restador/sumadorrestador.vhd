library ieee;
use ieee.std_logic_1164.all;
entity sumadorrestador is
port (
A,B,carry,estado: in std_logic;
sum, Cout: out std_logic);
 end sumadorrestador;

 Architecture asumres of sumadorrestador is
 begin
 process(estado,A,B,carry)
 begin
 if estado='0' then 
 sum <= A xor B xor carry;
Cout <= (A and B) or ((A xor B)and carry);
else if estado='1' then
sum <= A xor B xor carry;
Cout <= ((not A and (B or carry)) or (B and carry));
end if;
end if;
end process;
 end asumres;
