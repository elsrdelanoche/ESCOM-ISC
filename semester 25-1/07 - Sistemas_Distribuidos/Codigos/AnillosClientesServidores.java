import java.io.*;
import java.net.*;

public class Nodo extends Thread {
    private int puerto;
    private String siguienteIP;
    private int siguientePuerto;
    private boolean esInicial;
    private static final int REINTENTOS = 3;

    public Nodo(int puerto, String siguienteIP, int siguientePuerto, boolean esInicial) {
        this.puerto = puerto;
        this.siguienteIP = siguienteIP;
        this.siguientePuerto = siguientePuerto;
        this.esInicial = esInicial;
    }

    public void run() {
        try (ServerSocket serverSocket = new ServerSocket(puerto)) {
            System.out.println("Nodo en puerto " + puerto + " esperando conexiones...");

            if (esInicial) {
                enviarToken("Token inicial");
            }

            while (true) {
                try (Socket socket = serverSocket.accept()) {
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    String token = in.readLine();
                    System.out.println("Nodo en puerto " + puerto + " recibió: " + token);
                    
                    // Pausa de 1 segundo antes de enviar el token al siguiente nodo
                    Thread.sleep(1000);
                    
                    enviarToken(token);
                } catch (IOException | InterruptedException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void enviarToken(String token) {
        for (int i = 0; i < REINTENTOS; i++) {
            try (Socket socket = new Socket(siguienteIP, siguientePuerto);
                 PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
                out.println(token);
                System.out.println("Nodo en puerto " + puerto + " envió: " + token);
                break; // Salir del ciclo si la conexión fue exitosa
            } catch (IOException e) {
                System.out.println("Fallo al conectar con el siguiente nodo en puerto " + siguientePuerto + ". Reintento " + (i + 1));
                if (i == REINTENTOS - 1) {
                    e.printStackTrace();
                }
                try {
                    Thread.sleep(1000); // Esperar 1 segundo antes de reintentar
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Nodo nodo0 = new Nodo(5000, "localhost", 5001, true);
        Nodo nodo1 = new Nodo(5001, "localhost", 5002, false);
        Nodo nodo2 = new Nodo(5002, "localhost", 5000, false);

        nodo0.start();
        nodo1.start();
        nodo2.start();
    }
}
