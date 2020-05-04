#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int pos=0;

void setup() {
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(6);
  servo4.attach(5);
}

void loop() {
  if(pos==0){
    servo1.write(0);
    delay(10);
    servo1.write(180);
    delay(1000);
  }
}
