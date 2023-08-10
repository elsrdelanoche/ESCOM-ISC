library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity full_adder_3bit is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           b : in  STD_LOGIC_VECTOR (2 downto 0);
           c_in : in  STD_LOGIC;
           sum : out  STD_LOGIC_VECTOR (2 downto 0);
           c_out : out  STD_LOGIC);
end full_adder_3bit;

architecture behavioral of full_adder_3bit is
    signal c1, c2, c3 : STD_LOGIC;
begin
    process(a, b, c_in)
    begin
        sum(0) <= a(0) xor b(0) xor c_in;
        c1 <= (a(0) and b(0)) or (b(0) and c_in) or (a(0) and c_in);
        sum(1) <= a(1) xor b(1) xor c1;
        c2 <= (a(1) and b(1)) or (b(1) and c1) or (a(1) and c1);
        sum(2) <= (a(2) and b(2)) xor (a(2) and c2) xor (b(2) and c2);
        c3 <= (a(2) and b(2)) or (b(2) and c2) or (a(2) and c2);
    end process;
    c_out <= c3;
end behavioral;
