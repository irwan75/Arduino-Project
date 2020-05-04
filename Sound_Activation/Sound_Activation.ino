#include <Servo.h>
int soundSensor = 35;
int led = 53;

int statusSensor, stSensor;

//Servo
Servo servo1, servo2, servo3, servo4, servo5, servo6, servo7, servo8, servo9, servo10;
Servo servo11, servo12, servo13, servo14, servo15, servo16, servo17, servo18;


int srv1 = 2; //gagal
int srv2 = 4; //40 -> 90 turun
int srv3 = 3; //100 -> 180 kanan
int srv4 = 5; //50 -> 40 turun
int srv5 = 6; //100 -> 50 naik
int srv6 = 7; //100 -> 60 kiri //gagal
int srv7 = 8; //100 -> 10 turun
int srv8 = 10; //70 -> 90 bawah
int srv9 = 9; //80 -> 70 kanan
int srv10 = 11; //50 -> 100 bawah 
int srv11 = 12; //50 -> 100 naik
int srv12 = 34; //gagal
int srv13 = 22; //50 -> 90 turun
int srv14 = 24; //40 -> 70 naik
int srv15 = 26; //50 -> 100 kiri
int srv16 = 28; //50 -> 100 turun
int srv17 = 30; //50 -> 80 naik
int srv18 = 32; //50 -> 80 kanan

void default_leg(){
  
//  servo1.write();
  servo2.write(40);
  servo3.write(150);

  servo4.write(25);
  servo5.write(50);
//  servo6.write(30);

  servo7.write(20);
  servo8.write(40);
  servo9.write(55);

  servo10.write(120);
  servo11.write(120);
//  servo12.write(

//  servo13.write(
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  servo2.attach(srv2);
  delay(10);
  servo3.attach(srv3);
  delay(10);
  servo4.attach(srv4);
  delay(10);
  servo5.attach(srv5);
  delay(10);
  servo7.attach(srv7);
  delay(10);
  servo8.attach(srv8);
  delay(10);
  servo9.attach(srv9);
  delay(10);
  servo10.attach(srv10);
  delay(10);
  servo11.attach(srv11);
  delay(10);
  
//  servo1.attach(srv13);
//  servo1.write(50);
}

void loop() {
  statusSensor = digitalRead(soundSensor);
  if(statusSensor==1){
    stSensor = digitalRead(stSensor);
    if(stSensor==1){
      while(true){
        digitalWrite(led, HIGH);
        delay(5000);
        default_leg();
      }
    }
  }
  
}
