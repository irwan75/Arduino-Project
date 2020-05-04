#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

int servoPos = 0;
int nilai =0;

void setup() {
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  servo4.attach(6);

  Serial.begin(9600);
}

void loop() {

  servo1.write(servoPos);
  servo2.write(servoPos);
  servo3.write(servoPos);
  servo4.write(servoPos);
  
  for(nilai = 0; nilai <1; nilai++){
    for(servoPos = 0; servoPos<1;servoPos++){
      servo1.write(servoPos);
      delay(1000);
    }
    for(servoPos = 180; servoPos>179;servoPos--){
      servo1.write(servoPos);
      delay(1000);
    }
    if(servoPos==179){
      for(servoPos=0;servoPos<1;servoPos++){
        servo2.write(servoPos);
        delay(1000);
      }
      for(servoPos=180;servoPos>179;servoPos--){
        servo2.write(servoPos);
        delay(1000);
      }
    }
    if(servoPos==179){
      for(servoPos=0;servoPos<1;servoPos++){
        servo3.write(servoPos);
        delay(1000);
      }
      for(servoPos=180;servoPos>179;servoPos--){
        servo3.write(servoPos);
        delay(1000);
      }
    }
    if(servoPos==179){
      for(servoPos=0;servoPos<1;servoPos++){
        servo4.write(servoPos);
        delay(1000);
      }
      for(servoPos=180;servoPos>179;servoPos--){
        servo4.write(servoPos);
        delay(1000);
      }
    }
  }
}
