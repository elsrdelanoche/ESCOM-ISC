import java.io.*;
import java.net.*;
import javax.net.ssl.*;

public class AdministradorTraficoSSL {
    static String ipServidor1, ipServidor2;
    static int puertoServidor1, puertoServidor2;
    static final int PUERTO_SSL = 8443;

    static class ClienteProxy extends Thread {
        SSLSocket clienteNavegador;
        Socket clienteServidor;
        String ipServidor;
        int puertoServidor;

        ClienteProxy(SSLSocket clienteNavegador, String ipServidor, int puertoServidor) {
            this.clienteNavegador = clienteNavegador;
            this.ipServidor = ipServidor;
            this.puertoServidor = puertoServidor;
        }

        public void run() {
            try {
                // Conectar al servidor (Servidor-1 o Servidor-2)
                clienteServidor = new Socket(ipServidor, puertoServidor);

                // Si es Servidor-1, reenvía la respuesta al navegador
                if (ipServidor.equals(ipServidor1)) {
                    new RespuestaServidorAlNavegador(clienteNavegador, clienteServidor).start();
                }

                // Reenviar petición del navegador al servidor
                InputStream entradaNavegador = clienteNavegador.getInputStream();
                OutputStream salidaServidor = clienteServidor.getOutputStream();
                byte[] buffer = new byte[1024];
                int n;
                while ((n = entradaNavegador.read(buffer)) != -1) {
                    salidaServidor.write(buffer, 0, n);
                    salidaServidor.flush();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (clienteNavegador != null) clienteNavegador.close();
                    if (clienteServidor != null) clienteServidor.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class RespuestaServidorAlNavegador extends Thread {
        SSLSocket clienteNavegador;
        Socket clienteServidor;

        RespuestaServidorAlNavegador(SSLSocket clienteNavegador, Socket clienteServidor) {
            this.clienteNavegador = clienteNavegador;
            this.clienteServidor = clienteServidor;
        }

        public void run() {
            try {
                // Recibe la respuesta del servidor y la reenvía al navegador
                InputStream entradaServidor = clienteServidor.getInputStream();
                OutputStream salidaNavegador = clienteNavegador.getOutputStream();
                byte[] buffer = new byte[4096];
                int n;
                while ((n = entradaServidor.read(buffer)) != -1) {
                    salidaNavegador.write(buffer, 0, n);
                    salidaNavegador.flush();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (clienteNavegador != null) clienteNavegador.close();
                    if (clienteServidor != null) clienteServidor.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 4) {
            System.err.println("Uso:\nAdministradorTraficoSSL <ip-servidor1> <puerto-servidor1> <ip-servidor2> <puerto-servidor2>");
            System.exit(1);
        }

        ipServidor1 = args[0];
        puertoServidor1 = Integer.parseInt(args[1]);
        ipServidor2 = args[2];
        puertoServidor2 = Integer.parseInt(args[3]);

        // Configurar keystore para SSL
        System.setProperty("javax.net.ssl.keyStore", "keystore_servidor.jks");
        System.setProperty("javax.net.ssl.keyStorePassword", "password_keystore"); // Cambia la contraseña por la real

        // Crear el socket SSL del servidor en el puerto 8443
        SSLServerSocketFactory factory = (SSLServerSocketFactory) SSLServerSocketFactory.getDefault();
        SSLServerSocket proxyServer = (SSLServerSocket) factory.createServerSocket(PUERTO_SSL);

        System.out.println("Proxy inverso SSL iniciado en el puerto " + PUERTO_SSL);

        for (;;) {
            // Acepta la conexión del navegador
            SSLSocket clienteNavegador = (SSLSocket) proxyServer.accept();

            // Crea un ClienteProxy para el Servidor-1
            new ClienteProxy(clienteNavegador, ipServidor1, puertoServidor1).start();

            // Crea un ClienteProxy para el Servidor-2
            new ClienteProxy(clienteNavegador, ipServidor2, puertoServidor2).start();
        }
    }
}
