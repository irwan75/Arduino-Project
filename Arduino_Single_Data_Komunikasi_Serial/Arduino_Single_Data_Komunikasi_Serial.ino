#include <SoftwareSerial.h>
SoftwareSerial ss(7, 8); //RX - TX

int trigPin1=13;
int echoPin1=12;

void setup() {
  // put your setup code here, to run once:
  ss.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = 50;
  Serial.println(ultrasonik());
  if(ss.available()>0){
    Serial.println("Connect Ard");
//    char c = ss.read();
//    if(c=='s'){
      ss.write(ultrasonik());
//      Serial.println(c);
//    }
  }
  delay(1000);
}

int ultrasonik(){
  int duration, distance, tinggi;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn (echoPin1, HIGH);
  distance = (duration/2) / 29.2;
  tinggi = 22 - distance; // tinggi diganti

//  return tinggi;
  return distance;
  delay(500);
}
