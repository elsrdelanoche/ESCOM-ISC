<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name = "viewport" content = "width=device-width, initial-scale=1.0">
	<title>consulta bd</title>
	<style type = "text/css">

		button{
   			align-content: center;
   			font-family: 'Roboto';
   			background: #4568DC;
   			background: -webkit-linear-gradient(to right, #B06AB3, #4568DC);
   			background: linear-gradient(to right, #B06AB3, #4568DC);
   			border: none;
   			display: block;
   			width: 70%;
   			margin: 10px auto;
   			color: #fff;
   			height: 40px;
   			cursor: pointer;
		}

		table {
			border: solid 2px #7e7c7c;
			border-collapse: collapse;
			justify-content: center; 
			align-items: center; 
			display: flex;
		}

		th, h1 {
			background-color: #edf797;
			font-size: 20px;
		}

		h2{
			font-size: 15px;
		}

		td,
		th {
			border: solid 1px #7e7c7c;
			padding: 2px;
			text-align: center;
		}

	</style>
</head>
<body>
</body>
</html>


<?php
//validamos datos del servidor
$user = "root";
$pass = "";
$host = "localhost";

//conectamos a la base de datos
$connection = mysqli_connect($host, $user, $pass);

//hacemos llamado al input del formulario
$nombre = $_POST['nombre'];
$aPaterno = $_POST['apellidoP'];
$aMaterno = $_POST['apellidoM'];
$fechaN = $_POST['fechaN'];
$curp = $_POST['curp'];
$gmail = $_POST['mail'];
$telefono = $_POST['telefono'];
$estado = $_POST['entidadF'];
$alcaldia = $_POST['alcaldia'];
$evento = $_POST['evento'];
$nPersonas = $_POST['personas'];
$horario = $_POST['horario'];
$folio = "undifined";

if (!$connection) {
	echo "No se ha podido conectar con el servidor" . mysql_error();
} else {
	echo "<b><h3>Hemos conectado al servidor</h3></b>";
}
//indicamos el nombre de la bd
$datab = "dj_bd";

//indicacmos seleccionar a la bd
$db = mysqli_select_db($connection, $datab);

if (!$db) {
	echo "No se ha podido encontrar la Tabla";
} else {
	echo "<h3>Tabla seleccionada:</h3>";
}

$instruction_SQL = "INSERT INTO datosclientes (nombre, aPaterno, aMaterno, fechaN, CURP, gmail, telefono, estado, alcaldia, evento, nPersonas, horario, folio)
	VALUES 
		('$nombre', '$aPaterno', '$aMaterno', '$fechaN', '$curp', '$gmail', '$telefono', '$estado', '$alcaldia','evento','nPersonas' ,'$horario' , '$folio')";

$resultado = mysqli_query($connection, $instruction_SQL);

$consulta = "SELECT * FROM datosclientes";

$result = mysqli_query($connection, $consulta);

if (!$result) {
	echo "No se ha podido realizar la consulta";
}

echo "<table>";
echo "<tr>";
echo "<th><h1>id</th></h1>";
echo "<th><h1>Nombre</th></h1>";
echo "<th><h1>Apellido Paterno</th></h1>";
echo "<th><h1>Apellido Materno</th></h1>";
echo "<th><h1>Fecha de nacimiento</th></h1>";
echo "<th><h1>CURP</th></h1>";
echo "<th><h1>Correo Electronico</th></h1>";
echo "<th><h1>Telefono</th></h1>";
echo "<th><h1>Estado</th></h1>";
echo "<th><h1>Alcaldia</th></h1>";
echo "<th><h1>Evento</th></h1>";
echo "<th><h1>Numero de Personas</th></h1>";
echo "<th><h1>Horario</th></h1>";
echo "<th><h1>Folio</th></h1>";
echo "</tr>";

while ($colum = mysqli_fetch_array($result)){
	echo "<tr>";
	echo "<td><h2>" . $colum['idCliente'] . "</td></h2>";
	echo "<td><h2>" . $colum['nombre'] . "</td></h2>";
	echo "<td><h2>" . $colum['aPaterno'] . "</td></h2>";
	echo "<td><h2>" . $colum['aMaterno'] . "</td></h2>";
	echo "<td><h2>" . $colum['fechaN'] . "</td></h2>";
	echo "<td><h2>" . $colum['CURP'] . "</td></h2>";
	echo "<td><h2>" . $colum['gmail'] . "</td></h2>";
	echo "<td><h2>" . $colum['telefono'] . "</td></h2>";
	echo "<td><h2>" . $colum['estado'] . "</td></h2>";
	echo "<td><h2>" . $colum['alcaldia'] . "</td></h2>";
	echo "<td><h2>" . $colum['evento'] . "</td></h2>";
	echo "<td><h2>" . $colum['nPersonas'] . "</td></h2>";
	echo "<td><h2>" . $colum['horario'] . "</td></h2>";
	echo "<td><h2>" . $colum['folio'] . "</td></h2>";
	echo "<td><button>Actualizar</button></td>";
	echo "<td><button>Eliminar</button></td>";
	echo "</tr>";
}

echo "</table>";

mysqli_close($connection);

?>

