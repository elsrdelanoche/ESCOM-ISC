<!DOCTYPE html>
<html>
<head>
  <title>Inicio de sesión</title>
  <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="css/sphp.css">
    <link rel="stylesheet" href="css/style.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.min.js"></script>

  <link rel="icon" href="imgs/DJ.png" type="image/png">
  
</head>



<body>
  <?php
    include 'conexion2.php';
    $consulta = "SELECT * FROM datosclientes";
    $resultado = mysqli_query($connection,$consulta);
  ?>
    <div class="bg-custom-gradient">
    <nav class="navbar navbar-light navbar-expand-lg bg-light ">
        <div class="container-fluid">
           <a class="navbar-brand" href="index.html">
           <img src="imgs/DJ.png" alt="" width="50" class="d-inline-block align-text-top">
           </a>
           <a class="navbar-brand" href="index.html">
            <img src="imgs/djLetrasSinFondo.png" alt="" width="120" class="d-inline-block align-text-top">
            </a>
           <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
           <span class="navbar-toggler-icon"></span>
           </button>
           <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
              <div class="navbar-nav">
                 <a class="nav-link" aria-current="page" href="index.html">Inicio</a>
                 <a class="nav-link" href="contratacion.html">Contratación</a>
                 <a class="nav-link" href="indexadmin.php"> Admin</a>
                 <a class="nav-link" href="recpdf.php"> Comprobante</a>
              </div>
           </div>
        </div>
     </nav>
  <div class="cont row">
    <div>
      <p style="font-size: 30px; text-align: center;">USUARIOS REGISTRADOS</p>
      <table>
        <thead>
         <tr>
            <th>ID</th>
            <th>NOMBRE</th>
            <th>APELLIDO PATERNO</th>
            <th>APELLIDO MATERNO</th>
            <th>FECHA DE NACIMINETO</th>
            <th>CURP</th>
            <th>CORREO ELECTRONICO</th>
            <th>TELEFONO</th>
            <th>ENTIDAD FEDERATIVA</th>
            <th>ALCALDIA</th>
            <th>EVENTO</th>
            <th>No. PERSONAS</th>
            <th>HORARIO</th>
            <th>PAQUETE</th>
            <th>RECINTO</th>
            <th>FECHA DEL EVENTO</th>
            <th>FOLIO</th>
            <th>ACCIONES</th>
          </tr>
        </thead>
        <tbody>
          <?php while ($filas=mysqli_fetch_assoc($resultado)){

            ?>
          <tr>
            <td><?php echo $filas['idCliente']?></td>
            <td><?php echo $filas['nombre']?></td>
            <td><?php echo $filas['aPaterno']?></td>
            <td><?php echo $filas['aMaterno']?></td>
            <td><?php echo $filas['fechaN']?></td>
            <td><?php echo $filas['CURP']?></td>
            <td><?php echo $filas['gmail']?></td>
            <td><?php echo $filas['telefono']?></td>
            <td><?php echo $filas['estado']?></td>
            <td><?php echo $filas['alcaldia']?></td>
            <td><?php echo $filas['evento']?></td>
            <td><?php echo $filas['nPersonas']?></td>
            <td><?php echo $filas['horario']?></td>
            <td><?php echo $filas['paquete']?></td>
            <td><?php echo $filas['lugar']?></td>
            <td><?php echo $filas['fechaEv']?></td>
            <td><?php echo $filas['folio']?></td>
            <td>
              <a href="modificar.php?idCliente=<?php echo $filas['idCliente']?>">Editar</a>
              <a href="eliminar.php?idCliente=<?php echo $filas['idCliente']?>">Eliminar</a>
            </td>
          </tr>
          <?php }?>
      </table>
    </div>

    <br>

    <div class="container">
      <form method="post" action="agregarusr.php" style="background-color:white; border-style: solid;  border:8px; border-radius:10px; border-color:white !important; padding:10px;" id="registro">
            <div class="title">
            <p style="font-size: 30px ; text-align: center;">AGREGAR USUARIOS</p>
            </div>
            <!--Contacto-->
            <fieldset>
                <legend>Contacto</legend>
                <div class="row form-group">
                    <div class="col-md-4 ml-auto" id="gapellidoP">
                        <label for="apellidoP">Primer Apellido</label>
                        <input type="text" name="apellidoP" id="apellidoP" class="form-control" placeholder="Primer Apellido" >
                    </div>
                    <div class="col-md-4 ml-auto" id="gapellidoM">
                        <label for="apellidoM">Segundo Apellido</label>
                        <input type="text" name="apellidoM" id="apellidoM" class="form-control" placeholder="Segundo Apellido" >
                    </div>
                    <div class="col-md-4 ml-auto" id="gnombre">
                        <label for="nombre">Nombre (s)</label>
                        <input type="text" name="nombre" id="nombre" class="form-control" placeholder="Nombres" >
                    </div>
                </div>
                <br>
                <div class="row form-group" id="gfecha">
                    <div class="col-md-6 ml-auto">
                        <label for="fechaN">Fecha de Nacimiento</label>
                        <input type="date" id="fechaN" name="fechaN" class="form-control pickDate" name="fnac" max="2005-05-28" min="1945-05-28" required >
                    </div>
                    <div class="col-md-6 ml-auto" id="gcurp">
                        <label for="curp">CURP</label>
                        <input type="text" class="form-control" name="curp" id="curp" required pattern="^([A-Z]{4}[0-9]{6}[A-Z]{6}[A-Z0-9]{2})$">
                    </div>
                </div>
                <br>
                <div class="row form-group" id="gtelefono">
                    <div class="col-md-6 ml-auto">
                        <label for="telefono">Tel. Celular</label>
                        <input type="tel" class="form-control" id="telefono" name="telefono" required pattern="^[0-9]{10}$" maxlength="10">
                    </div>
                    <div class="col-md-6 ml-auto" id="gmail">
                        <label for="mail">Correo Electronico</label>
                        <input type="email" name="mail" id="mail" class="form-control" required pattern="^([a-záéíóúñüA-ZÁÉÍÓÚÑÜ0-9.\-_/\\]+@\w+(\.\w+)+)$">
                    </div>
                </div>
                <br>
                <div class="row form-group">
                    <div class="col-md-6 ml-auto">
                        <label for="entidadF">Entidad Federativa</label>
                        <select class="form-select" aria-label="Default select example" id="entidadF" name="entidadF" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Aguascalientes">Aguascalientes</option>
                            <option value="Baja California Norte">Baja California</option>
                            <option value="Baja California Sur">Baja California Sur</option>
                            <option value="Campeche">Campeche</option>
                            <option value="Chiapas">Chiapas</option>
                            <option value="Chihuahua">Chihuahua</option>
                            <option value="Ciudad de Mexico">Ciudad de México</option>
                            <option value="Coahuila de Zaragoza">Coahuila de Zaragoza</option>
                            <option value="Colima">Colima</option>
                            <option value="Durango">Durango</option>
                            <option value="Guanajuato">Guanajuato</option>
                            <option value="Guerrero">Guerrero</option>
                            <option value="Hidalgo">Hidalgo</option>
                            <option value="Jalisco">Jalisco</option>
                            <option value="Estado de Mexico">Estado de México</option>
                            <option value="Michoacan">Michoacán</option>
                            <option value="Morelos">Morelos</option>
                            <option value="Nayarit">Nayarit</option>
                            <option value="Nuevo Leon">Nuevo León</option>
                            <option value="Oaxaca">Oaxaca</option>
                            <option value="Puebla">Puebla</option>
                            <option value="Queretaro">Querétaro</option>
                            <option value="Quintana Roo">Quintana Roo</option>
                            <option value="San Luis Potosi">San Luis Potosí</option>
                            <option value="Sinaloa">Sinaloa</option>
                            <option value="Sonora">Sonora</option>
                            <option value="Tabasco">Tabasco</option>
                            <option value="Tamaulipas">Tamaulipas</option>
                            <option value="Tlaxcala">Tlaxcala</option>
                            <option value="Veracruz">Veracruz</option>
                            <option value="Yucatan">Yucatán</option>
                            <option value="Zacatecas">Zacatecas</option>
                        </select>
                    </div>
                    <div class="col-md-6 ml-auto">
                        <label for="alcaldia">Alcaldia</label>
                        <select class="form-select" aria-label="Default select example" id="alcaldia" name="alcaldia" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Alvaro Obregon">Álvaro Obregón</option>
                            <option value="Azcapotzalco">Azcapotzalco</option>
                            <option value="Benito Juarez">Benito Juárez</option>
                            <option value="Coyoacan">Coyoacán</option>
                            <option value="Cuajimalpa de Morelos">Cuajimalpa de Morelos</option>
                            <option value="Cuauhtemoc">Cuauhtémoc</option>
                            <option value="Gustavo A. Madero">Gustavo A. Madero</option>
                            <option value="Iztacalco">Iztacalco</option>
                            <option value="Iztapalapa">Iztapalapa</option>
                            <option value="Magdalena Contreras">Magdalena Contreras</option>
                            <option value="Miguel Hidalgo">Miguel Hidalgo</option>
                            <option value="Milpa Alta">Milpa Alta</option>
                            <option value="Tlahuac">Tláhuac</option>
                            <option value="Tlalpan">Tlalpan</option>
                            <option value="Venustiano Carranza">Venustiano Carranza</option>
                            <option value="Xochimilco">Xochimilco</option>
                        </select>
                    </div>
                </div>
            </fieldset>
            <hr>
 
            <!--Evento-->
            <fieldset>
                <legend>Evento</legend>
                <div class="row form-group">
                    <div class="col-md-5 ml-auto" id="gevento">
                        <label for="evento">Tipo de evento</label>
                        <select class="form-select" aria-label="Default select example" id="evento" name="evento" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Bautizo">Bautizo</option>
                            <option value="Primera Comunion">Primera Comunion</option>
                            <option value="XV Años">XV Años</option>
                            <option value="Cumpleaños">Cumpleaños</option>
                            <option value="Boda">Boda</option>
                            <option value="Otros">Otros</option>
                        </select>
                    </div>
                    <div class="col-md-5 ml-auto" id="gopcion">
                        <label for="opcion">Otro</label>
                        <div class="formInput" id="opcion">
                        <input class="form-control" type="text" id="opcion" name="opcion">
                        </div>
                    </div>
                    <div class="col-md-2 ml-auto" id="gpersonas">
                        <label for="personas">Número de personas</label>
                        <input type="number" name="personas" class="form-control" id="personas">
                    </div>
                </div>
                <br>
                <div class="row form-group">
                    <div class="col-md-3 ml-auto" id="grecinto">
                        <label for="recinto">Salon o jardin</label>
                        <select class="form-select" aria-label="Default select example" id="recinto" name="recinto" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Jardin mayita">Jardin Mayita</option>
                            <option value="IMITI">Salon IMITI</option>
                            <option value="Luc34">Luc34</option>
                        </select>
                    </div>
                    <div class="col-md-3 ml-auto" id="ghorarios">
                        <label for="horario">Horarios</label>
                        <select class="form-select" aria-label="Default select example" id="horario" name="horario" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Viernes de 12:00pm - 2:00am">Viernes de 12:00pm - 2:00am</option>
                            <option value="Sabado de 2:00pm - 2:00am">Sabados de 2:00pm - 2:00am</option>
                            <option value="Domingo de 9:00am - 2:pm">Domingos de 9:00am - 2:pm</option>
                        </select>
                    </div>
                    <div class="col-md-3 ml-auto">
                        <label for="fnac">Fecha del evento</label>
                        <input type="date" id="fechaE" class="form-control pickDate" name="fechaE" min="2023-01-01" max="2023-31-12" required >
                    </div>
                    <div class="col-md-3 ml-auto" id="ghorarios">
                        <label for="paquete">Paquete</label>
                        <select class="form-select" aria-label="Default select example" id="paquete" name="paquete" required>
                            <option value="" disabled selected>Selecciona una opción</option>
                            <option value="Paquete basico">Paquete Básico</option>
                            <option value="Paquete premium">Paquete Premium</option>
                        </select>
                    </div>
                </div>
                <br>
            <div>
                    <button type="submit" class="enviar" style="text-align: center;">AGREGAR</button>
            </div>      
        </form>

    </div>

      <p><a href = "cierre.php">cierra sesion</a>
  </div>
  <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"></script>
</div>
</body>
</html>