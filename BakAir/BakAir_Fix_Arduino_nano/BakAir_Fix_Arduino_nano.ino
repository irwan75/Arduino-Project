#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

int trigPin1=5;
int echoPin1=4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char text[5];
  sprintf(text, "%i", ultrasonik()); 
  radio.write(&text, sizeof(text));
  Serial.println(text);
  delay(6000);
}

int ultrasonik(){
  int duration, distance, tinggi;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn (echoPin1, HIGH);
  distance = (duration/2) / 29.2;
  delay(100);
  tinggi = 27 - distance; // tinggi diganti

  return tinggi;
  delay(500);
}
