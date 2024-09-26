/*
  ServidorHTTP.java
  Carlos Pineda G. 2024
*/

import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class ServidorHTTP
{
  static class Worker extends Thread
  {
    Socket conexion;
    Worker(Socket conexion)
    {
      this.conexion = conexion;
    }
    public void run()
    {
      try
      {
        BufferedReader entrada = new BufferedReader(new InputStreamReader(conexion.getInputStream()));
        PrintWriter salida = new PrintWriter(conexion.getOutputStream());

	String req= entrada.readLine();
        System.out.println(req);

        for (;;)
        {
  	  String encabezado= entrada.readLine();
          System.out.println(encabezado);
          if (encabezado.equals("")) break;
        }

        if (req.startsWith("GET /hola "))
        {
          String respuesta = "<html><button onclick='alert(\"OK\")'>Aceptar</button></html>";
          salida.println("HTTP/1.1 200 OK");
          salida.println("Content-type: text/html; charset=utf-8");
          salida.println("Content-length: "+respuesta.length());
	  salida.println("Connection: close");
          salida.println();
          salida.println(respuesta);
          salida.flush();
        }
        else
        {
          salida.println("HTTP/1.1 404 File Not Found");
          salida.flush();
        }
      }
      catch (Exception e)
      {
        System.err.println(e.getMessage());
      }
      finally
      {
        try
        {
          conexion.close();
        }
        catch (Exception e)
        {
          System.err.println(e.getMessage());
        }
      }
    }
  }

  public static void main(String[] args) throws Exception
  {
    ServerSocket servidor = new ServerSocket(80);

    for(;;)
    {
      Socket conexion = servidor.accept();
      new Worker(conexion).start();
    }
  }
}