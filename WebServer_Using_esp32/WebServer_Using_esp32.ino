#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include "DHT.h" //library sensor yang telah diimportkan
 
#define DHTPIN 21     //Pin apa yang digunakan
 
#define DHTTYPE DHT11   // DHT 11

#define LED_BUILTIN 4
int freq = 5000;
int ledChannel = 0;
int resolution = 8;

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Mate9";
const char* password = "ed66abe688e";

WebServer server(80);

float humidity_1;
float celcius_1;

uint8_t led1 = 2; 
bool led1status = LOW;

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(led1status));
}

void handle_led1on() {
  led1status = HIGH;
  server.send(200, "text/html", SendHTML(led1status));
  Serial.println("LED dinyalakan.");
}

void handle_led1off() {
  led1status = LOW;
  server.send(200, "text/html", SendHTML(led1status));
  Serial.println("LED dimatikan.");
}

void handle_led1off() {
  led1status = LOW;
//  server.send(200, "text/html", SendHTML(led1status));
  Serial.println("Servo Goyang.");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(led1, OUTPUT);
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("<span id='hasil' >", handle_servo);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  SendHTML(led1status);
  humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  celcius_1 = dht.readTemperature();

  if (isnan(humidity_1) || isnan(celcius_1) ) {
    Serial.println("Pembacaan data dari module sensor gagal!");
    return;
  }
  
  if (led1status) {
    digitalWrite(led1, HIGH);}   // LED1 seharusnya menyala
  else {
    digitalWrite(led1, LOW);}   // LED0 seharusnya menyala

  ledcWrite(ledChannel, 100);

    delay(1000);
    Serial.println();
}

String SendHTML(uint8_t led1stat){
  String teks = "<!DOCTYPE html> <html>\n";
  
  teks += "<head>";
  teks += "<style>";
  teks += ".slidecontainer {  width: 100%;}";
  teks += ".slider { -webkit-appearance: none;   width: 100%;  height: 25px;  height: 15px; border-radius: 5px;  background: #d3d3d3;  outline: none;  opacity: 0.7;  -webkit-transition: .2s;  transition: opacity .2s;}";
  teks += ".slider:hover {  opacity: 1;}";
  teks += ".slider::-webkit-slider-thumb {  -webkit-appearance: none;  appearance: none;  width: 25px;  height: 25px;   height: 20px;  border-radius: 5px;  background: #4CAF50;  cursor: pointer;}";
  teks += ".slider::-moz-range-thumb {  width: 25px;  height: 25px;  background: #4CAF50;  cursor: pointer;}";
  teks += "</style>";
  teks += "</head>";
  teks += "</body>";
  
  teks += "<h1>Custom Range Slider</h1>";
  
  teks += "<div>";
  teks += "<p>Custom range slider:</p>";
  teks += "<input type='range' min='1' max='255' value='50' class='slider' id='myRange'>";
  teks += "</div>";

  if (led1status) {
    teks += "<h2>Status LED: MENYALA</h2><br>";}
  else {
    teks += "<h2>Status LED: MATI</h2><br>";
  }
  
  teks += "<a href=\"/led1on\"\"><button>Nyalakan LED </button></a>";
  teks += "<a href=\"/led1off\"\"><button>Matikan LED </button></a>";

  teks += "<button id='tombol_form'>Tampilkan Nilai</button>";

  teks += "<h2>Hasil: "
  teks += "<span id='hasil' >"
  teks += "</span></h2>";
  
  teks += "</body>";

 teks += "<script>";
  teks += "document.getElementById('tombol_form').addEventListener('click', tampilkan_nilai_form);";
  teks += "function tampilkan_nilai_form(){";
  teks += "var nilai_form=document.getElementById('myRange').value;";
  teks += "document.getElementById('hasil').innerHTML=nilai_form;";
  teks += "}";

  teks += "</script>";
  teks += "</html>";

  Serial.println(teks);
  
return teks;
}
