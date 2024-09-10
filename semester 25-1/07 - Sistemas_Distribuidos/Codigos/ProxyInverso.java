import java.io.*;
import java.net.*;

class Proxy {
  static String host_remoto;
  static int puerto_remoto;
  static int puerto_local;

  static class Worker_1 extends Thread {
    Socket cliente_1, cliente_2;

    Worker_1(Socket cliente_1) {
      this.cliente_1 = cliente_1;
    }

    public void run() {
      try {
        // Se conecta al servidor backend (host remoto)
        cliente_2 = new Socket(host_remoto, puerto_remoto);
        System.out.println("Conectado al servidor backend: " + host_remoto + ":" + puerto_remoto);

        // Inicia el hilo que dirige el tráfico del servidor backend al cliente
        new Worker_2(cliente_1, cliente_2).start();

        // Transfiere datos del cliente al servidor backend
        InputStream entrada_1 = cliente_1.getInputStream();
        OutputStream salida_2 = cliente_2.getOutputStream();
        byte[] buffer = new byte[1024];
        int n;
        while ((n = entrada_1.read(buffer)) != -1) {
          salida_2.write(buffer, 0, n);
          salida_2.flush();
        }

      } catch (IOException e) {
        e.printStackTrace();
      } finally {
        try {
          if (cliente_1 != null) cliente_1.close();
          if (cliente_2 != null) cliente_2.close();
        } catch (IOException e2) {
          e2.printStackTrace();
        }
      }
    }
  }

  static class Worker_2 extends Thread {
    Socket cliente_1, cliente_2;

    Worker_2(Socket cliente_1, Socket cliente_2) {
      this.cliente_1 = cliente_1;
      this.cliente_2 = cliente_2;
    }

    public void run() {
      try {
        // Transfiere datos del servidor backend al cliente
        InputStream entrada_2 = cliente_2.getInputStream();
        OutputStream salida_1 = cliente_1.getOutputStream();
        byte[] buffer = new byte[4096];
        int n;
        while ((n = entrada_2.read(buffer)) != -1) {
          salida_1.write(buffer, 0, n);
          salida_1.flush();
        }

      } catch (IOException e) {
        e.printStackTrace();
      } finally {
        try {
          if (cliente_1 != null) cliente_1.close();
          if (cliente_2 != null) cliente_2.close();
        } catch (IOException e2) {
          e2.printStackTrace();
        }
      }
    }
  }

  public static void main(String[] args) throws Exception {
    if (args.length != 3) {
      System.err.println("Uso:\nProxy <host-remoto> <puerto-remoto> <puerto-local>");
      System.exit(1);
    }

    host_remoto = args[0]; // Servidor backend
    puerto_remoto = Integer.parseInt(args[1]); // Puerto del servidor backend
    puerto_local = Integer.parseInt(args[2]); // Puerto en el que escucha el proxy

    System.out.println("Iniciando proxy inverso...");
    System.out.println("Host backend: " + host_remoto + ", Puerto backend: " + puerto_remoto + ", Puerto proxy: " + puerto_local);

    // El proxy actúa como servidor para recibir las conexiones de los clientes
    ServerSocket ss = new ServerSocket(puerto_local);
    for (;;) {
      // Espera una conexión del cliente
      Socket cliente_1 = ss.accept();
      System.out.println("Conexión aceptada de: " + cliente_1.getInetAddress().getHostAddress());

      // Inicia el thread que dirige el tráfico del cliente al servidor backend
      new Worker_1(cliente_1).start();
    }
  }
}
