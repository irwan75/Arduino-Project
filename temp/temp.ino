#include "dht.h"
#define dht_apin A0

DHT dht;

void setup(){
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT 11");
  delay(1000);
}

void loop(){
  dht.read11(dht_apin);

  Serial.print(dht.humidity);
  Serial.print(dht.temperature);
  delay(5000);
}

