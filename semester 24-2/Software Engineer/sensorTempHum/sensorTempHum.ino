#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <time.h>
#include "DHT.h"

#define DHTPIN 15     // Pin al que está conectado el DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT (DHT11 en este caso)

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastUpdate = 0; 
const long updateInterval = 5000; 
const char* ssid = "INFINITUM0C77";   
const char* password = "Nm4Pj8Zv3j";

WebServer server(80);   
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -21600; 
const int daylightOffset_sec = 3600; 


// Manejador de la página principal
void handleRoot() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    server.send(500, "text/plain", "Failed to read from DHT sensor!");
    return;
  }

  // Obtener fecha y hora actualizadas
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  char timeStringBuff[50]; 
  strftime(timeStringBuff, sizeof(timeStringBuff), "%Y-%m-%d %H:%M:%S", &timeinfo);
  String dateTime = timeStringBuff;

  String html = "<!DOCTYPE html><html><head><title>Datos del Invernadero</title>";
  html += "<script>";
  html += "function refreshData() {";
  html += "  var xhttp = new XMLHttpRequest();";
  html += "  xhttp.onreadystatechange = function() {";
  html += "    if (this.readyState == 4 && this.status == 200) {";
  html += "      document.getElementById('data').innerHTML = this.responseText;";
  html += "    }";
  html += "  };";
  html += "  xhttp.open('GET', '/', true);";
  html += "  xhttp.send();";
  html += "}";
  html += "setInterval(refreshData, 5000);"; 
  html += "</script>";

  html += "<style>";
  html += "body { font-family: sans-serif; background-image: url('https://img.freepik.com/vector-premium/gran-invernadero-hileras-plantulas-tomates-ilustracion-dibujos-animados_273525-136.jpg?w=900'); background-size: cover; background-repeat: no-repeat; display: flex; justify-content: center; align-items: center; min-height: 100vh; }"; // Estilos de fondo y centrado vertical
  html += "h1 { text-align: center; color: #333; margin-bottom: 20px; }";
  html += ".container { background-color: rgba(255, 255, 255, 0.8); padding: 20px; border-radius: 5px; box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1); backdrop-filter: blur(5px); }"; // Estilos del contenedor con blur
  html += ".data { margin-bottom: 10px; }";
  html += ".data label { display: block; font-weight: bold; color: #333; }"; // Color de texto más oscuro
  html += ".data span { font-size: 1.2em; color: #333; }"; // Color de texto más oscuro
  html += "</style></head><body onload='refreshData()'>";

  // Contenedor principal con el título y los datos
  html += "<div class='container'>"; // Inicia el contenedor principal
  //html += "<h1>Datos del Invernadero</h1>"; // Título (una sola vez)
  html += "<div id='data'>";
   html += "<div class='data'><label>Humedad:</label><span>";
    html += h;
    html += "%</span></div>";
    html += "<div class='data'><label>Temperatura:</label><span>";
    html += t;
    html += "°C</span></div>";
    html += "<div class='data'><label>Última actualización:</label><span>";
    html += dateTime;
    html += "</span></div>";
  html += "</div>"; // Cierra el contenedor de datos
  html += "</div>"; // Cierra el contenedor principal

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Conexión WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  // Mostrar dirección IP en el monitor serial
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Iniciar servidor web
  server.on("/", handleRoot); 
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient(); 
}
