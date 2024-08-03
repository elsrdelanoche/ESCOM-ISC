create view vwdc002CountNombreIncVial as
SELECT * FROM incidentesvia2dosem2020.vwdc001countidincvial
INNER JOIN cat002incidentesviales
ON cat002incidentesviales.id = vwdc001countidincvial.id_incidentevial;
 