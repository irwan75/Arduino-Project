#include <Servo.h>
Servo servo;
int pos = 180;

void setup() {
  servo.attach(9);
}

void loop() {
    servo.write(pos);
}
