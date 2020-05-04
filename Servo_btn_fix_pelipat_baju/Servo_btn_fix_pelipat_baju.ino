#include <Servo.h>

int button = 7;
int led = 12;
int btnState = 0;

Servo servo1;
//Servo servo2;
//Servo servo3;
//Servo servo4;


void setup() {
  pinMode(button, INPUT);
//  pinMode(led, OUTPUT);

  servo1.attach(5);
//  servo2.attach(6);
//  servo3.attach(8);
//  servo4.attach(9);
}

void loop() {
  btnState = digitalRead(button);
  if(btnState==LOW){
    servo1.write(90);
    delay(2000);
  }else{
    servo1.write(0);
    delay(1000);
  }
}
