#include <SoftwareSerial.h>
SoftwareSerial s(5,6); //Rx - Tx
#include <ArduinoJson.h>
 
void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  s.begin(9600);
  while (!Serial) continue;
 
}
 
void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;
 
  Serial.println("JSON received and parsed");
//  root.prettyPrintTo(Serial);
  Serial.print("Data 1 : ");
  String data1=root["data1"];
  Serial.print(data1);
  Serial.println();
  Serial.print("Data 2 : ");
  String data2=root["data2"];
  Serial.print(data2);
  Serial.println();
  Serial.println("---------------------xxxxx--------------------");
 delay(5000);
}
