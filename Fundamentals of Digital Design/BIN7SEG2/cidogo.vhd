library ieee;
use ieee.std_logic_1164.all;

entity bin_to_7seg is
    port (
        clk : in std_logic;
        bin_in : in std_logic_vector(3 downto 0);
        seg : out std_logic_vector(6 downto 0)
    );
end entity;

architecture behavior of bin_to_7seg is
begin
    seg <= 
        "0000001" when (bin_in = "0000") else
        "1001111" when (bin_in = "0001") else
        "0010010" when (bin_in = "0010") else
        "0000110" when (bin_in = "0011") else
        "1001100" when (bin_in = "0100") else
        "0100100" when (bin_in = "0101") else
        "0100000" when (bin_in = "0110") else
        "0001111" when (bin_in = "0111") else
        "0000000" when (bin_in = "1000") else
        "0001100" when (bin_in = "1001") else
        "1111111";
end architecture;
