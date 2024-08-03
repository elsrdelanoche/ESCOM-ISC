SELECT 
	datepart(DW,fecha) as dia,
	SUM(ingreso) AS ingreso,
	linea
FROM ingresos_metro
GROUP BY datepart(DW,fecha),linea
ORDER BY datepart(DW,fecha),linea