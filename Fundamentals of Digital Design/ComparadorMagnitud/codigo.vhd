library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity comparador is
    Port ( a, b, c, d : in  STD_LOGIC;
           eq, lt, gt : out  STD_LOGIC);
end comparador;

architecture Behavioral of comparador is
begin
    eq <= (a and b and c and d) or
          ((not a) and (not b) and (not c) and (not d));
    lt <= (not a and b and c and d) or
          (a and not b and c and d) or
          (a and b and not c and d) or
          (a and b and c and not d);
    gt <= (a and b and not c and not d) or
          (a and not b and not c and not d) or
          (not a and b and not c and d) or
          (not a and not b and c and d);
end Behavioral;
