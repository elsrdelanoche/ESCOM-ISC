library ieee;
use ieee.std_logic_1164.all;
entity sumadorCompleto is
port (
A,B,carry: in std_logic;
sum, Cout: out std_logic);
end sumadorCompleto;
Architecture sumadorCArch of sumadorCompleto is
begin
sum <=(A xor B)xor carry;
Cout <= (A and B) or ((A xor B)and carry);
end sumadorCArch;

