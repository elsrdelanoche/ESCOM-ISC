create view vwdc002CountIDIncVialMes as

SELECT id_incidentevial, mes, count(id_incidentevial) as Cant
 FROM incidentesvia2dosem2020.tlb001reporteincidentevial
group by  id_incidentevial, mes
order by Cant, mes asc