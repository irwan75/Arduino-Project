#include <Servo.h>

Servo servo1;
int potpin1=4;
int val1;



void setup() {
  servo1.attach(4);
}

void loop() {
  //val1 = analogRead(potpin1);
  //val1 = map(val1, 0, 1023, 0, 180);
  servo1.write(50);
  delay(500);
}
