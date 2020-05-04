#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial sa(14,12); //Rx - Tx
 
void setup() {
sa.begin(9600);
Serial.begin(9600);
Serial.println("Masukjii");
}
 
void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();
  root["data1"] = "Dicoba Aja Dulu";
  root["data2"] = "Jangan Digangu";
if(sa.available()>0)
{
  Serial.println("Connect Node");
// root.printTo(s);
}
delay(1000);
}
