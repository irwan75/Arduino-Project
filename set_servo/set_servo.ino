#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(9);
  servo2.attach(12);
  servo3.attach(7);
  servo4.attach(5);
}

void loop() {
  servo1.write(0);
  servo2.write(0);
}
