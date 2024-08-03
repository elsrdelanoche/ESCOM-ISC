<!DOCTYPE html>
<html>
<head>
  <title>Inicio de sesión</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css">
  <link rel="stylesheet">
  <link rel="icon" href="imgs/DJ.png" type="image/png">
  
  <style type = "text/css">

        button{
            align-content: center;
            font-family: 'Roboto';
            background: #4568DC;
            background: -webkit-linear-gradient(to right, #B06AB3, #4568DC);
            background: linear-gradient(to right, #B06AB3, #4568DC);
            border: none;
            display: block;
            width: 30%;
            margin: 10px auto;
            color: #fff;
            height: 40px;
            cursor: pointer;
        }

        .bg-custom {
            background-color: #000002; /* Color personalizado (en este caso, magenta) */
        }

        .bg-custom-gradient {
             background-image: linear-gradient(to right, #1591C9, #FF26C6); /* Gradiente personalizado */
        }

        .bg-custom-gradient-alt {
            background-color: linear-gradient(to right, #FC45FC,#26C65C); /* Gradiente personalizado */
        }

        .cont {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            margin-top: 100px;
            background-color: white;
            text-align: center;
            align-items: center;
        }

        table {
            border: solid 2px #7e7c7c;
            border-collapse: collapse;
            justify-content: center; 
            align-items: center;
            width: 600px;
            margin: auto;
        }

        th{
            background-color: lightgrey;
            border: solid  1px grey;
            padding: 2px;
            text-align: left;
            font-size: 20px;
        }

        td, h1 {
            border: solid 1px grey;
            font-size: 20px;
            padding: 2px;
            text-align: left;
        }

        h2{
            font-size: 20px;
        }


    </style>

</head>
<body>

    <?php
        $user = "root";
        $pass = "";
        $host = "localhost";
        //conectamos a la base de datos
        $connection = mysqli_connect($host, $user, $pass);

        $datab = "dj_bd";

        //indicacmos seleccionar a la bd
        $db = mysqli_select_db($connection, $datab);

    ?>

    <div class="bg-custom-gradient">
    <nav class="navbar navbar-light navbar-expand-lg bg-light ">
        <div class="container-fluid">
           <a class="navbar-brand" href="#">
           <img src="imgs/DJ.png" alt="" width="50" class="d-inline-block align-text-top">
           </a>
           <a class="navbar-brand" href="#">
            <img src="imgs/djLetrasSinFondo.png" alt="" width="120" class="d-inline-block align-text-top">
            </a>
           <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
           <span class="navbar-toggler-icon"></span>
           </button>
           <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
              <div class="navbar-nav">
                 <a class="nav-link" aria-current="page" href="index.html">Inicio</a>
                 <a class="nav-link" href="contratacion.html">Contratación</a>
                 <a class="nav-link" href="loginAdmin.html"> Admin</a>
                 <a class="nav-link" href="recpdf.php"> Comprobante</a>
              </div>
           </div>
        </div>
     </nav>
  <div class="cont">
    <form method="post" action="capturaDatos.php">
    <?php

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

        $fechaEv = $_POST['fechaE'];
        $lugar = $_POST['recinto'];
        $paquete = $_POST['paquete'];
        
        $separador = "-";
        $separada = explode($separador, $fechaEv);
        $unida = implode($separada);
        $folio = $unida.$curp;

        echo "<h2>Hola! $nombre</h2>";
        echo "<p>Por favor verifica que los datos de tu contratacion/reservacion que ingresaste sean correctos.</p>";
        echo "<br>";

        echo "<table border = 1>";
        echo "<tr>";
        echo "<th>Nombre: </th>";
        echo "<td>$nombre</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Apelllido Paterno: </th>";
        echo "<td>$aPaterno</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Apellido Materno: </th>";
        echo "<td>$aMaterno</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Fecha de nacimiento: </th>";
        echo "<td>$fechaN</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>CURP: </th>";
        echo "<td>$curp</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Correo Electronico: </th>";
        echo "<td>$gmail</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Telefono: </th>";
        echo "<td>$telefono</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Entidad Federativa: </th>";
        echo "<td>$estado</td>";
        echo "<tr>";
        echo "<th>Alcaldia: </th>";
        echo "<td>$alcaldia</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Evento: </th>";
        echo "<td>$evento</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Fecha de evento: </th>";
        echo "<td>$fechaEv</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Lugar del evento: </th>";
        echo "<td>$lugar</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Paquete: </th>";
        echo "<td>$paquete</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Personas: </th>";
        echo "<td>$nPersonas</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Horario: </th>";
        echo "<td>$horario</td>";
        echo "</tr>";
        echo "</tr>";


        echo "</table>";
    ?>
    <div> 
        <br>
        <?php
        $instruction_SQL = "INSERT INTO datosclientes (nombre, aPaterno, aMaterno, fechaN, CURP, gmail, telefono, estado, alcaldia, evento, nPersonas, horario, paquete, lugar, fechaEv, folio)
             VALUES 
                ('$nombre', '$aPaterno', '$aMaterno', '$fechaN', '$curp', '$gmail', '$telefono', '$estado', '$alcaldia','$evento','$nPersonas' ,'$horario' ,'$paquete', '$lugar','$fechaEv', '$folio')";
            $resultado = mysqli_query($connection, $instruction_SQL);

            $consulta = "SELECT idCliente FROM datosclientes WHERE folio = '".$folio."'";
            $resultado2 = mysqli_query($connection,$consulta);
            $filas=mysqli_fetch_assoc($resultado2);            
        ?>

        <div style="padding-left: 0px;"><button type="button" class="enviar" style="text-align: center;"><a href="cpdf.php?idCliente=<?php echo $filas['idCliente']?>">Enviar y generar PDF</a></button></div>
        <div style="padding-left: 0px;"><button type="button"style="text-align: center;" value="Página anterior"><a href="eliminar2.php?idCliente=<?php echo $filas['idCliente']?>">Modificar</a></button></div>
        
    </div>
</form>
  </div>
  <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"></script>
</div>

<a href="eliminar2.php?idCliente=<?php echo $filas['idCliente']?>">Eliminar</a>

</body>
</html>
