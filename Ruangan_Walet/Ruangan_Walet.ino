#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#ifndef STASSID
#define STASSID "OPPO A3s"
#define STAPSK  "surachmo"
#endif

unsigned long myChannelNumber = 915630;
const char * myWriteAPIKey = "NQDP12070ETN2DII";
const char * myReadAPIKey = "0PCSEY5YQYFMYHBY";

const char* ssid     = STASSID;
const char* password = STAPSK;
WiFiClient clientt;

int relay = 5;
int ldr = 6;
int serv = 21;
int led = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(115200);

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
//  eldr();
  leds();
}

void leds(){
  digitalWrite(led, HIGH);
}

void eldr(){
  int lldr = analogRead(ldr);
  Serial.println(lldr);
  delay(1000);
}

void kipas(){
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
}

void writefield(int nil1, int nil2, int nil3, int nil4){
  ThingSpeak.setField(1, nil1);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);
  ThingSpeak.setField(2, nil2);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);
  ThingSpeak.setField(3, nil3);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);
  ThingSpeak.setField(4, nil4);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);
}
