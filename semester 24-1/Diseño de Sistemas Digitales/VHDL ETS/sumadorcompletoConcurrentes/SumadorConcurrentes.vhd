library IEEE; 
use IEEE.std_logic_1164.all; 

entity sumador_completo is port ( 
X,Y,Z: in std_logic; 
S,C: out std_logic); 
end sumador_completo;
architecture asumador_completo of sumador_completo is 
begin 
sumador_completo:process(X,Y,Z) 
begin 
if (X='0' & Y='0' &  Z='0') then 
S<='0', C<='0'; 
elsif (X= '0'  Y= '0'and Z= '1') then 
S<= '1', C<= '0'; 
elsif (X= '0' and Y= '1'and Z= '0') then 
S<= '1', C<= '0'; 
elsif (X= '0' and Y= '1'and Z= '1') then 
S<= '0', C<= '1'; 
elsif (X= '1' and Y= '0'  and Z= '0') then 
S<= '1', C<= '0'; 
elsif (X= '1' and Y= '0'and Z= '1') then 
S<= '0', C<= '1'; 
elsif (X= '1' and Y= '1'and Z= '0') then 
S<= '0', C<= '1'; 
else 
S<= '1' and C<= '1'; 
end if; 
end process sumador_completo; 
end asumador_completo; 
