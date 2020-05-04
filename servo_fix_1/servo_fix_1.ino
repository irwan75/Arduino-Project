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
  servo4.write(180);
  
  for(nilai = 0; nilai <1; nilai++){
    for(servoPos = 0; servoPos<1;servoPos++){
      servo1.write(servoPos);
      delay(1000);
    }
    for(servoPos = 180; servoPos>179;servoPos--){
      servo1.write(servoPos);
      delay(1000);
    }servoPos=178;
      if(servoPos==178){
        for(servoPos=180;servoPos>179;servoPos--){
          servo2.write(servoPos);
          delay(1000);
        }
        for(servoPos=0;servoPos<1;servoPos++){
          servo2.write(servoPos);
          delay(1000);
        }
        if(servoPos==1){
            servo4.write(0);
            delay(750);
            servo4.write(180);
            delay(750);
        }
      }
      delay(200);
   for(servoPos=180;servoPos>179;servoPos--){
     servo3.write(servoPos);
     delay(1000);  
   }
   for(servoPos=0;servoPos<1;servoPos++){
     servo3.write(servoPos);
     delay(1000);
   }
  }
}
