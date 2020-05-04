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
    delay(500);    
  }
}

void duduk(){
  servoLeg1_1.write(0);
//  delay(500);
  servoLeg1_2.write(30);
//  delay(500);  
  servoLeg1_3.write(25);
//  delay(500);
  servoLeg2_1.write(10);
//  delay(500);
  servoLeg2_2.write(25);
//  delay(500);
  servoLeg2_3.write(36);
//  delay(500);
  servoLeg3_1.write(7);
//  delay(500);
  servoLeg3_2.write(26);
//  delay(500);  
  servoLeg3_3.write(20);
//  delay(500);
  servoLeg4_1.write(45);
//  delay(500);
  servoLeg4_2.write(85);
//  delay(500);
  servoLeg4_3.write(5);
//  delay(500);
  servoLeg5_1.write(145);
//  delay(500);
  servoLeg5_2.write(90);
//  delay(500);
  servoLeg5_3.write(30);
//  delay(500);
  servoLeg6_1.write(125);
//  delay(500);
  servoLeg6_2.write(70);
//  delay(500);
  servoLeg6_3.write(47);
//  delay(500);
}

void berdiri(){

}

void maju(){
  //belakang
  servoLeg1_3.write(
  servoLeg2_3.write(
  servoLeg3_3.write(
  servoLeg4_3.write(
  servoLeg5_3.write(
  servoLeg6_3.write(
  //depan
  servoLeg1_3.write(
  servoLeg2_3.write(
  servoLeg3_3.write(
  servoLeg4_3.write(
  servoLeg5_3.write(
  servoLeg6_3.write(
  //naik
  for(int i=0
  //turun
  for(int i=
}

void kanan(){
  
}

void kiri(){
  
}

void setup() {
  Serial.begin(9600);

  servoLeg1_1.attach(22);
  servoLeg1_2.attach(24);
  servoLeg1_3.attach(26);
  servoLeg2_1.attach(23);
  servoLeg2_2.attach(25);
  servoLeg2_3.attach(27);
  servoLeg3_1.attach(28);
  servoLeg3_2.attach(30);
  servoLeg3_3.attach(32);
  servoLeg4_1.attach(36);
  servoLeg4_2.attach(38);
  servoLeg4_3.attach(40);
  servoLeg5_1.attach(41);
  servoLeg5_2.attach(43);
  servoLeg5_3.attach(45);
  servoLeg6_1.attach(46);
  servoLeg6_2.attach(48);
  servoLeg6_3.attach(50);

  duduk();
//  delay(500);
//  berdiri();
//salam();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
