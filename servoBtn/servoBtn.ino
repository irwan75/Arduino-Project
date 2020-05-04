#include <Servo.h>

int button = 7;
int btnState = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void setup() {
  pinMode(button, INPUT);
//  pinMode(led, OUTPUT);

  servo1.attach(2);
  servo1.write(180);
  servo2.attach(3);
  servo2.write(0);
  servo3.attach(4);
  servo3.write(180);
  servo4.attach(5);
  servo4.write(0);
}

void loop() {
  btnState = digitalRead(button);
  if(btnState==LOW){
    servo1.write(0);
    delay(1000);
    servo1.write(180);
    delay(1000);
    servo2.write(180);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(0);
    delay(1000);
    servo3.write(180);
    delay(1000);
    servo4.write(180);
    delay(1000);
    servo4.write(0);
    delay(1000);
  }else{
//    servo1.write(0);
//    delay(1000);
  }
}
