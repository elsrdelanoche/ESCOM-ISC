<?php

        $user = "root";
        $pass = "";
        $host = "localhost";
        //conectamos a la base de datos
        $connection = mysqli_connect($host, $user, $pass);

        //hacemos llamado al input del formulario

        $datab = "dj_bd";

        //indicacmos seleccionar a la bd
        $db = mysqli_select_db($connection, $datab);

        include 'conexion2.php';
        $idCliente = $_GET['idCliente'];
        $sql = "SELECT * FROM datosclientes WHERE idCliente = '".$idCliente."'";
        $resultado = mysqli_query($connection,$sql);
        $fila = mysqli_fetch_assoc($resultado);

    header('Content-Type: text/html; charset=UTF-8');

    require('tfpdf/tfpdf.php');

    class PDF extends tFPDF {
        function Header() {
            // Insertar Marca de agua con transparencia
            $this->Image('imgs/DJ3agua.png', 0, 0, $this->GetPageWidth(), $this->GetPageHeight());
        }
    }

    
    $pdf = new PDF();// Crea  PDF

    $pdf->AddPage();// Agrega una nueva página
    $pdf->AddFont('DejaVu','','DejaVuSans.ttf',true);
    $pdf->AddFont('DejaVuBold','','DejaVuSans-Bold.ttf',true);
    $nombre = $fila['nombre'];
    $apellidoPaterno = $fila['aPaterno'];
    $apellidoMaterno = $fila['aMaterno'];
    $fechaNacimiento = $fila['fechaN'];
    $curp = $fila['CURP'];
    $email = $fila['gmail'];
    $telefono = $fila['telefono'];
    $entidadFederativa = $fila['estado'];
    $alcaldia = $fila['alcaldia'];
    $evento = $fila['evento'];
    $personas = $fila['nPersonas'];
    $horario = $fila['horario'];
    $folio = $fila['folio'];
    $fechaEv = $fila['fechaEv'];
    $recinto = $fila['lugar'];
    $paquete = $fila['paquete'];
    $nombreArchivo = $folio . '.pdf';


    $pdf->SetFont('DejaVu', '', 12);

    $pdf->SetFont('DejaVuBold', '', 16);
    $pdf->Cell(0, 10, 'Gracias por contratar nuestros servicios de DJ', 0, 1, 'C');
    $pdf->Ln(3);

    $pdf->SetFont('DejaVu', '', 12);
    $pdf->Cell(0, 10, 'Estimado(a) ' . $nombre . ' ' . $apellidoPaterno . ' ' . $apellidoMaterno . ',', 0, 1);
    $pdf->Cell(0, 10, '¡Muchas gracias por confiar en nuestros servicios para su fiesta!', 0, 1);
    $pdf->Ln(5);

    $pdf->SetFont('DejaVuBold', '', 12);
    $pdf->Cell(0, 10, 'Resumen de la información proporcionada:', 0, 1);

    $pdf->SetFont('DejaVu', '', 12);
    $pdf->Cell(50, 10, 'Nombre:', 0, 0);
    $pdf->Cell(0, 10, $nombre, 0, 1);

    $pdf->Cell(50, 10, 'Apellido Paterno:', 0, 0);
    $pdf->Cell(0, 10, $apellidoPaterno, 0, 1);

    $pdf->Cell(50, 10, 'Apellido Materno:', 0, 0);
    $pdf->Cell(0, 10, $apellidoMaterno, 0, 1);

    $pdf->Cell(50, 10, 'Fecha de Nacimiento:', 0, 0);
    $pdf->Cell(0, 10, $fechaNacimiento, 0, 1);

    $pdf->Cell(50, 10, 'CURP:', 0, 0);
    $pdf->Cell(0, 10, $curp, 0, 1);

    $pdf->Cell(50, 10, 'Correo Electrónico:', 0, 0);
    $pdf->Cell(0, 10, $email, 0, 1);

    $pdf->Cell(50, 10, 'Teléfono:', 0, 0);
    $pdf->Cell(0, 10, $telefono, 0, 1);

    $pdf->Cell(50, 10, 'Entidad Federativa:', 0, 0);
    $pdf->Cell(0, 10, $entidadFederativa, 0, 1);

    $pdf->Cell(50, 10, 'Alcaldía:', 0, 0);
    $pdf->Cell(0, 10, $alcaldia, 0, 1);

    $pdf->Cell(50, 10, 'Evento:', 0, 0);
    $pdf->Cell(0, 10, $evento, 0, 1);

    $pdf->Cell(50, 10, 'Fecha del evento:', 0, 0);
    $pdf->Cell(0, 10, $fechaEv, 0, 1);

    $pdf->Cell(50, 10, 'Salón:', 0, 0);
    $pdf->Cell(0, 10, $recinto, 0, 1);

    $pdf->Cell(50, 10, 'Paquete:', 0, 0);
    $pdf->Cell(0, 10, $paquete, 0, 1);

    $pdf->Cell(50, 10, 'Personas:', 0, 0);
    $pdf->Cell(0, 10, $personas, 0, 1);

    $pdf->Cell(50, 10, 'Horario:', 0, 0);
    $pdf->Cell(0, 10, $horario, 0, 1);

    $pdf->Cell(50, 10, 'Folio:', 0, 0);
    $pdf->Cell(0, 10, $folio, 0, 1);
    $pdf->Ln(5);

    $pdf->SetFont('DejaVu', '', 12);
    $pdf->Cell(0, 10, '¡Esperamos que disfrute al máximo su fiesta con nuestra música!', 0, 1);

    $pdf->Cell(0, 10, 'Si tiene alguna pregunta adicional o requiere más información,', 0, 1);
    $pdf->Cell(0, 10, 'no dude en contactarnos a dj_pinata@gmail.com.', 0, 1);
    
    $pdf->Cell(0, 10, 'Atentamente', 0, 1);
    

    $yPos = $pdf->GetY(); 
    $pdf->Image('imgs/DJletras.png', 80, $yPos, 50);

    $pdf->SetTitle($folio);
    $pdf->Output();
?>

