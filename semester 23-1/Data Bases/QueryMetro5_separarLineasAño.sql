SELECT 
	year(fecha) as año,
	SUM(ingreso) AS TOTAL_INGRESO,
	linea
FROM ingresos_metro
GROUP BY year(fecha), linea
ORDER BY linea,year(fecha)