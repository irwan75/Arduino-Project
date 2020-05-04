#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#ifndef STASSID
#define STASSID "OPPO A3s"
#define STAPSK  "surachmo"
#endif

unsigned long myChannelNumber = 892519;
const char * myWriteAPIKey = "DZYQO0UVSRNY49LL";
const char * myReadAPIKey = "E415HV5WX0EU0OS4";
const int FieldNumber1 = 1;  // The field you wish to read
const int FieldNumber2 = 2;
const int FieldNumber3 = 3;
//
const char* ssid     = STASSID;
const char* password = STAPSK;
WiFiClient clientt;

RF24 radio(5, 4); // CE, CSN
const byte address[6] = "00001";

int relay = 0;
int buzzer= 2;

long statusCode;
long tmb;
long otomatis;
long nlTmb;
int tng;

void setup() {
  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(clientt);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (radio.available()) {
//    char text[5] = "";
//    radio.read(&text, sizeof(text));
//    Serial.println(text);
//    delay(1000);
//    //
//    ThingSpeak.setField(1, text);
//    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
//    delay(3000);
  writeThings();
    //
    tng = ThingSpeak.readLongField(myChannelNumber, FieldNumber1, myReadAPIKey);
    tmb = ThingSpeak.readLongField(myChannelNumber, FieldNumber2, myReadAPIKey);
    otomatis = ThingSpeak.readLongField(myChannelNumber, FieldNumber3, myReadAPIKey);
    statusCode = ThingSpeak.getLastReadStatus();
    if (statusCode == 200){
      if(otomatis==1){
        Serial.println("Otomatis Nyala");
        otomatisasi(tng);
        delay(3000);
      }else{
        Serial.println("Manual Nyala");
        Serial.println(tmb);
        if(tmb>0){
          if(tmb!= nlTmb){
            int batas = tng + tmb;
            Serial.println(batas);
            while(tng!=batas){
              pinMode(relay, INPUT);
              digitalWrite(relay, LOW);
              Serial.println("Relay Nyala");
              writeThings();
              delay(2000);
              tng = ThingSpeak.readLongField(myChannelNumber, FieldNumber1, myReadAPIKey);
            } 
            pinMode(relay, OUTPUT);
              digitalWrite(relay, HIGH);
              nlTmb = tmb;  
            }
        }
      }
    }else{
      Serial.println("Unable to read channel / No internet connection");
    }  
  delay(5000);
  }else{
    Serial.println("radio tidak ditemukan");
  }
}

void writeThings(){
  char text[5] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    delay(1000);
    //
    ThingSpeak.setField(1, text);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    delay(3000);
}

void otomatisasi(int nil){
//  Serial.println("otomatis nyala");
  if(nil >= 21){ // disesuaikan sama tinggi
    //Relay Mati
    pinMode(relay, OUTPUT);
    digitalWrite(relay, HIGH);
    Serial.println("Relay mati");
  }else{
    pinMode(relay, INPUT);
    digitalWrite(relay, LOW);
    Serial.println("Relay nyala");
  }
  if(nil >= 18 && nil <= 20){ //disesuaikan sama tinggi
    digitalWrite(buzzer, HIGH);
    Serial.println("Buzzer Nyala"); 
  }else{
    digitalWrite(buzzer, LOW); 
  }
}
