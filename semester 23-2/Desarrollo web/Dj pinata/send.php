<?php
$user = "root";
$pass = "";
$host = "localhost";
//conectamos a la base de datos
$connection = mysqli_connect($host, $user, $pass);

//hacemos llamado al input del formulario
if (!$connection) {
    echo "No se ha podido conectar con el servidor" . mysql_error();
}

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

    if ($resultado) {
        ?>
            <h3 class = "ok">Se ha registrado correctamente!</h3>
        <?php
    } else {
        ?>
            <h3 class = "bad">Ha ocurrido un error!</h3>
        <?php
    }
?>