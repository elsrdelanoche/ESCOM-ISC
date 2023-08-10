
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: codigo.vhd

--    Date: Wed Feb 01 01:04:02 2023

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-25PC/PI
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY full_adder_3bit IS
    PORT (
	                   a :    in std_logic_vector (2 downto 0) ;
	                   b :    in std_logic_vector (2 downto 0) ;
	                c_in :    in std_logic ;
	                 sum : inout std_logic_vector (2 downto 0) ;
	               c_out : inout std_logic
    );
END full_adder_3bit;

-- End of Test Bench Header

ARCHITECTURE DSMB of full_adder_3bit is

	signal jed_node1	: std_logic:='0' ; -- b(2)
	signal jed_node2	: std_logic:='0' ; -- a(2)
	signal jed_node3	: std_logic:='0' ; -- c_in
	signal jed_node4	: std_logic:='0' ; -- b(1)
	signal jed_node5	: std_logic:='0' ; -- b(0)
	signal jed_node6	: std_logic:='0' ; -- a(1)
	signal jed_node7	: std_logic:='0' ; -- a(0)
	signal jed_node8	: std_logic:='0' ;
	signal jed_node9	: std_logic:='0' ;
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node21	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of b(2):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of a(2):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of c_in:SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of b(1):SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of b(0):SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of a(1):SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of a(0):SIGNAL is "0007";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of sum(0):SIGNAL is "0014";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of sum(1):SIGNAL is "0016";

SIGNAL  jed_oept_18:std_logic:='0';
SIGNAL  jed_sum_18,jed_fb_18:std_logic:='0';
--Attribute PIN_NUMBERS of sum(2):SIGNAL is "0018";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of c_out:SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= b(2) ;
jed_node2 <= a(2) ;
jed_node3 <= c_in ;
jed_node4 <= b(1) ;
jed_node5 <= b(0) ;
jed_node6 <= a(1) ;
jed_node7 <= a(0) ;
Mcell_14:c22v10m
generic map(comb,
   ninv,
   xpin,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_14,
     clk=>jed_node1,
     oe=>jed_oept_14,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>sum(0),
     fb=>jed_fb_14
   );

Mcell_16:c22v10m
generic map(comb,
   ninv,
   xpin,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>sum(1),
     fb=>jed_fb_16
   );

Mcell_18:c22v10m
generic map(comb,
   ninv,
   xpin,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_18,
     clk=>jed_node1,
     oe=>jed_oept_18,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>sum(2),
     fb=>jed_fb_18
   );

Mcell_23:c22v10m
generic map(comb,
   ninv,
   xpin,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>c_out,
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_node3) and (jed_node5) and (jed_node7)) or
((jed_node3) and not(jed_node5) and not(jed_node7)) or
(not(jed_node3) and (jed_node5) and not(jed_node7)) or
(not(jed_node3) and not(jed_node5) and (jed_node7)));

jed_oept_16<=(one);

jed_sum_16<= (((jed_node3) and (jed_node4) and (jed_node5) and (jed_node6)
) or
((jed_node3) and (jed_node4) and (jed_node6) and (jed_node7)
) or
((jed_node4) and (jed_node5) and (jed_node6) and (jed_node7)
) or
((jed_node4) and not(jed_node5) and not(jed_node6) and not(jed_node7)
) or
((jed_node3) and not(jed_node4) and (jed_node5) and not(jed_node6)
) or
((jed_node3) and not(jed_node4) and not(jed_node6) and (jed_node7)
) or
(not(jed_node4) and (jed_node5) and not(jed_node6) and (jed_node7)
) or
(not(jed_node4) and not(jed_node5) and (jed_node6) and not(jed_node7)
) or
(not(jed_node3) and (jed_node4) and not(jed_node6) and not(jed_node7)
) or
(not(jed_node3) and (jed_node4) and not(jed_node5) and not(jed_node6)
) or
(not(jed_node3) and not(jed_node4) and (jed_node6) and not(jed_node7)
) or
(not(jed_node3) and not(jed_node4) and not(jed_node5)
 and (jed_node6)));

jed_oept_18<=(one);

jed_sum_18<= (((jed_node1) and (jed_node3) and (jed_node4) and (jed_node5)
) or
((jed_node2) and (jed_node3) and (jed_node4) and (jed_node5)
) or
((jed_node1) and (jed_node3) and (jed_node5) and (jed_node6)
) or
((jed_node2) and (jed_node3) and (jed_node5) and (jed_node6)
) or
((jed_node1) and (jed_node3) and (jed_node4) and (jed_node7)
) or
((jed_node1) and (jed_node4) and (jed_node5) and (jed_node7)
) or
((jed_node2) and (jed_node3) and (jed_node4) and (jed_node7)
) or
((jed_node2) and (jed_node4) and (jed_node5) and (jed_node7)
) or
((jed_node1) and (jed_node3) and (jed_node6) and (jed_node7)
) or
((jed_node1) and (jed_node5) and (jed_node6) and (jed_node7)
) or
((jed_node2) and (jed_node3) and (jed_node6) and (jed_node7)
) or
((jed_node2) and (jed_node5) and (jed_node6) and (jed_node7)
) or
((jed_node1) and (jed_node4) and (jed_node6)) or
((jed_node2) and (jed_node4) and (jed_node6)) or
((jed_node1) and (jed_node2)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_fb_18)));

end DSMB;
