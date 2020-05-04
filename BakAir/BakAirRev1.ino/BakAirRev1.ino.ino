#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(14,12); //Rx - Tx

#ifndef STASSID
#define STASSID "Mate9"
#define STAPSK  "ed66abe688e"
#endif

unsigned long myChannelNumber = 892519;
const char * myWriteAPIKey = "DZYQO0UVSRNY49LL";
const char * myReadAPIKey = "E415HV5WX0EU0OS4";
const int FieldNumber1 = 1;  // The field you wish to read
const int FieldNumber2 = 2;
const int FieldNumber3 = 3;

const char* ssid     = STASSID;
const char* password = STAPSK;
WiFiClient clientt;

long statusCode;

long tmb;
long otomatis;
long nlTmb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  s.begin(9600);
  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(clientt);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //  writefield();
  
  readField2();
  
  // Close the connection
  Serial.println();
  Serial.println("closing connection");

//  delay(4000); // execute once every 5 minutes, don't flood remote service
}

void readField2(){
  
  tmb = ThingSpeak.readLongField(myChannelNumber, FieldNumber2, myReadAPIKey);
  otomatis = ThingSpeak.readLongField(myChannelNumber, FieldNumber3, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200){
    StaticJsonBuffer<1000> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    Serial.print("tmb : ");
    Serial.println(tmb);
    Serial.print("otomatis : ");
    Serial.println(otomatis);
    root["data1"] = "csaca";
    root["data2"] = "sdada";
    if(s.available()>0){
      root.printTo(s);
      Serial.println("Connect");
    }delay(2000);
  }else{
      Serial.println("Unable to read channel / No internet connection");
    }
  delay(3000);
}
