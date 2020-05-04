#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define JoyX A0
#define JoyY A1

int ServoXforward;
int ServoXbackward;
int ServoYforward;
int ServoYbackward;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  int valX = analogRead(JoyX);
  int valY = analogRead(JoyY);
//  Serial.print("val x : ");
//  Serial.println(val1X);
//  Serial.print("val y : ");
//  Serial.println(val1Y);
//  delay(2000);

  valX = map(valX, 0, 1023, 10, 170);
  
//  Serial.println(ServoXforward);
//  delay(1000);
  pwm.setPWM(4, 0, valX);
//  pwm.setPWM(8, 0, ServoYforward);
  delay(5);

}
