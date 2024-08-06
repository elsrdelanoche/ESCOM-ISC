--Proyecto Maquina Expendedora DSD
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity MaquinaExpendedora is
    Port (
        direccion : in  std_logic_vector(1 downto 0);
        precio_prod : out std_logic_vector(3 downto 0); --precio productos
        cambio : out std_logic_vector(7 downto 0); --cambio de productos 7 segmentos
        --Monedas entrantes 
        in_005 : in std_logic; 
        in_010 : in std_logic;
        in_020 : in std_logic;
        in_050 : in std_logic;
        in_100 : in std_logic;
        clock : in std_logic;
        reset : in std_logic;
        dulce : out std_logic --Indica si se dara el dulce
    );
end MaquinaExpendedora;

architecture arqMachine of MaquinaExpendedora is
    type memoria_catalogo is array (0 to 3) of std_logic_vector(3 downto 0);
    signal catalogo : memoria_catalogo;
    type estado is (C000,C005,C010,C015,C020,C025,C030,C035,C040,C045,C050,C055,C060,C065,C070,C075,C080,C085,C090,C95,C100);--Los Creditos
    signal q_presente, q_siguiente : estado;

begin
    
    -- Proceso de inicialización memoria
    process
    begin
        catalogo <= ("0100", "0101", "0110", "0000");--Precios
    end process;

	-- Logica secuencial
    process(clock, q_presente,reset)
    begin 
        if reset = '1' then
            q_presente <= C000;
        elsif rising_edge(clock) then
            q_presente <= q_siguiente;
        end if;
    end process;

    -- Proceso principal
    process(direccion, q_presente, in_005, in_010, in_020, in_050, in_100, catalogo)
    begin
        case direccion is
            when "00" =>
                precio_prod <= catalogo(0);
                -- Maquina de estados para creminos, su precio al publco es de 4 pesos
                case q_presente is
                    when C000 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C050;
                        elsif in_100 = '1' then
                            q_siguiente <= C100;    
                        else
                            q_siguiente <= C000;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; -- 0pesos de cambio
        
                    when C005 => 
                        if in_005 = '1' then
                            q_siguiente <= C010;
                        elsif in_010 = '1' then
                            q_siguiente <= C015;
                        elsif in_020 = '1' then
                            q_siguiente <= C025;
                        elsif in_050 = '1' then
                            q_siguiente <= C055;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C005;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C010 => 
                        if in_005 = '1' then
                            q_siguiente <= C015;
                        elsif in_010 = '1' then
                            q_siguiente <= C020;
                        elsif in_020 = '1' then
                            q_siguiente <= C030;
                        elsif in_050 = '1' then
                            q_siguiente <= C060;
                        --elsif in_100 = '1' then
                            ---q_siguiente <= C100;    
                        else
                            q_siguiente <= C010;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C015 => 
                        if in_005 = '1' then
                            q_siguiente <= C020;
                        elsif in_010 = '1' then
                            q_siguiente <= C025;
                        elsif in_020 = '1' then
                            q_siguiente <= C035;
                        elsif in_050 = '1' then
                            q_siguiente <= C065;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C015;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C020 => 
                        if in_005 = '1' then
                            q_siguiente <= C025;
                        elsif in_010 = '1' then
                            q_siguiente <= C030;
                        elsif in_020 = '1' then
                            q_siguiente <= C040;
                        elsif in_050 = '1' then
                            q_siguiente <= C070;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C020;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C025 => 
                        if in_005 = '1' then
                            q_siguiente <= C030;
                        elsif in_010 = '1' then
                            q_siguiente <= C035;
                        elsif in_020 = '1' then
                            q_siguiente <= C045;
                        elsif in_050 = '1' then
                            q_siguiente <= C075;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C025;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C030 => 
                        if in_005 = '1' then
                            q_siguiente <= C035;
                        elsif in_010 = '1' then
                            q_siguiente <= C040;
                        elsif in_020 = '1' then
                            q_siguiente <= C050;
                        elsif in_050 = '1' then
                            q_siguiente <= C080;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C030;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C035 => 
                        if in_005 = '1' then
                            q_siguiente <= C040;
                        elsif in_010 = '1' then
                            q_siguiente <= C045;
                        elsif in_020 = '1' then
                            q_siguiente <= C055;
                        elsif in_050 = '1' then
                            q_siguiente <= C085;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C035;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C040 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C050;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C000;
                        end if;
                        dulce <= '1';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C045 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                            q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "00000001"; --medio peso de cambio
        
                    when C050 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100000"; --1 pesos de cambio
        
                    when C055 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100001"; --1.5 pesos de cambio
        
                    when C060 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011010"; --2 pesos de cambio
        
                    when C065 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011011"; --2.5 pesos de cambio
        
                    when C070 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110010"; --3 pesos de cambio
        
                    when C075 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110011"; --3.5 pesos de cambio
        
                    when C080 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100110"; --4 pesos de cambio
        
                    when C085 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100111"; --4.5 pesos de cambio
        
                    --when C090 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        --q_siguiente <= C000;
                        --end if;
                        --dulce <= '1';
                        --cambio <= "01100111"; --4.5 pesos de cambio
        
                    --when C095 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        --q_siguiente <= C000;
                        --end if;
                        --dulce <= '1';
                        --cambio <= "01100111"; --4.5 pesos de cambio
        
                    when C100 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "10111110"; --6 pesos de cambio


                    when others => 
                        q_siguiente <= C000;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
                end case;
                
                

            when "01" =>
                precio_prod <= catalogo(1);
                -- Maquina de estados para Mazapan, su precio al publico es de 5peso
                case q_presente is
                    when C000 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C050;
                        elsif in_100 = '1' then
                            q_siguiente <= C100;    
                        else
                            q_siguiente <= C000;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; -- 0pesos de cambio
        
                    when C005 => 
                        if in_005 = '1' then
                            q_siguiente <= C010;
                        elsif in_010 = '1' then
                            q_siguiente <= C015;
                        elsif in_020 = '1' then
                            q_siguiente <= C025;
                        elsif in_050 = '1' then
                            q_siguiente <= C055;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C005;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C010 => 
                        if in_005 = '1' then
                            q_siguiente <= C015;
                        elsif in_010 = '1' then
                            q_siguiente <= C020;
                        elsif in_020 = '1' then
                            q_siguiente <= C030;
                        elsif in_050 = '1' then
                            q_siguiente <= C060;
                        --elsif in_100 = '1' then
                            ---q_siguiente <= C100;    
                        else
                            q_siguiente <= C010;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C015 => 
                        if in_005 = '1' then
                            q_siguiente <= C020;
                        elsif in_010 = '1' then
                            q_siguiente <= C025;
                        elsif in_020 = '1' then
                            q_siguiente <= C035;
                        elsif in_050 = '1' then
                            q_siguiente <= C065;
                       -- elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C015;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C020 => 
                        if in_005 = '1' then
                            q_siguiente <= C025;
                        elsif in_010 = '1' then
                            q_siguiente <= C030;
                        elsif in_020 = '1' then
                            q_siguiente <= C040;
                        elsif in_050 = '1' then
                            q_siguiente <= C070;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C020;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C025 => 
                        if in_005 = '1' then
                            q_siguiente <= C030;
                        elsif in_010 = '1' then
                            q_siguiente <= C035;
                        elsif in_020 = '1' then
                            q_siguiente <= C045;
                        elsif in_050 = '1' then
                            q_siguiente <= C075;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C025;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C030 => 
                        if in_005 = '1' then
                            q_siguiente <= C035;
                        elsif in_010 = '1' then
                            q_siguiente <= C040;
                        elsif in_020 = '1' then
                            q_siguiente <= C050;
                        elsif in_050 = '1' then
                            q_siguiente <= C080;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C030;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C035 => 
                        if in_005 = '1' then
                            q_siguiente <= C040;
                        elsif in_010 = '1' then
                            q_siguiente <= C045;
                        elsif in_020 = '1' then
                            q_siguiente <= C055;
                        elsif in_050 = '1' then
                            q_siguiente <= C085;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C035;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C040 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C090;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C040;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C045 => 
                        if in_005 = '1' then
                            q_siguiente <= C050;
                        elsif in_010 = '1' then
                            q_siguiente <= C055;
                        elsif in_020 = '1' then
                            q_siguiente <= C065;
                        elsif in_050 = '1' then
                            q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C045;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C050 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C050;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C000;
                        end if;
                        dulce <= '1';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C055 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "00000001"; --medio peso de cambio
        
                    when C060 => 
                        --if in_005 = '1' then
                           -- q_siguiente <= C005;
                        --elsif in_010 = '1' then
                          --  q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100000"; --1 pesos de cambio
        
                    when C065 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100001"; --1.5 pesos de cambio
        
                    when C070 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011010"; --2 pesos de cambio
        
                    when C075 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011011"; --2.5 pesos de cambio
        
                    when C080 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110010"; --3 pesos de cambio
        
                    when C085 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110011"; --3.5 pesos de cambio
        
                    when C090 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        ccambio <= "01100110"; --4 pesos de cambio
        
                    when C095 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100111"; --4.5 pesos de cambio
        
                    when C100 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "10110110"; --5 pesos de cambio


                    when others => 
                        q_siguiente <= C000;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
                end case;



            when "10" =>
                precio_prod <= catalogo(2);
                 -- Maquina de estados para Lucas, su precio al publico es de 6 pesos
                 case q_presente is
                    when C000 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C050;
                        elsif in_100 = '1' then
                            q_siguiente <= C100;    
                        else
                            q_siguiente <= C000;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; -- 0pesos de cambio
        
                    when C005 => 
                        if in_005 = '1' then
                            q_siguiente <= C010;
                        elsif in_010 = '1' then
                            q_siguiente <= C015;
                        elsif in_020 = '1' then
                            q_siguiente <= C025;
                        elsif in_050 = '1' then
                            q_siguiente <= C055;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C005;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C010 => 
                        if in_005 = '1' then
                            q_siguiente <= C015;
                        elsif in_010 = '1' then
                            q_siguiente <= C020;
                        elsif in_020 = '1' then
                            q_siguiente <= C030;
                        elsif in_050 = '1' then
                            q_siguiente <= C060;
                        --elsif in_100 = '1' then
                            ---q_siguiente <= C100;    
                        else
                            q_siguiente <= C010;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C015 => 
                        if in_005 = '1' then
                            q_siguiente <= C020;
                        elsif in_010 = '1' then
                            q_siguiente <= C025;
                        elsif in_020 = '1' then
                            q_siguiente <= C035;
                        elsif in_050 = '1' then
                            q_siguiente <= C065;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C015;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C020 => 
                        if in_005 = '1' then
                            q_siguiente <= C025;
                        elsif in_010 = '1' then
                            q_siguiente <= C030;
                        elsif in_020 = '1' then
                            q_siguiente <= C040;
                        elsif in_050 = '1' then
                            q_siguiente <= C070;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C020;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C025 => 
                        if in_005 = '1' then
                            q_siguiente <= C030;
                        elsif in_010 = '1' then
                            q_siguiente <= C035;
                        elsif in_020 = '1' then
                            q_siguiente <= C045;
                        elsif in_050 = '1' then
                            q_siguiente <= C075;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C025;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C030 => 
                        if in_005 = '1' then
                            q_siguiente <= C035;
                        elsif in_010 = '1' then
                            q_siguiente <= C040;
                        elsif in_020 = '1' then
                            q_siguiente <= C050;
                        elsif in_050 = '1' then
                            q_siguiente <= C080;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C030;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C035 => 
                        if in_005 = '1' then
                            q_siguiente <= C040;
                        elsif in_010 = '1' then
                            q_siguiente <= C045;
                        elsif in_020 = '1' then
                            q_siguiente <= C055;
                        elsif in_050 = '1' then
                            q_siguiente <= C085;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C035;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C040 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        elsif in_050 = '1' then
                            q_siguiente <= C090;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C040;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C045 => 
                        if in_005 = '1' then
                            q_siguiente <= C050;
                        elsif in_010 = '1' then
                            q_siguiente <= C055;
                        elsif in_020 = '1' then
                            q_siguiente <= C065;
                        elsif in_050 = '1' then
                            q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C045;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C050 => 
                        if in_005 = '1' then
                            q_siguiente <= C055;
                        elsif in_010 = '1' then
                            q_siguiente <= C060;
                        elsif in_020 = '1' then
                            q_siguiente <= C070;
                        elsif in_050 = '1' then
                            q_siguiente <= C100;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C050;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C055 => 
                        if in_005 = '1' then
                            q_siguiente <= C060;
                        elsif in_010 = '1' then
                            q_siguiente <= C065;
                        elsif in_020 = '1' then
                            q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        else
                            q_siguiente <= C055;
                        end if;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C060 => 
                        if in_005 = '1' then
                            q_siguiente <= C005;
                        elsif in_010 = '1' then
                            q_siguiente <= C010;
                        elsif in_020 = '1' then
                            q_siguiente <= C020;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11111100"; --0 pesos de cambio
        
                    when C065 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "00000001"; --medio peso de cambio
        
                    when C070 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100000"; --1 pesos de cambio
        
                    when C075 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100001"; --1.5 pesos de cambio
        
                    when C080 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011010"; --2 pesos de cambio
        
                    when C085 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11011011"; --2.5 pesos de cambio
        
                    when C090 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110010"; --3 pesos de cambio
        
                    when C095 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "11110011"; --3.5 pesos de cambio
        
                    when C100 => 
                        --if in_005 = '1' then
                          --  q_siguiente <= C050;
                        --elsif in_010 = '1' then
                            --q_siguiente <= C055;
                        --elsif in_020 = '1' then
                            --q_siguiente <= C065;
                        --elsif in_050 = '1' then
                            --q_siguiente <= C095;
                        --elsif in_100 = '1' then
                            --q_siguiente <= C100;    
                        --else
                        q_siguiente <= C000;
                        --end if;
                        dulce <= '1';
                        cambio <= "01100110"; --4 pesos de cambio


                    when others => 
                        q_siguiente <= C000;
                        dulce <= '0';
                        cambio <= "11111100"; --0 pesos de cambio
                end case;
            when others =>
                precio_prod <= "1111";
                -- Maquina de estados correspondiente
        end case;
    end process;

end arqMachine;