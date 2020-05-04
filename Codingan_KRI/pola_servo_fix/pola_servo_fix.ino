#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

Servo servoLeg1_1;
Servo servoLeg1_2;
Servo servoLeg1_3;
Servo servoLeg2_1;
Servo servoLeg2_2;
Servo servoLeg2_3;
Servo servoLeg3_1;
Servo servoLeg3_2;
Servo servoLeg3_3;
Servo servoLeg4_1;
Servo servoLeg4_2;
Servo servoLeg4_3;
Servo servoLeg5_1;
Servo servoLeg5_2;
Servo servoLeg5_3;
Servo servoLeg6_1;
Servo servoLeg6_2;
Servo servoLeg6_3;

void salam(){
  //Leg 1
  for(int i=0;i<=6;i++){
    servoLeg1_1.write(100);
    delay(100);
    servoLeg1_2.write(30);
    delay(100);
    servoLeg1_3.write(0);
    delay(500);  
    servoLeg1_3.write(50);    
  }
}

void duduk(){
  //Leg 1
  pwm.setPWM(0, 0, 100);
  pwm.setPWM(1, 0, 170);
  pwm.setPWM(2, 0, 180);
  //Leg 2
  pwm.setPWM(3, 0, 133);
  pwm.setPWM(4, 0, 170);
  pwm.setPWM(5, 0, 225);
  //Leg 3
  pwm.setPWM(6, 0, 140);
  pwm.setPWM(7, 0, 190);
  pwm.setPWM(8, 0, 210);
  //Leg 4
  pwm.setPWM(9, 0, 240);
  pwm.setPWM(10, 0, 340);
  pwm.setPWM(11, 0, 155);
  //Leg 5
//  servo1.write(150);
  pwm.setPWM(12, 0, 345);
  pwm.setPWM(14, 0, 220);
  //Leg 6
//  servo2.write(120);
  pwm.setPWM(13, 0, 295);
  pwm.setPWM(15, 0, 225);
  delay(40);  
}

void berdiri(){
  //Leg 1
    pwm.setPWM(1, 0, 220);
    pwm.setPWM(4, 0, 220);
    pwm.setPWM(7, 0, 240);
    pwm.setPWM(10, 0, 290);
    pwm.setPWM(12, 0, 295);
    pwm.setPWM(13, 0, 255);
    delay(100);
  pwm.setPWM(0, 0, 150);
  //Leg 2
  pwm.setPWM(3, 0, 183);
  //Leg 3
  pwm.setPWM(6, 0, 190);
  //Leg 4
  pwm.setPWM(9, 0, 190);
  //Leg 5
//  servo1.write(125);
  //Leg 6
//  servo2.write(110);
  delay(40);  
}

void setup() {
  Serial.begin(9600);

  servoLeg1_1.attach(22);
  servoLeg1_2.attach(24);
  servoLeg1_3.attach(26);
  servoLeg2_1.attach(3);
  servoLeg2_2.attach(2);
  servoLeg2_3.attach(3);
  servoLeg3_1.attach(2);
  servoLeg3_2.attach(3);
  servoLeg3_3.attach(2);
  servoLeg4_1.attach(3);
  servoLeg4_2.attach(3);
  servoLeg4_3.attach(3);
  servoLeg5_1.attach(3);
  servoLeg5_2.attach(3);
  servoLeg5_3.attach(3);
  servoLeg6_1.attach(3);
  servoLeg6_2.attach(3);
  servoLeg6_3.attach(3);

//  duduk();
//  delay(500);
//  berdiri();
salam();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
