SET SQL_SAFE_UPDATES=0;


Update tlb001reporteincidentevial
Set tlb001reporteincidentevial.id_incidentevial =
(
select id from cat002incidentesviales where nombre LIKE tlb001reporteincidentevial.incidente_c4 
); 

Update tlb001reporteincidentevial
Set tlb001reporteincidentevial.id_delegacion =
(
select id from cat001delegaciones where nombre LIKE tlb001reporteincidentevial.idDelegacion 
); 


SET SQL_SAFE_UPDATES=1;
 