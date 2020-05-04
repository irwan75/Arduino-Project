#include <Servo.h>

Servo servo1;
Servo servo2;

int val;
int val1;

void setup() {
  servo1.attach(3);
  servo2.attach(4);
  
//servo1.write(90);
//delay(1000);
//servo2.write(90);
//delay(1000);
}

void loop() {
  val = analogRead(0);
  val = map(val, 0, 1023, 0, 180);
  servo1.write(val);
  delay(5);

  val1 = analogRead(1);
  val1 = map(val1, 0, 1023, 0, 180);
  servo2.write(val1);
  delay(5);
}
