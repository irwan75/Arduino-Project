#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Note 5";
const char* pass = "daud123456";
const char* mqtt_server = "farmer.cloudmqtt.com";
#define mqtt_port 14751
#define MQTT_USER "wgrsyppg"
#define MQTT_PASSWORD " 7hbWvLFAOWqR"

//client.publish("/fga/circuit/", "Hello World");
#define MQTT_SERIAL_PUBLISH_CH "/icircuit/presence/ESP32/"
#define MQTT_SERIAL_RECEIVER_CH "/icircuit/presence/ESP32/"

WiFiClient wifiClient;

PubSubClient client(wifiClient);

void setup_wifi(){
  Serial.println();
  Serial.println("Connecting to...");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }

  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP Address");
  Serial.println(WiFi.localIP());
  
}

void reconnect(){
  while(!client.connected()){
    Serial.print("Attempting MQTT Connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if(client.connect(clientId.c_str(), MQTT_USER, MQTT_PASSWORD)){
      Serial.println("Connected");
      client.publish("/icircuit/presence/ESP32/", "hello world");
      client.subscribe(MQTT_SERIAL_RECEIVER_CH);
    }else{
      Serial.print("Failed, rc-");
      Serial.print(client.state());
      Serial.println();
      Serial.println("try again in 5 minutes");
      delay(5000);
    }
}  
}

void callback(char* topic, byte *payload, unsigned int length){
  Serial.println("------new message from broker------");
  Serial.print("Channel: ");
  Serial.println(topic);
  Serial.print("data");
  Serial.write(payload, length);
  Serial.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(500);
  setup_wifi();
  client.setServer(mqtt_server, 14751);
  client.setCallback(callback);
  reconnect(); 
}

void publishSerialData(char *serialData){
  if(!client.connected()){
    reconnect();
  }
  client.publish(MQTT_SERIAL_PUBLISH_CH, serialData);
}

void loop() {
  // put your main code here, to run repeatedly:
  client.loop();
  if(Serial.available() > 0){
    char mun[501];
    memset(mun, 0, 501);
    Serial.readBytesUntil('\n', mun, 500);
    publishSerialData(mun);
  }
}
