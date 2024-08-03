<?php
	$user = "root";
	$pass = "";
	$host = "localhost";
	//conectamos a la base de datos
	$connection = mysqli_connect($host, $user, $pass);
	$datab = "dj_bd";
	mysqli_select_db($connection,$datab);

?>