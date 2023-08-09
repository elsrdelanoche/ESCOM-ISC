library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity Variables is
    port(
        A: in std_logic;
        Y: out std_logic);
end;

architecture Arquitectura of Variables is 
begin
    Y <= A;

end Arquitectura;