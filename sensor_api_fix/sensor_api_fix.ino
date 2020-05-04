#include <Servo.h>

Servo servo1;

int api;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (2, OUTPUT);
  servo1.attach(25);
}
void loop() {
  // put your main code here, to run repeatedly:
servo1.write(90);
digitalWrite(2, LOW);
delay(5000);
//  for(int i=0; i<=180;i++){
//    api = analogRead(A0);
//    servo1.write(i);
//    delay(30);
//    if(api<=150){
//      Serial.println("api terdeteksi");
//    }
//  }
//  for(int i=180;i>=0;i--){
//    api = analogRead(A0);
//    servo1.write(i);
//    delay(30);
//    if(api<=150){
//      Serial.println("api terdeteksi");
//    }
//  }
}
