<?php

$usuario=$_POST['username'];
$password=$_POST['password'];

session_start();

$_SESSION['usuario'] = $usuario;

include('conexion.php');

$consulta="SELECT * FROM usuarios where usuario = '$usuario' and password = '$password'";
$resultado = mysqli_query($connection, $consulta);

$filas = mysqli_num_rows($resultado);

if ($filas) {
	header("location:admincrud.php");
}else{
	?>
	<?php
	include("indexadmin.php");
	?>
	<h1 class = "bad">ERROR EN LA VALIDACION DE DATOS!</h1>
	<?php
}
mysqli_free_result($resultado);
mysqli_close($connection);
?>