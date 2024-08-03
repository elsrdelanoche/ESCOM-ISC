select 
	year(fecha) as años
	

from ingresos_metro
group by year(fecha)