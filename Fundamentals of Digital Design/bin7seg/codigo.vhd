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
    signal seg_temp : std_logic_vector(6 downto 0);
begin
    process (bin_in)
    begin
        case bin_in is
            when "0000" => seg_temp <= "0000001";
            when "0001" => seg_temp <= "1001111";
            when "0010" => seg_temp <= "0010010";
            when "0011" => seg_temp <= "0000110";
            when "0100" => seg_temp <= "1001100";
            when "0101" => seg_temp <= "0100100";
            when "0110" => seg_temp <= "0100000";
            when "0111" => seg_temp <= "0001111";
            when "1000" => seg_temp <= "0000000";
            when "1001" => seg_temp <= "0001100";
            when others => seg_temp <= "1111111";
        end case;
    end process;
    seg <= seg_temp;
end architecture;
