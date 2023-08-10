library ieee;
use ieee.std_logic_1164.all;
entity contador is
    port(
        CLK,RESET: in bit;
        salida: out integer range 0 to 255);
end contador;
architecture estructura of contador is
begin
process (CLK,RESET)
variable cuenta : integer range 0 to 255;
begin
    if(RESET='1')Then
    cuenta:=0;
    elsif(CLK'event and CLK='1')Then
    cuenta:=cuenta+1;
    end if;
    salida<=cuenta;
end process;
end estructura ; -- estructura 