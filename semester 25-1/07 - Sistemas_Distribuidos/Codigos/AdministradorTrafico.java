import java.io.*;
import java.net.*;

class AdministradorTrafico {
    static String ipServidor1, ipServidor2;
    static int puertoServidor1, puertoServidor2, puertoProxy;

    static class ClienteProxy extends Thread {
        Socket clienteNavegador, clienteServidor;
        String ipServidor;
        int puertoServidor;

        ClienteProxy(Socket clienteNavegador, String ipServidor, int puertoServidor) {
            this.clienteNavegador = clienteNavegador;
            this.ipServidor = ipServidor;
            this.puertoServidor = puertoServidor;
        }

        public void run() {
            try {
                // Se conecta al servidor (Servidor-1 o Servidor-2)
                clienteServidor = new Socket(ipServidor, puertoServidor);

                // Thread que reenvía la respuesta del servidor al navegador solo si es Servidor-1
                if (ipServidor.equals(ipServidor1)) {
                    new RespuestaServidorAlNavegador(clienteNavegador, clienteServidor).start();
                }

                // Reenviar petición desde el navegador al servidor
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
        Socket clienteNavegador, clienteServidor;

        RespuestaServidorAlNavegador(Socket clienteNavegador, Socket clienteServidor) {
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
        if (args.length != 5) {
            System.err.println("Uso:\nAdministradorTrafico <puerto-proxy> <ip-servidor1> <puerto-servidor1> <ip-servidor2> <puerto-servidor2>");
            System.exit(1);
        }

        puertoProxy = Integer.parseInt(args[0]);
        ipServidor1 = args[1];
        puertoServidor1 = Integer.parseInt(args[2]);
        ipServidor2 = args[3];
        puertoServidor2 = Integer.parseInt(args[4]);

        System.out.println("Proxy inverso iniciado en el puerto " + puertoProxy);
        ServerSocket proxyServer = new ServerSocket(puertoProxy);

        for (;;) {
            // Acepta la conexión del navegador
            Socket clienteNavegador = proxyServer.accept();

            // Crea un ClienteProxy para el Servidor-1
            new ClienteProxy(clienteNavegador, ipServidor1, puertoServidor1).start();

            // Crea un ClienteProxy para el Servidor-2
            new ClienteProxy(clienteNavegador, ipServidor2, puertoServidor2).start();
        }
    }
}
