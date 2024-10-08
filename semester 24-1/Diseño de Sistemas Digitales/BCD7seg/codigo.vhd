library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bcd_7seg is
    Port ( B0,B1,B2,B3 : in STD_LOGIC;
    A,B,C,D,E,F,G : out STD_LOGIC);
end bcd_7seg;

architecture Behavioral of bcd_7seg is begin
    A <= B0 OR B2 OR (B1 AND B3) OR (NOT B1 AND NOT B3);
    B <= (NOT B1) OR (NOT B2 AND NOT B3) OR (B2 AND B3);
    C <= B1 OR NOT B2 OR B3;
    D <= (NOT B1 AND NOT B3) OR (B2 AND NOT B3) OR (B1 AND NOT B2 AND B3) OR (NOT B1 AND B2) OR B0;
    E <= (NOT B1 AND NOT B3) OR (B2 AND NOT B3);
    F <= B0 OR (NOT B2 AND NOT B3) OR (B1 AND NOT B2) OR (B1 AND NOT B3);
    G <= B0 OR (B1 AND NOT B2) OR ( NOT B1 AND B2) OR (B2 AND NOT B3);
end Behavioral;  
