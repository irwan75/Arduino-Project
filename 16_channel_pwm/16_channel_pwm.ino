#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void kaki1(int i)
  {  
  pwm.setPWM(0, 0, i);
  pwm.setPWM(1, 0, i);
  pwm.setPWM(2, 0, i);
  delay(2000);
  pwm.setPWM(0, 0, i);
  pwm.setPWM(1, 0, i);
  pwm.setPWM(2, 0, i);
  delay(2000);
  }

  void kaki2(int i)
  {  
  pwm.setPWM(3, 0, i);
  pwm.setPWM(4, 0, i);
  pwm.setPWM(5, 0, i);
  delay(2000);
  pwm.setPWM(3, 0, i);
  pwm.setPWM(4, 0, i);
  pwm.setPWM(5, 0, i);
  delay(2000);
  }
  
  void kaki3(int i)
  {  
  pwm.setPWM(6, 0, i);
  pwm.setPWM(7, 0, i);
  delay(2000);
  pwm.setPWM(6, 0, i);
  pwm.setPWM(7, 0, i);
  delay(2000);
  }

  void kaki4(int i)
  {  
  pwm.setPWM(8, 0, i);
  pwm.setPWM(9, 0, i);
  pwm.setPWM(10, 0, i);
  delay(2000);
  pwm.setPWM(8, 0, i);
  pwm.setPWM(9, 0, i);
  pwm.setPWM(10, 0, i);
  delay(2000);
  }
  
  void kaki5(int i)
  {  
  pwm.setPWM(11, 0, i);
  pwm.setPWM(12, 0, i);
  pwm.setPWM(13, 0, i);
  delay(2000);
  pwm.setPWM(11, 0, i);
  pwm.setPWM(12, 0, i);
  pwm.setPWM(13, 0, i);
  delay(2000);
  }

  void kaki6(int i)
  {  
  pwm.setPWM(14, 0, i);
  pwm.setPWM(15, 0, i);
  delay(2000);
  pwm.setPWM(14, 0, i);
  pwm.setPWM(15, 0, i);
  delay(2000);
  }
void setup(){
  pwm.begin();
  pwm.setPWMFreq(60);
  
}

void loop(){
  
  kaki1(50);
  delay (500);
  kaki2(70);
  delay (500);
   kaki3(60);
   delay (500);
   kaki4(90);
   delay (500);
   kaki5(100);
   delay (500);
   kaki6(120);
  delay (500);
  kaki1(80);
  delay (500);
   kaki2(46);
   delay (500);
   kaki3(78);
   delay (500);
   kaki4(32);
   delay (500);
   kaki5(69);
   delay (500);
   kaki6(30);
   delay (500);
}
