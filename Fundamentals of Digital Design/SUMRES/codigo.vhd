library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity sum_diff_2bit is
    Port ( a : in  STD_LOGIC_VECTOR (1 downto 0);
           b : in  STD_LOGIC_VECTOR (1 downto 0);
           operation : in  STD_LOGIC;
           seg : out  STD_LOGIC_VECTOR (6 downto 0));
end sum_diff_2bit;

architecture behavioral of sum_diff_2bit is
    signal sum_diff : STD_LOGIC_VECTOR (2 downto 0);
    signal result : STD_LOGIC_VECTOR (1 downto 0);
    signal negative : STD_LOGIC;
begin
    process(a, b, operation)
    begin
        sum_diff <= "000";
        negative <= '0';
        if operation = '0' then
			result <= std_logic_vector(unsigned(a) + unsigned(b));
            if result(1) = '1' then
                sum_diff <= "010";
            end if;
        else
            result <= std_logic_vector(unsigned(b) - unsigned(a));
            if result(1) = '0' then
                sum_diff <= "100";
                negative <= '1';
            end if;
        end if;
    end process;
    
    seg <= "1000000" when sum_diff = "000" and negative = '0' else
          "1111001" when sum_diff = "001" and negative = '0' else
          "0100100" when sum_diff = "010" and negative = '0' else
          "0110000" when sum_diff = "011" and negative = '0' else
          "0011001" when sum_diff = "100" and negative = '0' else
          "0010010" when sum_diff = "101" and negative = '0' else
          "0000010" when sum_diff = "110" and negative = '0' else
          "1111000" when sum_diff = "111" and negative = '0' else
          "1000000" when sum_diff = "000" and negative = '1' else
          "1100000" when sum_diff = "001" and negative = '1' else
          "0111000" when sum_diff = "010" and negative = '1' else
          "0000011" when sum_diff = "011" and negative = '1' else
          "0000000" when sum_diff = "100" and negative = '1' else
          "0010000" when sum_diff = "101" and negative = '1' else
          "0001000" when sum_diff = "110" and negative = '1' else
          "0000001" when sum_diff = "111" and negative = '1' else
          "1111111";
end behavioral;
