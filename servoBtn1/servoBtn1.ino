#include <Servo.h>

int button = 13;
int led = 12;
int btnState = 1;
int servoState = 180;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(8);
  servo4.attach(9);
}

void loop() {
  btnState = digitalRead(button);
  Serial.write(btnState);
  if(btnState==HIGH){
    digitalWrite(led, HIGH);
    servo1.write(servoState);
    delay(10);
    Serial.write(servo1.read());
    if(servoState==180){
      servo1.write(0);
      delay(10);
      servoState = 0;
      Serial.write(servo1.read());
      servo2.write(180);
      delay(10);
      //servoState = servo2.read();
      if(servo2.read()==180){
        servo2.write(0);
        delay(10);
        //servoState=0;
        servo3.write(180);
        delay(10);
        //servoState = servo3.read();
          if(servo3.read()==180){
            servo3.write(0);
            delay(10);
            //servoState=0;
            servo4.write(180);
            delay(10);
          }
      }
    }
  }else{
    digitalWrite(led, LOW);
    servo1.write(0);
//    delay(10);
    servo2.write(0);
//    delay(10);
    servo3.write(0);
//    delay(10);
    servo4.write(0);
//    delay(10);
  }
}
