<!DOCTYPE html>
<html>
<head>
  <title>Inicio de sesión</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css">
  <link rel="stylesheet" href="css/style1.css">
  <link rel="icon" href="imgs/DJ.png" type="image/png">
  
</head>
<body>
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
                 <a class="nav-link" href="indexadmin.php"> Admin</a>
                 <a class="nav-link" href="recpdf.php"> Comprobante</a>
              </div>
           </div>
        </div>
     </nav>
     <br>
     <div class="container " >
      <br><br><br>
        <div class="row " style="border-radius:12px; background-color: #ffffff;">
              <p align="center" style="color: black ">Si deseas volver a descargar tu Comprobante en PDF introduce la fecha del evento en el formato yyyy/mm/dd y tu curp. </p> 
        </div>

  <div class="cont">
    <h2>Recuperacion del PDF</h2>
    <form method="post" action="genpdf.php">
      <div class="mb-3">
        <label for="username" class="form-label">Fecha del evento:</label>
        <input type="text" class="form-control" id="fechaN" name="fechaN" required>
      </div>
      <div class="mb-3">
        <label for="text" class="form-label">Curp:</label>
        <input type="text" class="form-control" id="curp" name="curp" required>
      </div>
      <button type="submit" class="btn btn-primary">Recuperar PDF</button>
    </form>
  </div>
  <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
  <br><br><br><br><br><br><br>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"></script>
</div>
</body>
</html>