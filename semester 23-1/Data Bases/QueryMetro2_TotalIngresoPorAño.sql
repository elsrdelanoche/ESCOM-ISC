SELECT 
	year(fecha) as año,
	SUM(ingreso) AS TOTAL_INGRESO 
FROM ingresos_metro
GROUP BY year(fecha)
ORDER BY year(fecha)