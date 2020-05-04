/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

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

const char* ssid     = STASSID;
const char* password = STAPSK;
WiFiClient clientt;

int trigPin1=13;
int echoPin1=12;

long statusCode;

long tmb;
long otomatis;
long nlTmb;

int relay = 14;
int buzzer= 5;

void setup() {
  Serial.begin(9600);

  // We start by connecting to a WiFi network

  Serial.print("Connecting to ");
  Serial.println(ssid);

  pinMode(buzzer, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
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

  writefield();
  
  readField2();
  
  // Close the connection
  Serial.println();
  Serial.println("closing connection");

  delay(4000); // execute once every 5 minutes, don't flood remote service
}

void writefield(){
  ThingSpeak.setField(1, ultrasonik());
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);
}

void readField2(){
  tmb = ThingSpeak.readLongField(myChannelNumber, FieldNumber2, myReadAPIKey);
  otomatis = ThingSpeak.readLongField(myChannelNumber, FieldNumber3, myReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200){
    if(otomatis==1){
      Serial.println("Otomatis Nyala");
      otomatisasi();
    }else{
      Serial.println("Manual");
      Serial.println(tmb);
      Serial.println(ultrasonik());
      if(tmb>0){
        if(tmb!= nlTmb){
            int batas = ultrasonik() + tmb;
            Serial.println(batas);
            while(ultrasonik()!=batas){
              pinMode(relay, INPUT);
              digitalWrite(relay, LOW); 
              Serial.println("Relay Nyala");
              delay(500);
            }pinMode(relay, OUTPUT);
            digitalWrite(relay, HIGH);
          nlTmb = tmb;  
        }
      }
    }
  }else{
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(5000);
}

void otomatisasi(){
//  Serial.println("otomatis nyala");
  Serial.println(ultrasonik());
  if(ultrasonik() >= 16){ // disesuaikan sama tinggi
    //Relay Mati
    pinMode(relay, OUTPUT);
    digitalWrite(relay, HIGH);
    Serial.println("Relay mati");
  }else{
    pinMode(relay, INPUT);
    digitalWrite(relay, LOW);
    Serial.println("Relay nyala");
  }
  if(ultrasonik() >= 15 && ultrasonik() <= 18){ //disesuaikan sama tinggi
    digitalWrite(buzzer, HIGH);
    Serial.println("Buzzer Nyala"); 
  }else{
    digitalWrite(buzzer, LOW); 
  }
}

int ultrasonik(){
  int duration, distance, tinggi;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn (echoPin1, HIGH);
  distance = (duration/2) / 29.2;
  delay(100);
  tinggi = 22 - distance; // tinggi diganti

  return tinggi;
  delay(500);
}

